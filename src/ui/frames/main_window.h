// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_MAIN_WINDOW_H
#define BCLOUD_UI_FRAMES_MAIN_WINDOW_H

#include <QFrame>
#include <QListView>
#include <QStackedLayout>

#include "ui/frames/bt_page.h"
#include "ui/frames/cloud_download_page.h"
#include "ui/frames/documents_page.h"
#include "ui/frames/download_page.h"
#include "ui/frames/home_page.h"
#include "ui/frames/music_page.h"
#include "ui/frames/others_category_page.h"
#include "ui/frames/pictures_page.h"
#include "ui/frames/settings_page.h"
#include "ui/frames/share_page.h"
#include "ui/frames/trash_page.h"
#include "ui/frames/upload_page.h"
#include "ui/frames/user_avatar.h"
#include "ui/frames/videos_page.h"

#include "ui/models/category_model.h"

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

  QListView* category_list_ = nullptr;
  CategoryModel* category_model_ = nullptr;
  UserAvatar* user_avatar_ = nullptr;
  QStackedLayout* stacked_layout_ = nullptr;

  BtPage* bt_page_ = nullptr;
  CloudDownloadPage* cloud_download_page_ = nullptr;
  DocumentsPage* documents_page_ = nullptr;
  DownloadPage* download_page_ = nullptr;
  HomePage* home_page_ = nullptr;
  MusicPage* music_page_ = nullptr;
  OthersCategoryPage* other_category_page_ = nullptr;
  PicturesPage* pictures_page_ = nullptr;
  SettingsPage* settings_page_ = nullptr;
  SharePage* share_page_ = nullptr;
  TrashPage* trash_page_ = nullptr;
  UploadPage* upload_page_ = nullptr;
  VideosPage* videos_page_ = nullptr;

 private slots:
  void onCategoryListChanged(const QModelIndex &index);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_MAIN_WINDOW_H
