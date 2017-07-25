// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef BCLOUD_UI_FRAMES_VERIFY_CODE_DIALOG_H
#define BCLOUD_UI_FRAMES_VERIFY_CODE_DIALOG_H

#include <QDialog>

namespace bcloud {

// Displays this dialog while creating new cloud download task.
class VerifyCodeDialog : public QDialog {
  Q_OBJECT
 public:
  explicit VerifyCodeDialog(QWidget* parent = nullptr);
};

}  // namespace bcloud

#endif  // BCLOUD_UI_FRAMES_VERIFY_CODE_DIALOG_H
