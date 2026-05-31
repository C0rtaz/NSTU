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

bool is_symb(char c);
bool check_not_only_space(const char* str);
bool check_min_symb(const char* str);
validation_errors is_not_valid_manufacturer(const laptop* lap);
validation_errors is_not_valid_cpu(const laptop* lap);
validation_errors is_not_valid_gpu(const laptop* lap);
validation_errors is_not_valid(const laptop* lap);
void errors_output(validation_errors err);
bool laptop_init_default(laptop* lap);
bool laptop_init(laptop* lap, const char* man, const char* cpu, const bool gpu);
bool laptop_init_cpy(laptop* lap, const laptop* cpy_lap);
void laptop_output(laptop* lap);
bool lap_set_CPU(laptop* lap, const char* cpu);
bool lap_set_manufacturer(laptop* lap, const char* man);
bool lap_set_gpu(laptop* lap, const bool gpu);