// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/pictures_page.h"

namespace bcloud {

PicturesPage::PicturesPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("PicturesPage");
}

int PicturesPage::getCategory() const {
  return 3;
}

QString PicturesPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString PicturesPage::getLocalName() const {
  return tr("Pictures");
}

QString PicturesPage::getName() const {
  return "Pictures";
}

QString PicturesPage::getTooltip() const {
  return tr("Pictures");
}

}  // namespace bcloud