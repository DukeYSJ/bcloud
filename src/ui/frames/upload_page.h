// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_UPLOAD_PAGE_H
#define BCLOUD_UI_FRAMES_UPLOAD_PAGE_H

#include <QFrame>

namespace bcloud {

// Displays upload tasks.
class UploadPage : public QFrame {
  Q_OBJECT
 public:
  explicit UploadPage(QWidget* parent = nullptr);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_UPLOAD_PAGE_H
