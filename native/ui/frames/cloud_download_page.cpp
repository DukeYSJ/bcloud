// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/cloud_download_page.h"

namespace bcloud {

CloudDownloadPage::CloudDownloadPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("CloudDownloadPage");
}

QString CloudDownloadPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString CloudDownloadPage::getLocalName() const {
  return tr("Cloud Download");
}

QString CloudDownloadPage::getName() const {
  return "CloudDownload";
}

QString CloudDownloadPage::getTooltip() const {
  return tr("Cloud Downloading tasks");
}

}  // namespace bcloud