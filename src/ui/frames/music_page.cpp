// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/music_page.h"

namespace bcloud {

MusicPage::MusicPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("MusicPage");
}

int MusicPage::getCategory() const {
  return 2;
}

QString MusicPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString MusicPage::getLocalName() const {
  return tr("Music");
}

QString MusicPage::getName() const {
  return "Music";
}

QString MusicPage::getTooltip() const {
  return tr("Music");
}

}  // namespace bcloud