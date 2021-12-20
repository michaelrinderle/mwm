#ifndef HOOK_H
#define HOOK_H

#include <stdafx.h>

class hook {
public:
    static BOOL (*keystroke)(DWORD vkCode);
    int hook_set();
    void hook_loop();
    static LRESULT CALLBACK hook_proc(int nCode, WPARAM wparam, LPARAM lparam);
    int hook_release();

private:
    static HHOOK h_hook;
};

#endif // HOOK_H