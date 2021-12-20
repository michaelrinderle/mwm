#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdafx.h>
#include <capture.h>

class functions {
public:
    static VOID launch_browser(key_bind_arg args);
    static VOID launch_desktops(key_bind_arg args);
    static VOID launch_explorer(key_bind_arg args);
    static VOID launch_terminal(key_bind_arg args);
    static VOID mesg_send(const char* mesg);
};

#endif // FUNCTIONS_H