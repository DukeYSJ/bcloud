// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_CONTROLLERS_WINDOW_CONTROLLER_H
#define BCLOUD_UI_CONTROLLERS_WINDOW_CONTROLLER_H

#include <QObject>

#include "services/pcs.h"
#include "services/user_profile.h"
#include "ui/frames/main_window.h"
#include "ui/frames/login_window.h"

namespace bcloud {

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
  MainWindow* main_window_ = nullptr;
  LoginWindow* login_window_ = nullptr;
  Pcs* pcs_ = nullptr;
  UserProfile* user_profiler_ = nullptr;

 private slots:
};

}  // namespace bcloud

#endif  // BCLOUD_UI_CONTROLLERS_WINDOW_CONTROLLER_H
