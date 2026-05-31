#include <stdio.h>

enum bool{
    false,
    true
} typedef bool;

struct Laptop{
    char manufacturer[255];
    char model_CPU[255];
    bool have_GPU;
} typedef Laptop;