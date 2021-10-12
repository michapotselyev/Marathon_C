#include "../inc/minilibmx.h"

void mx_printstr(const char *s)
{
        int out_lenght = mx_strlen(s);
        write(1, s, out_lenght);
}

