// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/bt_page.h"

namespace bcloud {

BtPage::BtPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("BtPage");
}

int BtPage::getCategory() const {
  return 7;
}

QString BtPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString BtPage::getLocalName() const {
  return tr("BT");
}

QString BtPage::getName() const {
  return "BT";
}

QString BtPage::getTooltip() const {
  return tr("BT seeds");
}

}  // namespace bcloud