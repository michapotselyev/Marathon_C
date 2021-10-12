#include "../inc/minilibmx.h"

void mx_printerr(const char *s)
{
    char *ch = mx_del_extra_whitespaces(s);
    write(2, ch, mx_strlen(ch));
}

