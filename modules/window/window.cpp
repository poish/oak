//
// Created by robert on 15.09.2021.
//
#include "window.h"

#include "../../module-system/system.h"
#include "callbacks.h"

#include <iostream>


Window::~Window() {}

std::string Window::name() {

    return std::string("Window");
}

void Window::init(){

    std::cout << "Window initialized" << std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

void Window::launch(){

    context.glfwWindowInstance = glfwCreateWindow(context.width, context.height, "LearnOpenGL", NULL, NULL);
    if (context.glfwWindowInstance == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    else{

        context.created = true;
    }

    glfwMakeContextCurrent(context.glfwWindowInstance);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glfwSetKeyCallback(context.glfwWindowInstance, keyboardEventCallback);
    glfwSetMouseButtonCallback(context.glfwWindowInstance, mouseEventCallback);
    glfwSetCursorPosCallback(context.glfwWindowInstance,  cursorEventCallback);
    glfwSetCharCallback(context.glfwWindowInstance, characterEventCallback);
}

bool Window::shouldClose() {

    return glfwWindowShouldClose(context.glfwWindowInstance);
}

void Window::refresh() {

    glfwSwapBuffers(context.glfwWindowInstance);
    glfwPollEvents();
}

bool Window::windowCreated() {

    return context.created;
}
