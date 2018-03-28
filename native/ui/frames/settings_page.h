// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_SETTINGS_PAGE_H
#define BCLOUD_UI_FRAMES_SETTINGS_PAGE_H

#include <QFrame>

namespace bcloud {

// Preferences setup page.
class SettingsPage : public QFrame {
  Q_OBJECT
 public:
  explicit SettingsPage(QWidget* parent = nullptr);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_SETTINGS_PAGE_H
