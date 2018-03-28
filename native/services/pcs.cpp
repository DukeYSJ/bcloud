// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "services/pcs.h"

#include <QDebug>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "base/json_util.h"
#include "base/string_util.h"

namespace bcloud {

namespace {

const char kPassportUrl[] = "https://passport.baidu.com/v2/api/";

QString GetTimestamp() {
  // TODO(LiuLang):
  return "0";
}

QString GetPpuiLoginTime() {
  // TODO(LiuLang):
  return "0";
}

}  // namespace

Pcs::Pcs(QObject* parent) :
    QObject(parent),
    network_manager_(new QNetworkAccessManager(this)) {
  this->setObjectName("Pcs");
}

Pcs::~Pcs() {

}

void Pcs::checkLoginState(const QString& username) {
  if (!cookie_inited_) {
    cookie_inited_ = true;
    username_ = username;

    // Get BaiduId.
    const QString url = QString("%1?getapi&tpl=mn&apiver=v3&tt=%2"
                                "&class=login&logintype=basicLogin")
        .arg(kPassportUrl).arg(0);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply* reply = network_manager_->get(request);
    connect(reply, &QNetworkReply::finished,
            this, &Pcs::onGetBaiduId);
    // TODO(LiuLang): Handle request errors.

  } else {
    const QString url = QString("%1?logincheck&token=%2&tpl=mm&apiver=v3"
                                "&tt=%3&username=%4&isphone=false")
        .arg(kPassportUrl).arg(token_).arg(0).arg(username);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply* reply = network_manager_->get(request);
    connect(reply, &QNetworkReply::finished,
            this, &Pcs::onCheckLogin);
  }
}

void Pcs::login(const QString& username, const QString& password) {
  this->login(username, password, "", "");
}

void Pcs::login(const QString& username,
                const QString& password,
                const QString& verify_code,
                const QString& code_string) {
  username_ = username;
  password_ = password;
  verify_code_ = verify_code;
  code_string_ = code_string;
  if (cookie_inited_) {

  } else {
    this->checkLoginState(username);
  }
}

void Pcs::printCookieJar() {
  QNetworkCookieJar* cookie_jar = network_manager_->cookieJar();
  QList<QNetworkCookie> cookies =
      cookie_jar->cookiesForUrl(QUrl(kPassportUrl));
  qDebug() << "cookie jar:" << cookies;
}

void Pcs::onGetBaiduId() {
  qDebug() << "onGetBaiduId()";
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(this->sender());
  // Cookies in http reply headers has been saved in cookie jar.
  reply->deleteLater();

  // Get token.
  const QString url = QString("%1?getapi&tpl=pp&apiver=v3&tt=%2"
                              "&class=login&logintype=basicLogin")
      .arg(kPassportUrl).arg(0);

  QNetworkRequest request;
  request.setUrl(QUrl(url));
  QNetworkReply* next_reply = network_manager_->get(request);
  connect(next_reply, &QNetworkReply::finished,
          this, &Pcs::onGetToken);
}

void Pcs::onGetToken() {
  qDebug() << "onGetToken()";
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(this->sender());
  const QByteArray body = reply->readAll();
  reply->deleteLater();

  qDebug() << "token body:" << body;
  const QVariant token = GetJsonItem(body, "data.token");
  if (token.isValid()) {
    token_ = token.toString();
    qDebug() << "token:" << token_;

    // Get UBI.
    const QString url = QString("%1?loginhistory&tpl=pp&apiver=v3&tt=%2"
                                "&token=%3")
        .arg(kPassportUrl).arg(0).arg(token_);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply* next_reply = network_manager_->get(request);
    connect(next_reply, &QNetworkReply::finished,
            this, &Pcs::onGetUbi);
  } else {
    qWarning() << "Failed to get token";
    emit this->onCheckLoginState(false);
  }
}

void Pcs::onGetUbi() {
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(this->sender());
  // Cookies are stored in cookie jar.
  reply->deleteLater();

  // Check login.
  this->checkLoginState(username_);
}

void Pcs::onCheckLogin() {
  qDebug() << "onCheckLogin()";
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(this->sender());
  const QByteArray body = reply->readAll();
  reply->deleteLater();
  qDebug() << "onCheckLogin():" << body;

  // Get public key.
  const QString url = QString("https://passport.baidu.com/v2/getpublickey"
                              "?token=%1&tpl=pp&apiver=v3&tt=%2")
      .arg(token_).arg(0);
  QNetworkRequest request;
  request.setUrl(QUrl(url));
  QNetworkReply* next_reply = network_manager_->get(request);
  connect(next_reply, &QNetworkReply::finished,
          this, &Pcs::onGetPublicKey);
}

void Pcs::onGetPublicKey() {
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(this->sender());
  const QByteArray body = reply->readAll();
  reply->deleteLater();
  qDebug() << "onGetPublicKey():" << body;

  this->postLogin();
}

void Pcs::postLogin() {
  QNetworkRequest request;
  request.setUrl(QUrl("https://passport.baidu.com/v2/api/?login"));
  QStringList items = {
      "staticpage=https%3A%2F%2Fpassport.baidu.com%2Fstatic%2Fpasspc-account%2Fhtml%2Fv3Jump.html",
      "&charset=UTF-8",
      "&token=", token_,
      "&tpl=pp&subpro=&apiver=v3",
      "&tt=", GetTimestamp(),
      "&codestring=", code_string_,
      "&safeflg=0&u=http%3A%2F%2Fpassport.baidu.com%2F",
      "&isPhone=",
      "&quick_user=0&logintype=basicLogin&logLoginType=pc_loginBasic&idc=",
      "&loginmerge=true",
      "&username=", EncodeUriComponent(username_),
      "&password=", EncodeUriComponent(password_),
      "&verifycode=", verify_code_,
      "&mem_pass=on",
      "&rsakey=", rsakey_,
      "&crypttype=12",
      "&ppui_logintime=", GetPpuiLoginTime(),
      "&callback=parent.bd__pcbs__28g1kg",

  };
  const QByteArray data =
      QString("staticpage=https://passport.baidu.com/static/passpc-"
                  "account/html/v3Jump.html&charset=UTF-8&token=%1&tpl=pp&subpro"
                  "&apiver=v3&tt=%2&codestring=%3&safeflg=0&u=https://p")
          .arg(token_).arg(0).arg(code_string_).toLocal8Bit();
  QNetworkReply* next_reply = network_manager_->post(request, data);
  connect(next_reply, &QNetworkReply::finished,
          this, &Pcs::onPostLogin);
}

void Pcs::onPostLogin() {
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(this->sender());
  const QByteArray body = reply->readAll();
  reply->deleteLater();
  qDebug() << "onPostLogin():" << body;
}

}  // namespace bcloud