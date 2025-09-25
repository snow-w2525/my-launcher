cmake_minimum_required(VERSION 3.19)

# Set app name
set(APP_NAME my-launcher)

#Set project.
project(${APP_NAME} LANGUAGES CXX)

# Add Qt package
find_package(
    Qt6 6.5 REQUIRED 
    COMPONENTS
        Core
        Widgets
        LinguistTools
)
qt_standard_project_setup()

qt_add_executable(${APP_NAME}
    WIN32 MACOSX_BUNDLE
)

add_subdirectory(resources)
add_subdirectory(translations)
add_subdirectory(src/appinfo)
add_subdirectory(src/ui)

target_sources(${APP_NAME}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${APP_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
        AppInfo
        MainWindow
        Resources
)

include(GNUInstallDirs)

install(TARGETS ${APP_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET ${APP_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
