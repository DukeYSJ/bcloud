// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/controllers/window_controller.h"

namespace bcloud {

WindowController::WindowController(QObject* parent)
    : QObject(parent),
      pcs_(new Pcs(this)) {
  this->setObjectName("WindowController");
}

WindowController::~WindowController() {
  if (main_window_ != nullptr) {
    delete main_window_;
    main_window_ = nullptr;
  }

  if (login_window_ != nullptr) {
    delete login_window_;
    login_window_ = nullptr;
  }

  if (user_profiler_ != nullptr) {
    delete user_profiler_;
    user_profiler_ = nullptr;
  }

}

void WindowController::showMainWindow() {
  if (main_window_ == nullptr) {
    main_window_ = new MainWindow();
  }
  main_window_->show();

  if (user_profiler_ == nullptr ||
      !user_profiler_->isValid()) {
    login_window_ = new LoginWindow();
    login_window_->show();
  }
}

}  // namespace bcloud