// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_CATEGORY_PAGE_H
#define BCLOUD_UI_FRAMES_CATEGORY_PAGE_H

namespace bcloud {

// Abstract class to filter files by category.
class CategoryPage {
 public:
  // Returns category icon path.
  virtual QString getIconName() const = 0;

  // Get localized category name.
  virtual QString getLocalName() const = 0;

  // Get category name.
  virtual QString getName() const = 0;

  // Get category tooltip.
  virtual QString getTooltip() const = 0;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_CATEGORY_PAGE_H
