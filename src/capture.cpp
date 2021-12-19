#include <capture.h>
#include <config.h>

key_bind capture::frame = { { 0, 0 }, NULL };

BOOL
capture::capture_key(DWORD vkCode)
{
    capture::frame.keys[0] = capture::frame.keys[1];
    capture::frame.keys[1] = vkCode;
    // filter_key_sym(capture::frame, keys, key_count);
    return capture::compare_key_sym(capture::frame, quit_flag);
}

BOOL
capture::compare_key_sym(key_bind key_sequence, key_bind match)
{
    return (key_sequence.keys[0] == match.keys[0] &&
            key_sequence.keys[1] == match.keys[1]);
}

BOOL
capture::filter_key_sym(key_bind key_sequence, key_bind bindings[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (capture::compare_key_sym(key_sequence, bindings[i]))
        {
            bindings[i].func(bindings[i].args);
            return TRUE;
        }
    }
    return FALSE;
}
