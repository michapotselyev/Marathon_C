#include "../inc/minilibmx.h"

int main (int argc, char *argv[])
{
    //Argc check
    if (argc != 5)
    {
        write(1, "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n", 71);
        exit(0);
    }
    //////////////////////////////////////////////////////////////////////////////

    //Error check
    is_error = ERROR_FALSE;
    is_operation = OPER_FALSE;

    char *first_operand = mx_strtrim(argv[1]);
    char *second_operand = mx_strtrim(argv[3]);
    char *result = mx_strtrim(argv[4]);
    char *operation_sign = mx_strtrim(argv[2]);
    int first_operand_length = mx_strlen(first_operand);
    int second_operand_length = mx_strlen(second_operand);
    int result_length = mx_strlen(result);

    mx_check_operation(operation_sign);
    mx_check_operand(first_operand, second_operand, result, operation_sign);
    //////////////////////////////////////////////////////////////////////////////

    //Error output
    if (is_error == ERROR_TRUE)
    {
        switch (error)
        {
            case INVALID_OPERAND_1:
                write(2, "Invalid operand: ", 17);
                mx_printerr(first_operand);
                write(2, "\n", 1);
                exit (0);

            case INVALID_OPERATION:
                write(2, "Invalid operation: ", 19);
                mx_printerr(operation_sign);
                write(2, "\n", 1);
                exit (0);

            case INVALID_OPERAND_2:
                write(2, "Invalid operand: ", 17);
                mx_printerr(second_operand);
                write(2, "\n", 1);
                exit (0);

            case INVALID_RESULT:
                write(2, "Invalid result: ", 16);
                mx_printerr(result);
                write(2, "\n", 1);
                exit (0);
                
            case DIV_BY_ZERO:
                exit (0);
        }
    }
    //////////////////////////////////////////////////////////////////////////////   

    mx_output_matrix(first_operand, second_operand, result, first_operand_length, second_operand_length, result_length);
    
    free(first_operand);
    first_operand = NULL;
    free(operation_sign);
    operation_sign = NULL;
    free(second_operand);
    second_operand = NULL;
    free(result);
    result = NULL;
}

