//
// Created by robert on 15.09.2021.
//

#ifndef OAK_OAK_H
#define OAK_OAK_H

#include <memory>

#include "module-system/system.h"

#include "modules/window/window.h"#include "modules/input/input.h"

class CallbackRelay;

class Oak : public System {

public:
    Oak();
    ~Oak(){}

    void run();

    float r, g, b;

protected:

    // Shorthand functions for getting the pointers associated with window and input modules

    std::shared_ptr<Window> getWindow();
    std::shared_ptr<Input> getInput();


    virtual void prepare() {}
    virtual void before() {}
    virtual void body();
    virtual void after() {}

    virtual void onFramebufferResize() {}

private:

    /* Below is a list of functions associated with various window and input events.
     * They are called by the CallbackRelay.

    /* Propagates key event to Input module */
    void keyboardEvent(int key, int scancode, int action, int mods);

    /* Propagates characters associated with key presses to Input module */
    void characterEvent(unsigned codepoint);

    /* Propagates mouse button events to Input module */
    void mouseEvent(int button, int action, int mods);

    /* Propagates mouse motion events to Input module */
    void cursorEvent(double xpos, double ypos);

    /* Receives */
    void framebufferResize(int width, int height);

    /* Passes a pointer to this class to Callback Relay */
    void bindToCallbackRelay();

    friend CallbackRelay;
};
#endif //OAK_OAK_H
