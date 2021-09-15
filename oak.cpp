//
// Created by robert on 15.09.2021.
//
#include "oak.h"
#include <iostream>

#include "modules/window/callback-relay.h"

Oak::Oak(){

    addModule(std::make_shared<Window>(this));
    addModule(std::make_shared<Input>(this));

    r = 1.0;
    g = 0.0;
    b = 0.0;
}

std::shared_ptr<Window> Oak::getWindow(){

    std::shared_ptr<Window> window = std::dynamic_pointer_cast<Window>(getModule("Window"));
    return window;
}

std::shared_ptr<Input> Oak::getInput(){

    std::shared_ptr<Input> input = std::dynamic_pointer_cast<Input>(getModule("Input"));
    return input;
}

void Oak::run(){

    initModules();
    auto window = getWindow();

    prepare();

    window->launch();
    bindToCallbackRelay(); // This needs to be called AFTER the window::launch;

    before();

    while(!window->shouldClose()){

        body();
        window->refresh();
    }

    after();

    //terminateModules();
}

void Oak::body() {

    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Oak::keyboardEvent(int key, int scancode, int action, int mods){

    auto input = getInput();
    input->keyboardEvent(key, scancode, action, mods);
}

void Oak::characterEvent(unsigned int codepoint) {

    auto input = getInput();
    input->characterEvent(codepoint);
}

void Oak::mouseEvent(int button, int action, int mods) {

    auto input = getInput();
    input->mouseEvent(button, action, mods);
}

void Oak::cursorEvent(double xpos, double ypos) {

    auto input = getInput();
    input->cursorEvent(xpos, ypos);
}

void Oak::framebufferResize(int width, int height) {

    auto window = getWindow();
    window->updateFramebufferSize(width, height);

    onFramebufferResize();
}

void Oak::bindToCallbackRelay() {

    CallbackRelay::setTarget(this);
}