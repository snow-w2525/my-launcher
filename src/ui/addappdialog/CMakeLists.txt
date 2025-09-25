set(OBJ_NAME AddAppDialog)

set(CMAKE_AUTOUIC ON)

add_library(${OBJ_NAME} OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/addappdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/addappdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/addappdialog.ui
)

target_include_directories(${OBJ_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}                 # includeパスを公開
)

target_sources(${APP_NAME}
    PRIVATE
        $<TARGET_OBJECTS:${OBJ_NAME}>
)
target_link_libraries(${OBJ_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Widgets
)
