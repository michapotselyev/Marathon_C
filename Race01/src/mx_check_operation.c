#include "../inc/minilibmx.h"

void mx_check_operation(char *operation_sign)
{
    //Check len of operation
    if (mx_strlen(operation_sign) != 1)
    {
        error = INVALID_OPERATION;
        is_error = ERROR_TRUE;
    }
    ///////////////////////////////////////////////////////////

    //Define operation if add
    if (mx_strncmp(operation_sign, "+", 1) == 0)
    {
        operation = ADD;
        is_operation = OPER_TRUE;
    }
    ///////////////////////////////////////////////////////////

    //Define operation if sub
    else if (mx_strncmp(operation_sign, "-", 1) == 0)
    {
        operation = SUB;
        is_operation = OPER_TRUE;
    }
    ///////////////////////////////////////////////////////////

    //Define operation if mul
    else if (mx_strncmp(operation_sign, "*", 1) == 0)
    {
        operation = MUL;
        is_operation = OPER_TRUE;
    }
    ///////////////////////////////////////////////////////////

    //Define operation if div
    else if (mx_strncmp(operation_sign, "/", 1) == 0)
    {
        operation = DIV;
        is_operation = OPER_TRUE;
    }
    ///////////////////////////////////////////////////////////

    //Define operation if unknown operation
    else if (mx_strncmp(operation_sign, "?", 1) == 0)
    {
        operation = UNKNOWN_OPERATION;
        is_operation = OPER_TRUE;
    }
    ///////////////////////////////////////////////////////////

    //Define error if error
    else
    {
        error = INVALID_OPERATION;
        is_error = ERROR_TRUE;
    }
    ///////////////////////////////////////////////////////////
}

