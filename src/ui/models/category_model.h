// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_MODELS_CATEGORY_MODEL_H
#define BCLOUD_UI_MODELS_CATEGORY_MODEL_H

#include <QAbstractItemModel>
#include <QVector>

#include "ui/frames/category_page.h"

namespace bcloud {

class CategoryModel : public QAbstractListModel {
  Q_OBJECT
 public:
  explicit CategoryModel(QObject* parent = nullptr);

  QVariant data(const QModelIndex& index, int role) const override;

  int rowCount(const QModelIndex& parent) const override;

  void addPage(CategoryPage* page);

 private:
  QVector<CategoryPage*> pages_;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_MODELS_CATEGORY_MODEL_H
