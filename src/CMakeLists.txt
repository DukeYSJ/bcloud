
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
    Qt5::Gui
    Qt5::Network
    Qt5::Widgets
    Qt5::X11Extras
    Qt5::Xml
    )

set(BASE_FILES
    base/const.h)

set(SERVICES_FILES
    services/user_profile.cpp
    services/user_profile.h)

set(UI_FILES
    ui/images/images.qrc
    ui/images/images_rcc.h

    ui/controllers/window_controller.cpp
    ui/controllers/window_controller.h
    ui/frames/main_window.cpp
    ui/frames/main_window.h
    ui/frames/login_window.cpp
    ui/frames/login_window.h ui/images/images_rcc.h)


## Executables
add_executable(bcloud
               app/bcloud.cpp
               ${BASE_FILES}
               ${SERVICES_FILES}
               ${UI_FILES})
target_link_libraries(bcloud ${QT_LIBS})