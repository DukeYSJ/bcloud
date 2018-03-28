// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "main_window.h"

#include <QDebug>
#include <QVBoxLayout>

namespace bcloud {

MainWindow::MainWindow(QWidget* parent) : QFrame(parent) {
  this->setObjectName("MainWindow");

  this->initUI();
  this->initConnections();
}

void MainWindow::initConnections() {
  connect(category_list_, &QListView::pressed,
          this, &MainWindow::onCategoryListChanged);
}

void MainWindow::initUI() {
  QFrame* title_bar = new QFrame(this);

  category_list_ = new QListView(this);
  category_model_ = new CategoryModel(this);
  category_list_->setModel(category_model_);

  user_avatar_ = new UserAvatar(this);
  QVBoxLayout* left_layout = new QVBoxLayout();
  left_layout->addWidget(category_list_);
  left_layout->addWidget(user_avatar_);

  bt_page_ = new BtPage(this);
  cloud_download_page_ = new CloudDownloadPage(this);
  documents_page_ = new DocumentsPage(this);
  download_page_ = new DownloadPage(this);
  home_page_ = new HomePage(this);
  music_page_ = new MusicPage(this);
  other_category_page_ = new OthersCategoryPage(this);
  pictures_page_ = new PicturesPage(this);
  settings_page_ = new SettingsPage(this);
  share_page_ = new SharePage(this);
  trash_page_ = new TrashPage(this);
  upload_page_ = new UploadPage(this);
  videos_page_ = new VideosPage(this);

  stacked_layout_ = new QStackedLayout();
  stacked_layout_->addWidget(home_page_);
  category_model_->addPage(home_page_);
  stacked_layout_->addWidget(videos_page_);
  category_model_->addPage(videos_page_);
  stacked_layout_->addWidget(music_page_);
  category_model_->addPage(music_page_);
  stacked_layout_->addWidget(pictures_page_);
  category_model_->addPage(pictures_page_);
  stacked_layout_->addWidget(documents_page_);
  category_model_->addPage(documents_page_);
  stacked_layout_->addWidget(bt_page_);
  category_model_->addPage(bt_page_);
  stacked_layout_->addWidget(other_category_page_);
  category_model_->addPage(other_category_page_);
  stacked_layout_->addWidget(share_page_);
  category_model_->addPage(share_page_);
  stacked_layout_->addWidget(trash_page_);
  category_model_->addPage(trash_page_);
  stacked_layout_->addWidget(cloud_download_page_);
  category_model_->addPage(cloud_download_page_);
  stacked_layout_->addWidget(download_page_);
  category_model_->addPage(download_page_);
  stacked_layout_->addWidget(upload_page_);
  category_model_->addPage(upload_page_);
  stacked_layout_->addWidget(settings_page_);

  QHBoxLayout* hbox_layout = new QHBoxLayout();
  hbox_layout->addLayout(left_layout);
  hbox_layout->addLayout(stacked_layout_);

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(title_bar);
  layout->addLayout(hbox_layout);

  this->setLayout(layout);
}

void MainWindow::onCategoryListChanged(const QModelIndex& index) {
  qDebug() << "change stacked layout: " << index.row();
  stacked_layout_->setCurrentIndex(index.row());
}

}  // namespace bcloud