// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include <QApplication>
#include <QIcon>

#include "base/const.h"
#include "ui/controllers/window_controller.h"
#include "ui/images/images_rcc.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  app.setApplicationDisplayName(QObject::tr("BCloud"));
  app.setApplicationName("bcloud");
  app.setApplicationVersion(bcloud::kVersionName);
  app.setWindowIcon(QIcon(bcloud::rcc::kBcloud32));

  bcloud::WindowController controller;
  controller.showMainWindow();

  return app.exec();
}