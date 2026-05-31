#include "laptop.h"

bool is_symb(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) return true;
    return false;
}

bool check_not_only_space(const char* str){
    while(*str != '\0'){
        if(is_symb(*str)) return true;
        str++;
    }
    return false;
}

bool check_min_symb(const char* str){
    int min = 0, tmp = 0;
    while(*str != '\0'){
        if(is_symb(*str)) tmp++;
        else tmp = 0; 
        if(min < tmp){
            min = tmp;
        }
    }
    if(min <= 3)
        return false;
    else
        return true;
}


validation_errors is_valid(const laptop* lap){
    if(!check_not_only_space(lap->manufacturer)){
        return ERR0R_MANUFACTURER_EMPTY;
    }
    if(!check_min_symb(lap->manufacturer)){
        return ERR0R_MANUFACTURER_MIN_SYMB;
    }
    if(!check_not_only_space(lap->model_CPU)){
        return ERR0R_CPU_EMPTY;
    }
    if(!check_min_symb(lap->model_CPU)){
        return ERR0R_CPU_MIN_SYMB;
    }
    if(lap->have_GPU != true && lap->have_GPU != false){
        return ERROR_GPU_EMPTY;
    }
    return CORRECT;
}


