// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/others_category_page.h"

namespace bcloud {

OthersCategoryPage::OthersCategoryPage(QWidget* parent) : CategoryPage(parent) {
  this->setObjectName("OthersCategoryPage");
}

int OthersCategoryPage::getCategory() const {
  return 6;
}

QString OthersCategoryPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString OthersCategoryPage::getLocalName() const {
  return tr("Others");
}

QString OthersCategoryPage::getName() const {
  return "Others";
}

QString OthersCategoryPage::getTooltip() const {
  return "Others";
}

}  // namespace bcloud