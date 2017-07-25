// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/frames/user_avatar.h"

#include <QVBoxLayout>

namespace bcloud {

UserAvatar::UserAvatar(QWidget* parent) : QFrame(parent) {
  this->setObjectName("UserAvatar");

  this->initUI();
}

void UserAvatar::setAvatar(const QString& avatar_path) {
  avatar_label_->setPixmap(QPixmap(avatar_path));
}

void UserAvatar::setQuota(qint64 used, qint64 total) {
  Q_UNUSED(used);
  Q_UNUSED(total);
}

void UserAvatar::setUsername(const QString& username) {
  username_label_->setText(username);
}

void UserAvatar::initUI() {
  avatar_label_ = new QLabel(this);
  username_label_ = new QLabel(this);
  quota_bar_ = new QProgressBar(this);

  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(avatar_label_);
  layout->addWidget(username_label_);
  layout->addWidget(quota_bar_);
  this->setLayout(layout);
}

}  // namespace bcloud