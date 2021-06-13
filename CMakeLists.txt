cmake_minimum_required(VERSION 3.20.0)
project(qubit)
add_executable(${PROJECT_NAME} window.cpp quat.cpp event.cpp world.cpp slerp.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


target_include_directories(${PROJECT_NAME}
    PUBLIC ${OPENGL_INCLUDE_DIR}
    PUBLIC ${GLUT_INCLUDE_DIR}
    )

link_directories(/usr/local/lib)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})