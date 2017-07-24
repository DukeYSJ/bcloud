// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_CONTROLLERS_WINDOW_CONTROLLER_H
#define BCLOUD_UI_CONTROLLERS_WINDOW_CONTROLLER_H

#include <QObject>

namespace bcloud {

struct WindowControllerPrivate;

// Control application window and notifications.
class WindowController : public QObject {
  Q_OBJECT
 public:
  explicit WindowController(QObject* parent = nullptr);
  ~WindowController() override;

  // Show main window.
  // Create a new one if needed.
  // Also show LoginWindow if current user profile is empty.
  void showMainWindow();

 private:
  WindowControllerPrivate* p_ = nullptr;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_CONTROLLERS_WINDOW_CONTROLLER_H
