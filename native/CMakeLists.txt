
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5X11Extras REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5LinguistTools)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(QT_CORE_LIBS Qt5::Core)
set(QT_LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::Network
    Qt5::Widgets
    Qt5::X11Extras
    Qt5::Xml)

add_subdirectory(third_party/gtest)

set(BASE_FILES
    base/const.h
    base/file_util.cpp
    base/file_util.h
    base/json_util.cpp
    base/json_util.h
    base/string_util.cpp
    base/string_util.h)

set(SERVICES_FILES
    services/pcs.cpp
    services/pcs.h
    services/user_profile.cpp
    services/user_profile.h)

set(UI_FILES
    ui/images/images.qrc
    ui/images/images_rcc.h

    ui/controllers/window_controller.cpp
    ui/controllers/window_controller.h

    ui/frames/access_code_dialog.cpp
    ui/frames/access_code_dialog.h
    ui/frames/bt_page.cpp
    ui/frames/bt_page.h
    ui/frames/category_page.h
    ui/frames/cloud_download_page.cpp
    ui/frames/cloud_download_page.h
    ui/frames/documents_page.cpp
    ui/frames/documents_page.h
    ui/frames/download_page.cpp
    ui/frames/download_page.h
    ui/frames/file_property_dialog.cpp
    ui/frames/file_property_dialog.h
    ui/frames/filter_category_page.h
    ui/frames/folder_browser_dialog.cpp
    ui/frames/folder_browser_dialog.h
    ui/frames/folder_property_dialog.cpp
    ui/frames/folder_property_dialog.h
    ui/frames/home_page.cpp
    ui/frames/home_page.h
    ui/frames/login_dialog.cpp
    ui/frames/login_dialog.h
    ui/frames/main_window.cpp
    ui/frames/main_window.h
    ui/frames/music_page.cpp
    ui/frames/music_page.h
    ui/frames/new_folder_dialog.cpp
    ui/frames/new_folder_dialog.h
    ui/frames/others_category_page.cpp
    ui/frames/others_category_page.h
    ui/frames/pictures_page.cpp
    ui/frames/pictures_page.h
    ui/frames/settings_page.cpp
    ui/frames/settings_page.h
    ui/frames/share_page.cpp
    ui/frames/share_page.h
    ui/frames/trash_page.cpp
    ui/frames/trash_page.h
    ui/frames/upload_page.cpp
    ui/frames/upload_page.h
    ui/frames/user_avatar.cpp
    ui/frames/user_avatar.h
    ui/frames/verify_code_dialog.cpp
    ui/frames/verify_code_dialog.h
    ui/frames/videos_page.cpp
    ui/frames/videos_page.h

    ui/models/category_model.cpp
    ui/models/category_model.h)

set(UNITTEST_FILES
    base/file_util_test.cpp
    base/json_util_test.cpp
    base/string_util_test.cpp)

## Executables
add_executable(bcloud
               app/bcloud.cpp
               ${BASE_FILES}
               ${SERVICES_FILES}
               ${UI_FILES})
target_link_libraries(bcloud ${QT_LIBS})


# Unittest
add_executable(unittest-main
               app/unittest_main.cpp
               ${BASE_FILES}
               ${UNITTEST_FILES})
target_link_libraries(unittest-main
                      ${QT_CORE_LIBS}
                      gtest)