// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_DOCUMENTS_PAGE_H
#define BCLOUD_UI_FRAMES_DOCUMENTS_PAGE_H

#include <QFrame>

#include "ui/frames/filter_category_page.h"

namespace bcloud {

class DocumentsPage : public QFrame,
                      public FilterCategoryPage {
  Q_OBJECT
 public:
  explicit DocumentsPage(QWidget* parent = nullptr);

 protected:
  int getCategory() const override;

  QString getIconName() const override;

  QString getLocalName() const override;

  QString getName() const override;

  QString getTooltip() const override;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_DOCUMENTS_PAGE_H
