//
// Created by robert on 15.09.2021.
//

#ifndef OAK_CALLBACKS_H
#define OAK_CALLBACKS_H

#include "glfw-header.h"

/* These are callback functions passed to GLFW as means of receiving information about
 * window and user input events. Their purpose is to call to CallbackRelay, which then,
 * based on the *window pointer, relays the call to a proper Oak instance.
 */

void keyboardEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void characterEventCallback(GLFWwindow* window, unsigned codepoint);

void mouseEventCallback(GLFWwindow* window, int button, int action, int mods);

void cursorEventCallback(GLFWwindow* window, double xpos, double ypos);

void framebufferResizeCallback(GLFWwindow* window, int width, int height);

#endif //OAK_CALLBACKS_H
