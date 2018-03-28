// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/trash_page.h"

namespace bcloud {

TrashPage::TrashPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("TrashPage");
}

QString TrashPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString TrashPage::getLocalName() const {
  return tr("Trash");
}

QString TrashPage::getName() const {
  return "Trash";
}

QString TrashPage::getTooltip() const {
  return tr("Trash");
}

}  // namespace bcloud