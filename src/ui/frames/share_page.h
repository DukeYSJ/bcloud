// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_SHARE_PAGE_H
#define BCLOUD_UI_FRAMES_SHARE_PAGE_H

#include <QFrame>

namespace bcloud {

// Displays shared files.
class SharePage : public QFrame {
  Q_OBJECT
 public:
  explicit SharePage(QWidget* parent = nullptr);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_SHARE_PAGE_H
