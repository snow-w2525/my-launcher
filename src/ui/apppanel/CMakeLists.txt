set(OBJ_NAME AppPanel)

set(CMAKE_AUTOUIC ON)

add_library(${OBJ_NAME} OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/apppanel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/apppanel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/apppanel.ui
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
        AppInfo
)
