// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_MAIN_WINDOW_H
#define BCLOUD_UI_FRAMES_MAIN_WINDOW_H

#include <QFrame>
#include <QListWidget>
#include <QStackedLayout>

#include "ui/frames/user_avatar.h"

namespace bcloud {

// Main window of application.
// Almost all of ui widgets are displayed in this container.
class MainWindow : public QFrame {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);

 private:
  void initConnections();
  void initUI();

  QListWidget* category_list_ = nullptr;
  UserAvatar* user_avatar_ = nullptr;
  QStackedLayout* stacked_layout_ = nullptr;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_MAIN_WINDOW_H
