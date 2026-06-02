#include <stdio.h>
#include <stdlib.h>


int to_digit(char* str, int* i){
  int res = -1, t = 1;
  for(;str[*i] >= 48 && str[*i] <= 57 && str[*i] != '\0';  (*i)++){
    res *= t;
    if(res == -1) {
        res = 0;
        t = 10;
    }
    res += str[*i] - 48;
  }
  return res;
}

int my_strlen(char* str){
    int counter = 0;
    while(*str++){
        counter++;
    }
    return counter;
}

char* index_strcpy(char* str, int ind1, int ind2){
    int len = ind2 - ind1 + 1;
    char* substr = (char*)malloc(sizeof(char) * (len + 1));
    for(int i = 0; ind1 <= ind2; ind1++, i++){
        substr[i] = str[ind1]; 
    }
    substr[len] = '\0';
    return substr;
}

char* str_repeat(char* str){
    int numb1 = 0, numb2 = 0, ind1 = 0, ind2 = 0, fl = 0;
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 48 && str[i] <= 57){
            ind1 = i;
            numb1 = to_digit(str, &i);
            if(str[i] == 44) i++;
            else continue;
            if(str[i] >= 48 && str[i] <= 57){
                numb2 = to_digit(str, &i);
                ind2 = i;
                fl = 1;
            }
        }
    }
    if(fl){
        char* substr = index_strcpy(str, ind2, ind2 + numb2 - 1);
        int new_len = my_strlen(str) - (ind2 - ind1) + (numb1 * numb2);
        char* res = (char*)malloc(sizeof(char) * (new_len + 1));
        int res_idx = 0; 
        for (int i = 0; i < ind1; i++) {
            res[res_idx++] = str[i];
        }
        for (int j = 0; j < numb1; j++) {
            for (int k = 0; k < numb2; k++) {
                res[res_idx++] = substr[k];
            }
        }
        for (int i = ind2 + numb2; str[i] != '\0'; i++) {
            res[res_idx++] = str[i];
        }
        res[res_idx] = '\0'; 
        free(substr);
        return res;
    }
    return str;
}

int main(){
    char str[] = "aaa4,3abcdef";
    char* result = str_repeat(str);
    printf("%s\n", result);
    free(result);
    return 0;
}