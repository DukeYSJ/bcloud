// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/share_page.h"

namespace bcloud {

SharePage::SharePage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("SharePage");
}

QString SharePage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString SharePage::getLocalName() const {
  return tr("Share");
}

QString SharePage::getName() const {
  return "Share";
}

QString SharePage::getTooltip() const {
  return tr("Shared files");
}

}  // namespace bcloud