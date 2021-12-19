#ifndef CAPTURE_H
#define CAPTURE_H

#include <stdafx.h>

typedef struct {
    int i;
    float f;
    const char* string;
} key_bind_arg;

typedef struct {
    DWORD keys[2];
    VOID(*func)(key_bind_arg args);
    const key_bind_arg args;
} key_bind;

class capture {
public:
    static BOOL capture_key(DWORD vkCode);
    static BOOL compare_key_sym(key_bind key_sequence, key_bind match);
    static BOOL filter_key_sym(key_bind key_sequence, key_bind bindings[], int count);
private:
    static key_bind frame;
};

#endif // CAPTURE_H