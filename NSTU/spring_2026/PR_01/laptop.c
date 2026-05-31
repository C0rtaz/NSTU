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

validation_errors is_not_valid_manufacturer(const laptop* lap){
    if(!check_not_only_space(lap->manufacturer)){
        return ERR0R_MANUFACTURER_EMPTY;
    }
    if(!check_min_symb(lap->manufacturer)){
        return ERR0R_MANUFACTURER_MIN_SYMB;
    }
    return CORRECT;
}

validation_errors is_not_valid_cpu(const laptop* lap){
    if(!check_not_only_space(lap->model_CPU)){
        return ERR0R_CPU_EMPTY;
    }
    if(!check_min_symb(lap->model_CPU)){
        return ERR0R_CPU_MIN_SYMB;
    }
    return CORRECT;
}

validation_errors is_not_valid_gpu(const laptop* lap){
    if(lap->have_GPU != true && lap->have_GPU != false){
        return ERROR_GPU_EMPTY;
    }
    return CORRECT;
}

validation_errors is_not_valid(const laptop* lap){
    validation_errors tmp = CORRECT;
    tmp = is_not_valid_manufacturer(&lap);
    if(tmp){
        return tmp;
    }
    tmp = is_not_valid_cpu(&lap);
    if(tmp){
        return tmp;
    }
    tmp = is_not_valid_gpu(&lap);
    if(tmp){
        return tmp;
    }
    return tmp;
}


void errors_output(validation_errors err){
    switch(err){
        case ERR0R_CPU_EMPTY:
            printf("ERR0R:CPU is empty");
        case ERR0R_CPU_MIN_SYMB:
            printf("ERR0R:CPU is need more 3 symbols");
        case ERR0R_MANUFACTURER_EMPTY:
            printf("ERR0R:Manufacturer is empty");
        case ERR0R_MANUFACTURER_MIN_SYMB:
            printf("ERR0R:Manufacturer is need more 3 symbols");
        case ERROR_GPU_EMPTY:
            printf("ERR0R:GPU is empty");
    }
    return 0;
}

bool laptop_init_default(laptop* lap){
    strcpy(lap->manufacturer, "None");
    strcpy(lap->model_CPU, "None");
    lap->have_GPU = false;
    validation_errors res = is_not_valid(&lap);
    if(res){
        errors_output(res);
        return false;
    }
    return true;
}


bool laptop_init(laptop* lap, const char* man, const char* cpu, const bool gpu){
    strcpy(lap->manufacturer, man);
    strcpy(lap->model_CPU, cpu);
    lap->have_GPU = gpu;
    validation_errors res = is_not_valid(&lap);
    if(res){
        errors_output(res);
        return false;
    }
    return true;
}

bool laptop_init_cpy(laptop* lap, const laptop* cpy_lap){
    strcpy(lap->manufacturer, cpy_lap->manufacturer);
    strcpy(lap->model_CPU, cpy_lap->model_CPU);
    lap->have_GPU = cpy_lap->have_GPU;
    validation_errors res = is_not_valid(&lap);
    if(res){
        errors_output(res);
        return false;
    }
    return true;
}

void laptop_output(laptop* lap){
    printf("Manufacturer: %s\n", lap->manufacturer);
    printf("CPU: %s\n", lap->model_CPU);
    printf("Manufacturer: %s\n", lap->have_GPU ? "true" : "false");
}

bool lap_set_CPU(laptop* lap, const char* cpu){
    strcpy(lap->model_CPU, cpu);
    validation_errors res = is_not_valid_cpu(&lap);
    if(res){
        errors_output(res);
        return false;
    }
    return true;
}

bool lap_set_manufacturer(laptop* lap, const char* man){
    strcpy(lap->manufacturer, man);
    validation_errors res = is_not_valid_manufacturer(&lap);
    if(res){
        errors_output(res);
        return false;
    }
    return true;
}

bool lap_set_gpu(laptop* lap, const bool gpu){
    lap->have_GPU = gpu;
    validation_errors res = is_not_valid_gpu(&lap);
    if(res){
        errors_output(res);
        return false;
    }
    return true;
}