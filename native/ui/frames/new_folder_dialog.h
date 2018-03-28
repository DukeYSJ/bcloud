// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_NEW_FOLDER_DIALOG_H
#define BCLOUD_UI_FRAMES_NEW_FOLDER_DIALOG_H

#include <QDialog>

namespace bcloud {

class NewFolderDialog : public QDialog {
  Q_OBJECT
 public:
  explicit NewFolderDialog(QWidget* parent = nullptr);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_NEW_FOLDER_DIALOG_H
