// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_BT_PAGE_H
#define BCLOUD_UI_FRAMES_BT_PAGE_H

#include "ui/frames/category_page.h"

namespace bcloud {

// Displays bt torrent files.
class BtPage : public CategoryPage {
  Q_OBJECT
 public:
  explicit BtPage(QWidget* parent = nullptr);

 protected:
  int getCategory() const override;

  QString getIconName() const override;

  QString getLocalName() const override;

  QString getName() const override;

  QString getTooltip() const override;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_BT_PAGE_H
