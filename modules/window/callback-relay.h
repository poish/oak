//
// Created by robert on 15.09.2021.
//

#ifndef OAK_CALLBACK_RELAY_H
#define OAK_CALLBACK_RELAY_H
#include "glfw-header.h"

class Oak;

class CallbackRelay {

    static Oak* target;
public:

    static void setTarget(Oak* tgt);
    static Oak* getTarget(GLFWwindow* context);

    static void pushKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void pushCharacterEvent(GLFWwindow* window, unsigned codepoint);
    static void pushMouseEvent(GLFWwindow* window, int button, int action, int mods);
    static void pushCursorEvent(GLFWwindow* window, double xpos, double ypos);

    static void pushFramebufferResize(GLFWwindow* window, int width, int height);
};
#endif //OAK_CALLBACK_RELAY_H
