// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_HOME_PAGE_H
#define BCLOUD_UI_FRAMES_HOME_PAGE_H

#include <QFrame>

#include "ui/frames/category_page.h"

namespace bcloud {

// Display files on server side.
class HomePage : public QFrame,
                 public CategoryPage {
  Q_OBJECT
 public:
  explicit HomePage(QWidget* parent = nullptr);

  QString getIconName() const override;

  QString getLocalName() const override;

  QString getName() const override;

  QString getTooltip() const override;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_HOME_PAGE_H
