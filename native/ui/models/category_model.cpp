// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/models/category_model.h"

#include <QIcon>

namespace bcloud {

CategoryModel::CategoryModel(QObject* parent) : QAbstractListModel(parent) {
  this->setObjectName("CategoryModel");
}

QVariant CategoryModel::data(const QModelIndex& index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }
  CategoryPage* page = pages_.at(index.row());
  Q_ASSERT(page != nullptr);

  switch (role) {
    case Qt::DisplayRole: {
      return page->getLocalName();
    }
    case Qt::ToolTipRole: {
      return page->getTooltip();
    }
    case Qt::DecorationRole: {
      return QIcon(page->getIconName());
    }
    default: {
      break;
    }
  }
  return QVariant();
}

int CategoryModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return pages_.size();
}

void CategoryModel::addPage(CategoryPage* page) {
  this->beginResetModel();
  pages_.append(page);
  this->endResetModel();
}

}  // namespace bcloud