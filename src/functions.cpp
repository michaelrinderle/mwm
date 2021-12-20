#include <functions.h>
#include <config.h>

VOID 
functions::launch_browser(key_bind_arg args)
{
    ShellExecute(NULL, "open", "https://www.startpage.com", NULL, NULL, SW_SHOWNORMAL);
}

VOID 
functions::launch_explorer(key_bind_arg args)
{
    system("start c:\\");
}

VOID
functions::launch_terminal(key_bind_arg args)
{
    system("wt.exe\n");
}

VOID
functions::mesg_send(const char* mesg)
{
    MessageBox(NULL, mesg, "Yo!", 0);
}