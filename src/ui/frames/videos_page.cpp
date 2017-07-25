// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/videos_page.h"

namespace bcloud {

VideosPage::VideosPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("VideosPage");
}

int VideosPage::getCategory() const {
  return 1;
}

QString VideosPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString VideosPage::getLocalName() const {
  return tr("Videos");
}

QString VideosPage::getName() const {
  return "Videos";
}

QString VideosPage::getTooltip() const {
  return tr("Videos");
}

}  // namespace bcloud