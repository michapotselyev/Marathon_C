#include "../inc/minilibmx.h"

void mx_check_operand(char *first_operand, char *second_operand, char *result, char *operation_sign)
{
    //Check len of first element
    if (mx_strlen(first_operand) <= 0)
    {
        error = INVALID_OPERAND_1;
        is_error = ERROR_TRUE;
    }
    //////////////////////////////////////////////////////////////////////

    //Check len of second element
    if (mx_strlen(second_operand) <= 0)
    {
        error = INVALID_OPERAND_2;
        is_error = ERROR_TRUE;
    }
    //////////////////////////////////////////////////////////////////////

    //Check len of result
    if (mx_strlen(result) <= 0)
    {
        error = INVALID_RESULT;
        is_error = ERROR_TRUE;
    }
    //////////////////////////////////////////////////////////////////////

    //Check if second element is 0 in div
    if (!mx_strncmp(second_operand, "0", 1) && !mx_strncmp(operation_sign, "/", 1))
    {
        error = DIV_BY_ZERO;
        is_error = ERROR_TRUE;
    }
    //////////////////////////////////////////////////////////////////////

    //Check valid of first element
    for (int i = 0; i < mx_strlen(first_operand); i++)
    {
        if (i == 0)
        {
            if (first_operand[i] == '-' || first_operand[i] == '+')
            {
                if (mx_strlen(first_operand) > 1)
                {
                    continue;
                }

                else
                {
                    error = INVALID_OPERAND_1;
                    is_error = ERROR_TRUE;
                }
            }
        }
        
        if (first_operand[i] != '?' && !mx_isdigit(first_operand[i]))
        {
            error = INVALID_OPERAND_1;
            is_error = ERROR_TRUE;
        }
    }
    //////////////////////////////////////////////////////////////////////

    if (is_error == ERROR_TRUE)
    {
        return;
    }

    //Check valid of second element
    for (int i = 0; i < mx_strlen(second_operand); i++)
    {
        if (i == 0)
        {
            if (second_operand[i] == '-' || second_operand[i] == '+')
            {
                if (mx_strlen(second_operand) > 1)
                {
                    continue;
                }

                else
                {
                    error = INVALID_OPERAND_2;
                    is_error = ERROR_TRUE;
                }
            }
        }
        
        if (second_operand[i] != '?' && !mx_isdigit(second_operand[i]))
        {
            error = INVALID_OPERAND_2;
            is_error = ERROR_TRUE;
        }
    }
    //////////////////////////////////////////////////////////////////////

    if (is_error == ERROR_TRUE)
    {
        return;
    }

    //Check valid of result
    for (int i = 0; i < mx_strlen(result); i++)
    {
        if (i == 0)
        {
            if (result[i] == '-' || result[i] == '+')
            {
                if (mx_strlen(result) > 1)
                {
                    continue;
                }

                else
                {
                    error = INVALID_RESULT;
                    is_error = ERROR_TRUE;
                }
            }
        }

        if (result[i] != '?' && !mx_isdigit(result[i]))
        {
            error = INVALID_RESULT;
            is_error = ERROR_TRUE;
        }
    }
    //////////////////////////////////////////////////////////////////////
}

