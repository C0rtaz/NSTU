#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_MAX 255


typedef enum valid{
    CORRECT,
    ERR0R_MANUFACTURER_EMPTY,
    ERR0R_MANUFACTURER_MIN_SYMB,
    ERR0R_CPU_EMPTY,
    ERR0R_CPU_MIN_SYMB,
    ERR0R_GPU_EMPTY
}validation_errors;


typedef enum bool{
    false,
    true
}bool;

typedef struct Laptop{
    char manufacturer[STRING_MAX];
    char model_CPU[STRING_MAX];
    bool have_GPU;
}laptop;

bool is_symb(char);
bool check_not_only_space(const char*);
bool check_min_symb(const char*);
validation_errors is_not_valid_manufacturer(const laptop*);
validation_errors is_not_valid_cpu(const laptop*);
validation_errors is_not_valid_gpu(const laptop*);
validation_errors is_not_valid(const laptop*);
void errors_output(validation_errors);
bool laptop_init_default(laptop*);
bool laptop_init(laptop*, const char*, const char*, const bool);
bool laptop_init_cpy(laptop*, const laptop*);
void laptop_output(laptop*);
bool lap_set_CPU(laptop*, const char*);
bool lap_set_manufacturer(laptop*, const char*);
bool lap_set_gpu(laptop*, const bool);
laptop* create_laptop();
void free_laptop(laptop*);