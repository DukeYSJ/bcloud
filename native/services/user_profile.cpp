// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "services/user_profile.h"

namespace bcloud {

UserProfile::UserProfile(QObject* parent) : QObject(parent) {
  this->setObjectName("UserProfile");
}

}  // namespace bcloud