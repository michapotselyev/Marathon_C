#pragma once

#ifndef CALC_H
#define CALC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int mx_add(int a, int b);

int mx_sub(int a, int b);

int mx_mul(int a, int b);

int mx_div(int a, int b);

enum e_operation {
    ADD,
    SUB,
    MUL,
    DIV,
    UNKNOWN_OPERATION
};

enum e_operation operation;

enum e_operation_flag {
    OPER_TRUE,
    OPER_FALSE
};

enum e_operation_flag is_operation;

enum e_error {
    INVALID_OPERAND_1,
    INVALID_OPERAND_2,
    INVALID_RESULT,
    INVALID_OPERATION,
    DIV_BY_ZERO
};

enum e_error error;

enum e_error_flag {
    ERROR_TRUE,
    ERROR_FALSE
};

enum e_error_flag is_error;

int mx_atoi(const char*);

void mx_check_operand(char*, char*, char*, char*);

void mx_check_operation(char*);

char *mx_del_extra_whitespaces(const char*);

bool mx_isdigit(int);

bool mx_isspace(char);

char *mx_itoa(long long);

void mx_output_matrix(char*, char*, char*, int, int, int);

double mx_pow(double, unsigned int);

void mx_printchar(char);

void mx_printerr(const char*);

void mx_printint(int);

void mx_printstr(const char*);

char *mx_strcpy(char*, const char*);

void mx_strdel(char**);

int mx_strlen(const char*);

int mx_strncmp(const char*, const char*, int);

char *mx_strncpy(char*, const char*, int);

char *mx_strnew(const int);

char *mx_strtrim(const char*);

#endif

