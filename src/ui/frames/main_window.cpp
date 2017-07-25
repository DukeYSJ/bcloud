// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "main_window.h"

#include <QVBoxLayout>

namespace bcloud {

MainWindow::MainWindow(QWidget* parent) : QFrame(parent) {
  this->setObjectName("MainWindow");

  this->initUI();
  this->initConnections();
}

void MainWindow::initConnections() {

}

void MainWindow::initUI() {
  QFrame* title_bar = new QFrame(this);

  category_list_ = new QListWidget(this);
  category_list_->addItem(tr("Home"));
  category_list_->addItem(tr("Pictures"));
  category_list_->addItem(tr("Videos"));
  category_list_->addItem(tr("BT"));
  category_list_->addItem(tr("Music"));
  category_list_->addItem(tr("Others"));
  category_list_->addItem(tr("Trash"));
  category_list_->addItem(tr("Share"));
  category_list_->addItem(tr("Cloud Download"));
  category_list_->addItem(tr("Download"));
  category_list_->addItem(tr("Upload"));

  user_avatar_ = new UserAvatar(this);
  QVBoxLayout* left_layout = new QVBoxLayout();
  left_layout->addWidget(category_list_);
  left_layout->addWidget(user_avatar_);

  stacked_layout_ = new QStackedLayout();

  QHBoxLayout* hbox_layout = new QHBoxLayout();
  hbox_layout->addLayout(left_layout);
  hbox_layout->addLayout(stacked_layout_);

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(title_bar);
  layout->addLayout(hbox_layout);

  this->setLayout(layout);
}


}  // namespace bcloud