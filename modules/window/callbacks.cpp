//
// Created by robert on 15.09.2021.
//
#include "callbacks.h"
#include "callback-relay.h"

void keyboardEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    CallbackRelay::pushKeyboardEvent(window, key, scancode, action, mods);
}

void mouseEventCallback(GLFWwindow* window, int button, int action, int mods) {

    CallbackRelay::pushMouseEvent(window, button, action, mods);
}

void characterEventCallback(GLFWwindow* window, unsigned codepoint) {

    CallbackRelay::pushCharacterEvent(window, codepoint);
}

void cursorEventCallback(GLFWwindow* window, double xpos, double ypos) {

    CallbackRelay::pushCursorEvent(window, xpos, ypos);
}

void framebufferResizeCallback(GLFWwindow* window, int width, int height) {

    CallbackRelay::pushFramebufferResize(window, width, height);
}