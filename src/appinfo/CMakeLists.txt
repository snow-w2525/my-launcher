set(OBJ_NAME AppInfo)

add_library(${OBJ_NAME} OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/appdefines.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/appdefines.h
)

# インクルードパスを公開
target_include_directories(${OBJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${APP_NAME}
    PRIVATE
        $<TARGET_OBJECTS:${OBJ_NAME}>
)
target_link_libraries(${OBJ_NAME} PRIVATE Qt6::Core)


