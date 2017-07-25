// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_USER_AVATAR_H
#define BCLOUD_UI_FRAMES_USER_AVATAR_H

#include <QFrame>
#include <QLabel>
#include <QProgressBar>

namespace bcloud {

// Displays user avatar, user name and disk space.
class UserAvatar : public QFrame {
  Q_OBJECT
 public:
  explicit UserAvatar(QWidget* parent = nullptr);

 public slots:
  // Update user avatar at |avatar_path|.
  void setAvatar(const QString& avatar_path);

  // Update cloud disk quota.
  void setQuota(qint64 used, qint64 total);

  // Update username.
  void setUsername(const QString& username);

 private:
  void initUI();

  QLabel* avatar_label_ = nullptr;
  QLabel* username_label_ = nullptr;
  QProgressBar* quota_bar_ = nullptr;
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_USER_AVATAR_H
