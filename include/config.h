#ifndef CONFIG_H
#define CONFIG_H

#include <stdafx.h>
#include <functions.h>
#include <capture.h>
#include <window.h>

#define ALT_KEY 164
#define KEY_ENTER 13
#define KEY_V 86
#define KEY_T 84
#define KEY_S 83
#define KEY_Q 81
#define KEY_P 80
#define KEY_M 77
#define KEY_K 75
#define KEY_H 72
#define KEY_F 70
#define KEY_E 69
#define KEY_D 68
#define KEY_C 67
#define KEY_B 66

#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57

static key_bind quit_flag = { { ALT_KEY, KEY_Q }, NULL };
static char* cmdterm = "wt.exe\n";
static const int key_count = 9;
static const key_bind keys[] = 
{
    {{ALT_KEY, KEY_B},      functions::launch_browser,      NULL},
    {{ALT_KEY, KEY_F},      functions::launch_explorer,     NULL},
    {{ALT_KEY, KEY_ENTER},  functions::launch_terminal,     NULL},
    {{ALT_KEY, KEY_K},      window::window_kill,            NULL},
    {{ALT_KEY, KEY_H},      window::window_hide,            NULL},
    {{ALT_KEY, KEY_M},      window::window_maximize,        NULL},
    {{ALT_KEY, KEY_C},      window::desktop_create,         NULL},
    {{ALT_KEY, KEY_V},      window::desktop_view,           NULL},
    {{ALT_KEY, KEY_1},      window::desktop_move,           {1}},
};

#endif // CONFIG_H