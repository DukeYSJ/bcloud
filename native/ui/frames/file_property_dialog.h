// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_FILE_PROPERTY_DIALOG_H
#define BCLOUD_UI_FRAMES_FILE_PROPERTY_DIALOG_H

#include <QDialog>

namespace bcloud {

// Displays selected file properties.
class FilePropertyDialog : public QDialog {
  Q_OBJECT
 public:
  explicit FilePropertyDialog(QWidget* parent = nullptr);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_FILE_PROPERTY_DIALOG_H
