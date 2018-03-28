// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "base/string_util.h"

#include <QUrl>

namespace bcloud {

QByteArray EncodeUri(const QString& input) {
  return QUrl::toPercentEncoding(input, "~@#$&()*!+=:;,.?/'");
}

QByteArray EncodeUriComponent(const QString& input) {
  return QUrl::toPercentEncoding(input, "~()*!.'");
}

}  // namespace bcloud