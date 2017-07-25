// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/download_page.h"

namespace bcloud {

DownloadPage::DownloadPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("DownloadPage");
}

QString DownloadPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString DownloadPage::getLocalName() const {
  return tr("Download");
}

QString DownloadPage::getName() const {
  return "Download";
}

QString DownloadPage::getTooltip() const {
  return tr("Local downloading tasks");
}

}  // namespace bcloud