#include <window.h>
#include <ShObjIdl_core.h>

std::vector<window_handle> window::h_windows;
desktop_specs window::desktop;

const CLSID CLSID_ImmersiveShell = {
	0xC2F03A33, 0x21F5, 0x47FA, 0xB4, 0xBB, 0x15, 0x63, 0x62, 0xA2, 0xF2, 0x39 };

VOID 
window::window_kill(key_bind_arg args)
{
    HWND hwnd = GetForegroundWindow();
    if (hwnd != NULL)
    {
        SendMessage(hwnd, WM_CLOSE, 0, 0);
        DestroyWindow(hwnd);
    }
}

VOID 
window::window_hide(key_bind_arg args)
{
    HWND hwnd = GetForegroundWindow();
    if (hwnd != NULL)
    {
        WINDOWPLACEMENT place;
        memset(&place, 0, sizeof(WINDOWPLACEMENT));
        place.length = sizeof(WINDOWPLACEMENT);
        GetWindowPlacement(hwnd, &place);
        ShowWindow(hwnd, SW_MINIMIZE);
    }
}

VOID 
window::window_maximize(key_bind_arg args)
{
    HWND hwnd = GetForegroundWindow();
    if (hwnd != NULL)
    {
        WINDOWPLACEMENT place;
        memset(&place, 0, sizeof(WINDOWPLACEMENT));
        place.length = sizeof(WINDOWPLACEMENT);
        GetWindowPlacement(hwnd, &place);

        if (place.showCmd == SW_NORMAL)
            ShowWindow(hwnd, SW_SHOWMAXIMIZED);
        else
            ShowWindow(hwnd, SW_NORMAL);
    }
}

VOID
window::desktop_create(key_bind_arg args)
{
    INPUT inputs[6] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_CONTROL;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 0x68;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = 0x68;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[4].type = INPUT_KEYBOARD;
    inputs[4].ki.wVk = VK_CONTROL;
    inputs[4].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[5].type = INPUT_KEYBOARD;
    inputs[5].ki.wVk = VK_LWIN;
    inputs[5].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

VOID
window::desktop_view(key_bind_arg args)
{
    INPUT inputs[4] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_TAB;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_TAB;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_LWIN;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

VOID 
window::desktop_move(key_bind_arg args) {
    HWND hwnd = GetForegroundWindow();
    if (hwnd != NULL)
    {
        ::CoInitialize(NULL);
        IServiceProvider*  service_provider = NULL;
        HRESULT hr = ::CoCreateInstance(
            CLSID_ImmersiveShell, NULL, CLSCTX_LOCAL_SERVER,
            __uuidof(IServiceProvider), (PVOID*)&service_provider);

        if (SUCCEEDED(hr))
        {
            IVirtualDesktopManager* desktop_manager = NULL;
            hr = service_provider->QueryService(__uuidof(IVirtualDesktopManager), &desktop_manager);

            if (SUCCEEDED(hr))
            {
                BOOL bIsOnCurrentDesktop = FALSE;
                hr = desktop_manager->IsWindowOnCurrentVirtualDesktop(hwnd, &bIsOnCurrentDesktop);

                if (SUCCEEDED(hr))
                {
                    // use bIsOnCurrentDesktop as needed...
                }

                desktop_manager->Release();
            }

            service_provider->Release();
        }

        ::CoUninitialize();
    }
}

BOOL CALLBACK
window::enum_windows_cascade(HWND hwnd, long lParam)
{
    CHAR buff[MAX_PATH];
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    if ((style & WS_VISIBLE) != 0) {
        GetWindowText(hwnd, (LPSTR)buff, 254);
        if (strlen(buff) != 0) {

            BOOL block = FALSE;
            for (int i = 0; i < 2; i++) {
                if (strcmp(buff, blacklist[i]) == 0 &&
                    strlen(buff) != 0) {
                    block = TRUE;
                }
            }

            if (block) return FALSE;

            window_handle tile;
            memcpy(tile.title, buff, MAX_PATH);
            tile.hwnd = &hwnd;

            h_windows.push_back(tile);
        }
    }

    return TRUE;
}
