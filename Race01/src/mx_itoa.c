#include "../inc/minilibmx.h"

char *mx_itoa(long long num)
{
    char *num_str = NULL;

    if (num == 0)
    {
        num_str = mx_strnew(1);
        num_str[0] = '0';
        return num_str;
    }

    int len = 0;
    int num_copy = num;

    if (num_copy < 0)
    {
        len++;
        num_copy *= -1;
    }

    while (num_copy != 0)
    {
        num_copy /= 10;
        len++;
    }

    num_str = mx_strnew(len);
    
    if (num < 0)
    {
        num_str[0] = '-';
        num *= -1;
    }

    num_str[len--] = '\0';

    while ((num != 0 && len >= 0) && num_str[len] != '-')
    {
        num_str[len--] = (num % 10) + '0';
        num /= 10;
    }

    return num_str;
}

