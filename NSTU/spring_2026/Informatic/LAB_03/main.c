#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arr_fill(int* arr, int len){
    for(int i = 0; i < len; arr[i++] = rand() % 50000);
}

void arr_output(int* arr, int len){
    for(int i = 0; i < len; printf("%d ", arr[i++]));
    printf("\n");
}

int bubble_sort(int* arr, int len){
    int c = 0; 
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            c++;
             if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return c;
}


int sort(int* arr, int len, int step){
    int j, c = 0;
    for(int k = 0; k < step; ++k){
        int min = arr[0], max = arr[0];
        for(int i = 0; i < len; i++){
            c++;
            if(min > arr[i]) min = arr[i];
            c++;
            if(max < arr[i]) max = arr[i];
        }
        if(min == max) break;
        for(int i = 0; i < len; i++){
            j = (arr[i] - min) * (len - 1) / (max - min);
            if(j > i){
                c++;
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp; 
                }
            }    
            else if(j < i){
                c++;
                if(arr[i] < arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp; 
                }
            }    
        }
    }
    c += bubble_sort(arr, len);
    return c;
}

void run(int N, int M){
    int* arr = (int*)malloc(sizeof(int) * N);

    arr_fill(arr, N);

    int c = sort(arr, N, M);

    printf("N = %d, comps = %d\n", N, c);

    free(arr);
}


int main(){
    srand(time(NULL));
    run(1000, 3);
    run(5000, 3);
    run(10000, 3);
    return 0;
}