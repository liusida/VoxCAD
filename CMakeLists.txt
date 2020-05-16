cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE "Debug")
option(BUILD_SHARED_LIBS "Build shared library" OFF)
option(BUILD_STATIC_LIBS "Build static library" ON)

project(voxcad2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VOXCAD ${CMAKE_CURRENT_LIST_DIR}/VoxCad)
set(VX2 ${CMAKE_CURRENT_LIST_DIR}/Voxelyze)
set(VX1 ${CMAKE_CURRENT_LIST_DIR}/oldVoxelyze)
set(QTUTILS ${CMAKE_CURRENT_LIST_DIR}/QTUtils)


file(GLOB VOXCAD_SRC ${VOXCAD}/*.c*)
file(GLOB VX2_SRC ${VX2}/src/*.c*)
file(GLOB VX1_SRC ${VX1}/*.c*)
file(GLOB QTUTILS_SRC ${QTUTILS}/*.c*)

file(GLOB VOXCAD_HEADER ${VOXCAD}/*.h*)
file(GLOB VX2_HEADER ${VX2}/include/*.h*)
file(GLOB VX1_HEADER ${VX1}/*.h*)
file(GLOB QTUTILS_HEADER ${QTUTILS}/*.h*)

add_executable(voxcad2 ${VOXCAD}/VoxCad.qrc ${VOXCAD_SRC} ${VX2_SRC} ${VX1_SRC} ${QTUTILS_SRC} ${VOXCAD_HEADER} ${VX2_HEADER} ${VX1_HEADER} ${QTUTILS_HEADER})
install(TARGETS voxcad2 DESTINATION bin)

add_compile_definitions(QT_XML_LIB QT_OPENGL_LIB USE_ZLIB_COMPRESSION USE_OPEN_GL QT_DLL PREC_MED USE_OMP)

target_include_directories(voxcad2 PUBLIC ${VOXCAD} ${VX2}/include ${VX1} ${QTUTILS}
)
find_package(Qt5 COMPONENTS Core Gui Xml OpenGL Concurrent Widgets REQUIRED)
target_link_libraries(voxcad2 PRIVATE Qt5::Core Qt5::Gui Qt5::Xml Qt5::OpenGL Qt5::Concurrent Qt5::Widgets)



#for visualization
set(OpenGL_GL_PREFERENCE GLVND)
if (UNIX)
    find_package(OpenGL REQUIRED) # find and include OpenGL
    if (OpenGL_FOUND)
        message(STATUS "OPENGL FOUND")
        target_include_directories(voxcad2 PRIVATE ${OpenGL_INCLUDE_DIRS})
        target_link_libraries(voxcad2 PRIVATE ${OpenGL_LIBRARIES} GL)
        target_link_libraries(voxcad2 PRIVATE ${OPENGL_glu_LIBRARY})
    endif()
else()
    find_package(OPENGL REQUIRED) # find and include OpenGL
    if (OPENGL_FOUND)
        message(STATUS "OPENGL FOUND")
        target_include_directories(voxcad2 PRIVATE ${OPENGL_INCLUDE_DIRS})
        target_link_libraries(voxcad2 PRIVATE ${OPENGL_LIBRARIES})
    endif()
endif()

find_package(glfw3 CONFIG REQUIRED)
if (glfw3_FOUND)
    message(STATUS "GLFW FOUND")
    target_include_directories(voxcad2 PRIVATE ${glfw3_INCLUDE_DIRS})
    target_link_libraries(voxcad2 PRIVATE ${glfw3_LIBRARIES})
endif()

find_package(GLUT REQUIRED) # GLEW
if (GLUT_FOUND)
    message(STATUS "GLUT FOUND")
    target_include_directories(voxcad2 PRIVATE ${GLUT_INCLUDE_DIRS})
    target_link_libraries(voxcad2 PRIVATE ${GLUT_LIBRARIES} glut)
endif()

find_package(glm CONFIG REQUIRED) # glm
if (glm_FOUND)
    message(STATUS "GLM FOUND")
    target_include_directories(voxcad2 PRIVATE ${glm_INCLUDE_DIRS})
    target_link_libraries(voxcad2 PRIVATE ${glm_LIBRARIES} glm)
endif()


#for zlib
find_package(ZLIB)
target_link_libraries(voxcad2 PRIVATE ${ZLIB_LIBRARIES})
