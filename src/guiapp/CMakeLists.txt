
message(STATUS "Building Connect4 Gui App")

set(CMAKE_OSX_DEPLOYMENT_TARGET 12.0)

set(connect4gui_SRCS
        main.cpp
        Connect4App.cpp
        opengl_shader.cpp
        file_manager.cpp
        opengl_shader.h
        file_manager.h
        bindings/imgui_impl_glfw.cpp
        bindings/imgui_impl_opengl3.cpp
        bindings/imgui_impl_glfw.h
        bindings/imgui_impl_opengl3.h
        assets/simple-shader.vs
        assets/simple-shader.fs
        )

add_executable(connect4Gui
        ${connect4gui_SRCS}
        )

#add_custom_command(TARGET connect4Gui
#    POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/guiapp/assets/simple-shader.vs ${PROJECT_BINARY_DIR}
#    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/guiapp/assets/simple-shader.fs ${PROJECT_BINARY_DIR}
#)

target_compile_definitions(connect4Gui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW)
target_link_libraries(connect4Gui ${CONAN_LIBS} connect4core)