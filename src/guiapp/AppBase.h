
#ifndef CONNECT4_APPBASE_H
#define CONNECT4_APPBASE_H

#include "imgui.h"
#include "bindings/imgui_impl_glfw.h"
#include "bindings/imgui_impl_opengl3.h"
#include "opengl_shader.h"
#include "file_manager.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <GL/glew.h> // Initialize with glewInit()

// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>

#define PI 3.14159265358979323846

static void glfw_error_callback(int error, const char *description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

template<typename Derived>
class AppBase {
public:
    AppBase() {
        // Setup window
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
            std::exit(1);

            // Decide GL+GLSL versions
#if __APPLE__
        // GL 3.2 + GLSL 150
        const char *glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Required on Mac
#else
        // GL 3.0 + GLSL 130
        const char *glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

        // Create window with graphics context
        window = glfwCreateWindow(1280, 720, "Dear ImGui - Conan", NULL, NULL);
        if (window == NULL)
            std::exit(1);
        glfwSetWindowSize(window, 1920, 1080);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // Enable vsync

        glfwSetMouseButtonCallback(window, &Derived::MouseButtonCallback);
        glfwSetCursorPosCallback(window, &Derived::CursorPosCallback);

        bool err = glewInit() != GLEW_OK;

        if (err)
        {
            fprintf(stderr, "Failed to initialize OpenGL loader!\n");
            std::exit(1);
        }

        int screen_width, screen_height;
        glfwGetFramebufferSize(window, &screen_width, &screen_height);
        glViewport(0, 0, screen_width, screen_height);

        // create our geometries
//        unsigned int vbo, vao, ebo;
//        create_triangle(vbo, vao, ebo);

        // init shader
//        Shader triangle_shader;
//        triangle_shader.init(FileManager::read("simple-shader.vs"), FileManager::read("simple-shader.fs"));

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
    }

    virtual ~AppBase() {
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void run() {
        startup();
        while(!glfwWindowShouldClose(window)) {
            // Poll and handle events (inputs, window resize, etc.)
            // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
            // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
            // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
            // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
            glfwPollEvents();
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            glClear(GL_COLOR_BUFFER_BIT);

            // feed inputs to dear imgui, start new frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            update();

            // Rendering
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glfwSwapBuffers(window);
        }
    }

    virtual void update() {
        static_cast<Derived*>(this)->update();
    }
    virtual void startup(){
        static_cast<Derived*>(this)->startup();
    }

private:
    GLFWwindow* window;

protected:
    Shader my_shader;
};
#endif //CONNECT4_APPBASE_H
