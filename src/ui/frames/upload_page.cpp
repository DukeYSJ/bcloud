// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/upload_page.h"

namespace bcloud {

UploadPage::UploadPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("UploadPage");
}

QString UploadPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString UploadPage::getLocalName() const {
  return tr("Upload");
}

QString UploadPage::getName() const {
  return "Upload";
}

QString UploadPage::getTooltip() const {
  return tr("Uploading tasks");
}

}  // namespace bcloud