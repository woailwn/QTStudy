cmake_minimum_required(VERSION 3.16)

project(IDentiFy VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
#设置opencv根目录
set(OpenCV_DIR "E:\\cppsoft\\opencv\\build")

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)
find_package(OpenCV REQUIRED COMPONENTS core imgproc)

qt_standard_project_setup(REQUIRES 6.5)
qt_add_resources(QML_RESOURCES qrc.qrc )
qt_add_executable(${PROJECT_NAME}
    main.cpp
    ${QML_RESOURCES}
    log.rc
    backend.h backend.cpp
    sample_images/sample_1.jpg sample_images/sample_2.jpg sample_images/sample_3.jpg sample_images/sample_4.jpg sample_images/sample_5.jpg sample_images/sample_6.jpg
    cameraworker.h cameraworker.cpp
    imageprovider.h imageprovider.cpp
)

include_directories(${OpenCV_INCLUDE_DIRS}) #包含opencv头文件

target_link_libraries(IDentiFy PRIVATE Qt6::Core)
target_link_libraries(IDentiFy PRIVATE Qt6::Core)
target_link_libraries(IDentiFy PRIVATE Qt6::Core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(${PROJECT_NAME} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appIDentiFy
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
    ${OpenCV_LIBS} # 链接opencv库
)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Multimedia)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
