// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_FILTER_CATEGORY_PAGE_H
#define BCLOUD_UI_FRAMES_FILTER_CATEGORY_PAGE_H

#include "ui/frames/category_page.h"

namespace bcloud {

class FilterCategoryPage : public CategoryPage {
 public:
  // Returns category id of current page.
  virtual int getCategory() const = 0;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_FILTER_CATEGORY_PAGE_H
