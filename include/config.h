#ifndef CONFIG_H
#define CONFIG_H

#include <stdafx.h>
//#include <functions.h>
#include <capture.h>

#define ALT_KEY 164
#define KEY_ENTER 13
#define KEY_T 84
#define KEY_S 83
#define KEY_Q 81
#define KEY_P 80
#define KEY_M 77
#define KEY_K 75
#define KEY_H 72
#define KEY_F 70
#define KEY_E 69
#define KEY_C 67
#define KEY_B 66



static key_bind quit_flag = { { ALT_KEY, KEY_Q }, NULL };

static char* cmdterm = "wt.exe\n";

static const int key_count = 1;
//static const key_bind keys[] = {
//
//    {{ALT_KEY, KEY_B}, functions::launch_browser, NULL},
//    /*      {{ALT_KEY, KEY_F}, functions::launch_explorer, NULL},
//          {{ALT_KEY, KEY_ENTER}, functions::launch_terminal, NULL},*/
//};



#endif // CONFIG_H