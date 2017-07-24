// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/controllers/window_controller.h"

#include "services/user_profile.h"
#include "ui/frames/login_window.h"
#include "ui/frames/main_window.h"

namespace bcloud {

struct WindowControllerPrivate {
  MainWindow* main_window = nullptr;
  LoginWindow* login_window = nullptr;

  UserProfile* user_profiler = nullptr;
};

WindowController::WindowController(QObject* parent)
    : QObject(parent),
      p_(new WindowControllerPrivate()) {
  this->setObjectName("WindowController");
}

WindowController::~WindowController() {
  if (p_->main_window != nullptr) {
    delete p_->main_window;
    p_->main_window = nullptr;
  }

  if (p_->login_window != nullptr) {
    delete p_->login_window;
    p_->login_window = nullptr;
  }

  if (p_->user_profiler != nullptr) {
    delete p_->user_profiler;
    p_->user_profiler = nullptr;
  }

  delete p_;
  p_ = nullptr;
}

void WindowController::showMainWindow() {
  if (p_->main_window == nullptr) {
    p_->main_window = new MainWindow();
  }
  p_->main_window->show();

  if (p_->user_profiler == nullptr ||
      !p_->user_profiler->isValid()) {
    p_->login_window = new LoginWindow();
    p_->login_window->show();
  }
}

}  // namespace bcloud