cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)

add_executable(laptop
    laptop.c
    main.c
)

target_compile_options(laptop PRIVATE
    -Wall    
    -Wextra  
    -Werror  
)