// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_BASE_STRING_UTIL_H
#define BCLOUD_BASE_STRING_UTIL_H

#include <QString>

namespace bcloud {

QByteArray EncodeUri(const QString& input);

QByteArray EncodeUriComponent(const QString& input);

}  // namespace bcloud

#endif  // BCLOUD_BASE_STRING_UTIL_H
