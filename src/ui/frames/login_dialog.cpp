// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/login_dialog.h"

namespace bcloud {

LoginDialog::LoginDialog(QWidget* parent) : QDialog(parent) {
  this->setObjectName("LoginDialog");

  this->setWindowModality(Qt::ApplicationModal);
  this->setWindowTitle(tr("Login Now"));

  this->initUI();
  this->initConnections();
}

bool LoginDialog::getKeepPassword() const {
  return keep_password_box_->isChecked();
}

void LoginDialog::setKeepPassword(bool keep) {
  keep_password_box_->setChecked(keep);
}

bool LoginDialog::getAutoLogin() const {
  return auto_login_box_->isChecked();
}

void LoginDialog::setAutoLogin(bool auto_login) {
  auto_login_box_->setChecked(auto_login);
}

void LoginDialog::initConnections() {
  connect(login_button_, &QPushButton::clicked,
          this, &LoginDialog::onLoginButtonClicked);
}

void LoginDialog::initUI() {
  username_edit_ = new QLineEdit(this);
  username_edit_->setPlaceholderText(tr("Username/email/phone"));

  password_edit_ = new QLineEdit(this);
  password_edit_->setPlaceholderText(tr("Password"));
  password_edit_->setEchoMode(QLineEdit::Password);

  keep_password_box_ = new QCheckBox(this);
  keep_password_box_->setText(tr("Remember password"));

  auto_login_box_ = new QCheckBox(this);
  auto_login_box_->setText(tr("Login automatically"));

  login_button_ = new QPushButton(this);
  login_button_->setText(tr("Login"));

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(username_edit_);
  layout->addWidget(password_edit_);
  layout->addWidget(keep_password_box_);
  layout->addWidget(auto_login_box_);
  layout->addWidget(login_button_);

  this->setLayout(layout);
}

void LoginDialog::onLoginButtonClicked() {
  const QString username(username_edit_->text());
  if (username.isEmpty()) {
    return;
  }
  const QString password(password_edit_->text());
  if (password.isEmpty()) {
    return;
  }
  emit this->requestLogin(username, password);
}

}  // namespace bcloud