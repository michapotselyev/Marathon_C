#include "../inc/minilibmx.h"

char *mx_del_extra_whitespaces(const char *str)
{
    int count = 0;

    for (int i = 0; i < mx_strlen(str); i++)
    {
        if (!mx_isspace(str[i]))
        {
            count++;
        }
    }

    if (count == 0)
    {
        return " ";
    }

    count = 0;
    char *trimstr = mx_strtrim(str);
    

    for (int i = 0; i < mx_strlen(trimstr); i++) 
	{
        if (mx_isspace(trimstr[i]) && !mx_isspace(trimstr[i + 1])) 
		{
            count++;
        }

        else if(!mx_isspace(trimstr[i]))
        {
            count++;
        }
        
    }

    int quantity = count;
    char *str2 = mx_strnew(quantity);

    for (int i = 0, k = 0; i < mx_strlen(trimstr); i++)
    {
        if (mx_isspace(trimstr[i]) && !mx_isspace(trimstr[i + 1])) 
        {
            str2[k] = ' ';
            k++;
        }

        else if(!mx_isspace(trimstr[i]))
        {
            str2[k] = trimstr[i];
            k++;
        }
    }

    mx_strdel(&trimstr);
    return str2;
}

