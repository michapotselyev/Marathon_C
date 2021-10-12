#include "../inc/minilibmx.h"

void mx_output_matrix(char *first_operand, char *second_operand, char *result, int first_operand_length, int second_operand_length, int result_length)
{
    if (operation == UNKNOWN_OPERATION)
    {
        operation = ADD;
        mx_output_matrix(first_operand, second_operand, result, first_operand_length, second_operand_length, result_length);
        operation = SUB;
        mx_output_matrix(first_operand, second_operand, result, first_operand_length, second_operand_length, result_length);
        operation = MUL;
        mx_output_matrix(first_operand, second_operand, result, first_operand_length, second_operand_length, result_length);
        operation = DIV;
        mx_output_matrix(first_operand, second_operand, result, first_operand_length, second_operand_length, result_length);
        exit (0);
    }

    else
    {
        bool if_first_operand_negative = false;
        bool if_second_operand_negative = false;
        bool if_result_negative = false;

        if (first_operand[0] == '-')
        {
            if_first_operand_negative = true;
            first_operand++;
            first_operand_length--;
        }

        if (second_operand[0] == '-')
        {
            if_second_operand_negative = true;
            second_operand++;
            second_operand_length--;
        }

        if (result[0] == '-')
        {
            if_result_negative = true;
            result++;
            result_length--;
        }

        long long first_operand_number = mx_atoi(first_operand);
        long long second_operand_number = mx_atoi(second_operand);
        long long result_number = mx_atoi(result);

        for (long long i = 0; i < mx_pow(10, first_operand_length); i++)
        {
            if (first_operand_number > 0)
            {
                i = first_operand_number;
            }

            char *i_str = mx_itoa(i);
            int i_str_length = mx_strlen(i_str);
            bool if_true_i = true;

            for (int k = 0; k < first_operand_length - i_str_length; k++)
            {
                if (mx_isdigit(first_operand[k]) && first_operand[k] != '0')
                {
                    if_true_i = false;
                    break;
                }
            }

            for (int k = first_operand_length - i_str_length, i_str_i = 0; k < first_operand_length; k++, i_str_i++)
            {
                if (first_operand[k] != '?' && first_operand[k] != i_str[i_str_i])
                {
                    if_true_i = false;
                    break;
                }
            }

            free(i_str);
            i_str = NULL;

            if (!if_true_i)
            {
                continue;
            }

            for (long long j = 0; j < mx_pow(10, second_operand_length); j++)
            {  
                if (second_operand_number > 0)
                {
                    j = second_operand_number;
                }

                char *j_str = mx_itoa(j);
                int j_str_length = mx_strlen(j_str);
                bool if_true_j = true;

                for (int k = 0; k < second_operand_length - j_str_length; k++)
                {
                    if (mx_isdigit(second_operand[k]) && second_operand[k] != '0')
                    {
                        if_true_j = false;
                        break;
                    }
                }

                for (int k = second_operand_length - j_str_length, j_str_i = 0; k < second_operand_length; k++, j_str_i++)
                {
                    if (second_operand[k] != '?' && second_operand[k] != j_str[j_str_i])
                    {
                        if_true_j = false;
                        break;
                    }
                }

                free(j_str);
                j_str = NULL;

                if (!if_true_j)
                {
                    continue;
                }
                
                for (long long z = 0; z < mx_pow(10, result_length); z++)
                {
                    if (result_number > 0)
                    {
                        z = result_number;
                    }

                    char *z_str = mx_itoa(z);
                    int z_str_length = mx_strlen(z_str);
                    bool if_true_z = true;

                    for (int k = 0; k < result_length - z_str_length; k++)
                    {
                        if (mx_isdigit(result[k]) && result[k] != '0')
                        {
                            if_true_z = false;
                            break;
                        }
                    }

                    for (int k = result_length - z_str_length, z_str_i = 0; k < result_length; k++, z_str_i++)
                    {
                        if (result[k] != '?' && result[k] != z_str[z_str_i])
                        {
                            if_true_z = false;
                            break;
                        }
                    }

                    free(z_str);
                    z_str = NULL;

                    if (!if_true_z)
                    {
                        continue;
                    }

                    //output
                    if (if_first_operand_negative)
                    {
                        i *= -1;
                    }

                    if (if_second_operand_negative)
                    {
                        j *= -1;
                    }

                    if (if_result_negative)
                    {
                        z *= -1;
                    }

                    if (is_operation == OPER_TRUE)
                    {
                        switch (operation)
                        {
                            case ADD:
                                if (i + j == z)
                                {
                                    mx_printint(i);
                                    mx_printstr(" + ");
                                    mx_printint(j);
                                    mx_printstr(" = ");
                                    mx_printint(z);
                                    mx_printchar('\n');
                                    break;
                                }

                                else
                                {
                                    break;
                                }

                            case SUB:
                                if (i - j == z)
                                {
                                    mx_printint(i);
                                    mx_printstr(" - ");
                                    mx_printint(j);
                                    mx_printstr(" = ");
                                    mx_printint(z);
                                    mx_printchar('\n');
                                    break;
                                }

                                else
                                {
                                    break;
                                }
                            
                            case MUL:
                                if (i * j == z)
                                {
                                    mx_printint(i);
                                    mx_printstr(" * ");
                                    mx_printint(j);
                                    mx_printstr(" = ");
                                    mx_printint(z);
                                    mx_printchar('\n');
                                    break;
                                }

                                else
                                {
                                    break;
                                }
                            
                            case DIV:
                                if (j != 0 && i / j == z)
                                {
                                    mx_printint(i);
                                    mx_printstr(" / ");
                                    mx_printint(j);
                                    mx_printstr(" = ");
                                    mx_printint(z);
                                    mx_printchar('\n');
                                    break;
                                }

                                else
                                {
                                    break;
                                }

                            case UNKNOWN_OPERATION:
                                break;
                        }
                        
                    }
                    
                    if (if_first_operand_negative) {
                        i *= -1;
                    }

                    if (if_second_operand_negative) {
                        j *= -1;
                    }

                    if (if_result_negative) {
                        z *= -1;
                    }

                    if (result_number > 0) {
                        break;
                    }
                }

                if (second_operand_number > 0) {
                    break;
                }
            }
            if (first_operand_number > 0) {
                break;
            }
        }

        if (if_first_operand_negative) {
            first_operand--;
        }
        if (if_second_operand_negative) {
            second_operand--;
        }
        if (if_result_negative) {
            result--;
        }
    } 
}

