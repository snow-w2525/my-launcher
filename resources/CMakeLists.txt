set(RESOURCE_FILE resources.qrc)

qt6_add_resources(RESOURCE_FILE resources.qrc)

add_library(Resources STATIC ${RESOURCE_FILE})

target_link_libraries(Resources PRIVATE Qt6::Core Qt6::Widgets)
