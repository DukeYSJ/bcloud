// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/login_window.h"

namespace bcloud {

LoginWindow::LoginWindow(QWidget* parent) : QFrame(parent) {
  this->setObjectName("LoginWindow");

  this->setWindowModality(Qt::ApplicationModal);
  this->setWindowTitle(tr("Login Now"));
}

}  // namespace bcloud