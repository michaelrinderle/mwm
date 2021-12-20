#ifndef WINDOWS_H
#define WINDOWS_H

#include <stdafx.h>
#include <capture.h>

static char blacklist[2][MAX_PATH] = {
    "Windows Input Experience",
    "Program Manager"
};

typedef struct {
    RECT rect;
    int width;
    int height;
} desktop_specs;

typedef struct {
    HWND* hwnd;
    char title[MAX_PATH];
    int pos_x;
    int pos_y;
} window_handle;

class window {
public:
    static std::vector<window_handle> h_windows;
    static desktop_specs desktop;

    static VOID window_kill(key_bind_arg args);
    static VOID window_hide(key_bind_arg args);
    static VOID window_maximize(key_bind_arg args);

    static VOID desktop_create(key_bind_arg args);
    static VOID desktop_view(key_bind_arg args);
 
    static VOID desktop_move(key_bind_arg args);
    
    static BOOL CALLBACK enum_windows_cascade(HWND hwnd, long lParam);
};

#endif // WINDOWS_H