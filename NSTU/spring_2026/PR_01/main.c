#include <stdio.h>
#include "laptop.h"

int main(){
    laptop lap1;
    laptop_init(&lap1, "Sus", "INTEL", true);
    laptop lap2;
    laptop_init_default(&lap2);
    laptop_output(&lap1);
    laptop_output(&lap2);
    laptop_init_cpy(&lap2, &lap1);
    lap_set_manufacturer(&lap1, "HP");
    laptop_output(&lap1);
    laptop_output(&lap2);
    printf("--------------------------------------------------\n");
    laptop* lap1_dyn = create_laptop(&lap1_dyn);
    laptop_init(lap1_dyn, "Sus", "INTEL", true);
    laptop* lap2_dyn = create_laptop(&lap2_dyn);
    laptop_init_default(lap2_dyn);
    laptop_output(lap1_dyn);
    laptop_output(lap2_dyn);
    laptop_init_cpy(lap2_dyn, lap1_dyn);
    lap_set_manufacturer(lap1_dyn, "HP");
    laptop_output(lap1_dyn);
    laptop_output(lap2_dyn);
    free_laptop(lap1_dyn);
    free_laptop(lap2_dyn);




    return 0;
}