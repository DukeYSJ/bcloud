// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/documents_page.h"

namespace bcloud {

DocumentsPage::DocumentsPage(QWidget* parent) : QFrame(parent) {
  this->setObjectName("DocumentsPage");
}

int DocumentsPage::getCategory() const {
  return 4;
}

QString DocumentsPage::getIconName() const {
  // TODO(LiuLang):
  return "";
}

QString DocumentsPage::getLocalName() const {
  return tr("Documents");
}

QString DocumentsPage::getName() const {
  return "Documents";
}

QString DocumentsPage::getTooltip() const {
  return tr("Documents");
}

}  // namespace bcloud