#include <hook.h>

HHOOK hook::h_hook = NULL;
BOOL(*hook::keystroke)(DWORD vkCode) = NULL;

int
hook::hook_set()
{
    hook::h_hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)hook_proc, NULL, 0);
    return hook::h_hook == NULL;
}

void
hook::hook_loop()
{
    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT
hook::hook_proc(int nCode, WPARAM wparam, LPARAM lparam)
{
    if (nCode < 0)
        CallNextHookEx(hook::h_hook, nCode, wparam, lparam);

    KBDLLHOOKSTRUCT* kb = (KBDLLHOOKSTRUCT*)lparam;
    if (wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN)
    {
        if ((*keystroke)(kb->vkCode))
            PostQuitMessage(0);
    }

    return CallNextHookEx(hook::h_hook, nCode, wparam, lparam);
}

int
hook::hook_release()
{
    int h_hook_status = UnhookWindowsHookEx(hook::h_hook);
    hook::h_hook = NULL;
    return h_hook_status;
}
