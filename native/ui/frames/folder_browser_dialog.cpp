// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/folder_browser_dialog.h"

namespace bcloud {

FolderBrowserDialog::FolderBrowserDialog(QWidget* parent) : QDialog(parent) {
  this->setObjectName("FolderBrowserDialog");
}

}  // namespace bcloud