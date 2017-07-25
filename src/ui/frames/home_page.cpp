// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/home_page.h"

namespace bcloud {

HomePage::HomePage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("HomePage");
}

QString HomePage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString HomePage::getLocalName() const {
  return tr("Home");
}

QString HomePage::getName() const {
  return "Home";
}

QString HomePage::getTooltip() const {
  return tr("Home");
}

}  // namespace bcloud