//
// Created by robert on 15.09.2021.
//

#ifndef OAK_WINDOW_H
#define OAK_WINDOW_H
#include "../../module-system//module.h"

#include "glfw-header.h"

#include <iostream> // delete this

class Window : public Module {

public:

    Window(System* owner) : Module(owner) {

        context.created = false;
        context.width = 600;
        context.height = 400;
    };

    ~Window();

    std::string name() override;

    void init() override;

    void launch();

    bool shouldClose();

    void refresh();

    struct {
        GLFWwindow* glfwWindowInstance;
        bool created;
        int width, height;
    } context;

    bool windowCreated();

    void updateFramebufferSize(int width, int height){

        context.width = width;
        context.height = height;
    }
};


#endif //OAK_WINDOW_H
