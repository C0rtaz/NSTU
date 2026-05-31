#include <stdio.h>

#define STRING_MAX 255


enum valid{
    CORRECT,
    ERR0R_MANUFACTURER_EMPTY,
    ERR0R_MANUFACTURER_MIN_SYMB,
    ERR0R_CPU_EMPTY,
    ERR0R_CPU_MIN_SYMB,
    ERROR_GPU_EMPTY
} typedef validation_errors;


enum bool{
    false,
    true
} typedef bool;

struct Laptop{
    char manufacturer[STRING_MAX];
    char model_CPU[STRING_MAX];
    bool have_GPU;
} typedef laptop;