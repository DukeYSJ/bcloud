// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_SERVICES_USER_PROFILE_H
#define BCLOUD_SERVICES_USER_PROFILE_H

#include <QObject>

namespace bcloud {

// Manage current user settings and other user information.
class UserProfile : public QObject {
  Q_OBJECT
 public:
  explicit UserProfile(QObject* parent = nullptr);
};

} // namespace bcloud

#endif  // BCLOUD_SERVICES_USER_PROFILE_H
