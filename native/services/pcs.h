// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_SERVICES_PCS_PASSPORT_H
#define BCLOUD_SERVICES_PCS_PASSPORT_H

#include <QObject>
#include <QNetworkAccessManager>

namespace bcloud {

// Http request API to access baidu cloud service.
// Cookies and states are managed at internal.
class Pcs : public QObject {
  Q_OBJECT
 public:
  explicit Pcs(QObject* parent = nullptr);
  ~Pcs();

 signals:
  // Emitted after |checkLoginState()| return.
  void onCheckLoginState(bool ok);

  void onLogin();

 public slots:
  // Check login state before singing into server.
  void checkLoginState(const QString& username);

  void login(const QString& username, const QString& password);
  void login(const QString& username,
             const QString& password,
             const QString& verify_code,
             const QString& code_string);

 private:
  void printCookieJar();
  void postLogin();

  QNetworkAccessManager* network_manager_ = nullptr;
  bool cookie_inited_ = false;
  QString username_;
  QString password_;
  QString verify_code_;
  QString code_string_;
  QString token_;
  QString rsakey_;

 private slots:
  void onGetBaiduId();
  void onGetToken();
  void onGetUbi();
  void onCheckLogin();
  void onGetPublicKey();
  void onPostLogin();
};

}  // namespace bcloud

#endif  // BCLOUD_SERVICES_PCS_PASSPORT_H
