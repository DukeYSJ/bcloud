// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_LOGIN_WINDOW_H
#define BCLOUD_UI_FRAMES_LOGIN_WINDOW_H

#include <QFrame>

namespace bcloud {

// Displays login form.
class LoginWindow : public QFrame {
  Q_OBJECT
 public:
  explicit LoginWindow(QWidget* parent = nullptr);
};

} // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_LOGIN_WINDOW_H
