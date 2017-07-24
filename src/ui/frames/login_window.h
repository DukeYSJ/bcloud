// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_LOGIN_WINDOW_H
#define BCLOUD_UI_FRAMES_LOGIN_WINDOW_H

#include <QCheckBox>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

namespace bcloud {

// Displays login form.
class LoginWindow : public QFrame {
  Q_OBJECT
 public:
  explicit LoginWindow(QWidget* parent = nullptr);

  // Get/set state of keep_password_box_.
  bool getKeepPassword() const;
  void setKeepPassword(bool keep);

  // Get/set state of auto_login_box_.
  bool getAutoLogin() const;
  void setAutoLogin(bool auto_login);

 signals:
  // This signal is emitted when |login_button_| is clocked.
  void requestLogin(const QString& username, const QString& password);

 private:
  void initConnections();
  void initUI();

  QLineEdit* username_edit_ = nullptr;
  QLineEdit* password_edit_ = nullptr;
  QCheckBox* keep_password_box_ = nullptr;
  QCheckBox* auto_login_box_ = nullptr;
  QPushButton* login_button_ = nullptr;

 private:
  void onLoginButtonClicked();
};

} // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_LOGIN_WINDOW_H
