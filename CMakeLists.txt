cmake_minimum_required(VERSION 3.19)
project(my-launcher LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(my-launcher
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    appdefiles.h appdefiles.cpp
    apppanel.h apppanel.cpp apppanel.ui
)

qt_add_translations(
    TARGETS my-launcher
    TS_FILES my-launcher_ja_JP.ts
)

qt6_add_resources(appicons resources.qrc)

target_sources(my-launcher PRIVATE ${appicons})

target_link_libraries(my-launcher
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS my-launcher
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET my-launcher
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
