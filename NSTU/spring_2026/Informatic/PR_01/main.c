#include <stdio.h>
#include <string.h>

// Передача по значению: v передаётся копией, массив A и j - указатели для изменения
void F18_val(int v, int A[], int *j) {
    int a, n, s, k;
    *j = 0;
    for (a = 10; a < v; a++) {
        // Переворачиваем число a
        for (n = a, s = 0; n != 0; n = n / 10) {
            k = n % 10;
            s = s * 10 + k;
        }
        if (a == s) { // Если число равно перевёрнутому -> палиндром
            A[(*j)++] = a;
        }
    }
}

// Передача по ссылке (через указатели)
void F18_ref(int *v, int A[], int *j) {
    int a, n, s, k;
    *j = 0;
    for (a = 10; a < *v; a++) {
        for (n = a, s = 0; n != 0; n = n / 10) {
            k = n % 10;
            s = s * 10 + k;
        }
        if (a == s) {
            A[(*j)++] = a;
        }
    }
}

// Передача по указателю (массив как указатель)
void F18_pointer(int *v, int *A, int *j) {
    int a, n, s, k;
    *j = 0;
    for (a = 10; a < *v; a++) {
        for (n = a, s = 0; n != 0; n = n / 10) {
            k = n % 10;
            s = s * 10 + k;
        }
        if (a == s) {
            *(A + (*j)++) = a;
        }
    }
}

void F24_val(int n, int A[], int B[]) {
    int i, j, m, s;
    for (j = 0, i = 0; i < n; i++) {
        for (s = 0, m = 2; m < A[i]; m++) {
            if (A[i] % m == 0) {
                s = 1;
                break;
            }
        }
        if (s == 0) {
            B[j++] = A[i];
        }
    }
    B[j] = 0;
}

void F24_ref(int *n, int A[], int B[]) {
    int i, j, m, s;
    for (j = 0, i = 0; i < *n; i++) {
        for (s = 0, m = 2; m < A[i]; m++) {
            if (A[i] % m == 0) {
                s = 1;
                break;
            }
        }
        if (s == 0) {
            B[j++] = A[i];
        }
    }
    B[j] = 0;
}

void F24_pointer(int *n, int *A, int *B) {
    int i, j, m, s;
    for (j = 0, i = 0; i < *n; i++) {
        for (s = 0, m = 2; m < *(A + i); m++) {
            if (*(A + i) % m == 0) {
                s = 1;
                break;
            }
        }
        if (s == 0) {
            *(B + (j++)) = *(A + i);
        }
    }
    *(B + j) = 0;
}

int F31_val(int n, int c[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (c[i] == c[j]) {
                return i;
            }
        }
    }
    return -1;
}

int F31_ref(int *n, int c[]) {
    int i, j;
    for (i = 0; i < *n - 1; i++) {
        for (j = i + 1; j < *n; j++) {
            if (c[i] == c[j]) {
                return i;
            }
        }
    }
    return -1;
}

int F31_pointer(int *n, int *c) {
    int i, j;
    for (i = 0; i < *n - 1; i++) {
        for (j = i + 1; j < *n; j++) {
            if (*(c + i) == *(c + j)) {
                return i;
            }
        }
    }
    return -1;
}

void F48_val(int n, int A[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1]) {
            for (j = i; j < n - 2; j++) {
                A[j] = A[j + 2];
            }
            n = n - 2;
            i--;
        }
    }
}

void F48_ref(int *n, int A[]) {
    int i, j;
    for (i = 0; i < *n - 1; i++) {
        if (A[i] == A[i + 1]) {
            for (j = i; j < *n - 2; j++) {
                A[j] = A[j + 2];
            }
            *n = *n - 2;
            i--;
        }
    }
}

void F48_pointer(int *n, int *A) {
    int i, j;
    for (i = 0; i < *n - 1; i++) {
        if (*(A + i) == *(A + i + 1)) {
            for (j = i; j < *n - 2; j++) {
                *(A + j) = *(A + j + 2);
            }
            *n = *n - 2;
            i--;
        }
    }
}

int F56_val(int A[]) {
    int i, s = 0;
    for (i = 1; i < 10; i++) {
        if (A[i] > 0 && A[i - 1] < 0) {
            s++;
        }
    }
    return s;
}

int F56_ref(int A[]) {
    int i, s = 0;
    for (i = 1; i < 10; i++) {
        if (A[i] > 0 && A[i - 1] < 0) {
            s++;
        }
    }
    return s;
}

int F56_pointer(int *A) {
    int i, s = 0;
    for (i = 1; i < 10; i++) {
        if (*(A + i) > 0 && *(A + i - 1) < 0) {
            s++;
        }
    }
    return s;
}

void printArray(const char *name, int arr[], int size) {
    printf("%s: [", name);
    for (int i = 0; i < size && arr[i] != 0; i++) { // Останавливаемся на нуле-маркере
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int palindromes1[50], palindromes2[50];
    int count1, count2;
    
    printf("Фрагмент 18: поиск палиндромов в диапазоне [10, v-1]\n");
    F18_val(100, palindromes1, &count1);
    printArray("F18_val(1)", palindromes1, count1);
    F18_val(200, palindromes2, &count2);
    printArray("F18_val(2)", palindromes2, count2);
    
    int v1 = 100, v2 = 200;
    F18_ref(&v1, palindromes1, &count1);
    printArray("F18_ref(1)", palindromes1, count1);
    F18_ref(&v2, palindromes2, &count2);
    printArray("F18_ref(2)", palindromes2, count2);
    
    v1 = 100; v2 = 200;
    F18_pointer(&v1, palindromes1, &count1);
    printArray("F18_pointer(1)", palindromes1, count1);
    F18_pointer(&v2, palindromes2, &count2);
    printArray("F18_pointer(2)", palindromes2, count2);
    
    int src1[] = {10, 11, 13, 15, 17, 19, 21, 23, 25};
    int src2[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int primes1[20], primes2[20];
    
    printf("\nФрагмент 24: поиск простых чисел в массиве A и запись в B\n");
    
    // Обнуляем массивы перед использованием
    memset(primes1, 0, sizeof(primes1));
    memset(primes2, 0, sizeof(primes2));
    
    F24_val(9, src1, primes1);  // 9 элементов в src1
    printArray("F24_val(1)", primes1, 20);
    
    memset(primes2, 0, sizeof(primes2));
    F24_val(10, src2, primes2);
    printArray("F24_val(2)", primes2, 20);
    
    int n1 = 9, n2 = 10;
    memset(primes1, 0, sizeof(primes1));
    F24_ref(&n1, src1, primes1);
    printArray("F24_ref(1)", primes1, 20);
    
    memset(primes2, 0, sizeof(primes2));
    F24_ref(&n2, src2, primes2);
    printArray("F24_ref(2)", primes2, 20);
    
    n1 = 9; n2 = 10;
    memset(primes1, 0, sizeof(primes1));
    F24_pointer(&n1, src1, primes1);
    printArray("F24_pointer(1)", primes1, 20);
    
    memset(primes2, 0, sizeof(primes2));
    F24_pointer(&n2, src2, primes2);
    printArray("F24_pointer(2)", primes2, 20);
    
    int arr1[] = {1, 2, 3, 4, 5, 3, 6};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int idx;
    int size_arr1 = 7, size_arr2 = 7;
    
    printf("\nФрагмент 31: поиск первого повторяющегося элемента в массиве c\n");
    idx = F31_val(size_arr1, arr1);
    printf("F31_val(1): %d\n", idx);
    idx = F31_val(size_arr2, arr2);
    printf("F31_val(2): %d\n", idx);
    
    idx = F31_ref(&size_arr1, arr1);
    printf("F31_ref(1): %d\n", idx);
    idx = F31_ref(&size_arr2, arr2);
    printf("F31_ref(2): %d\n", idx);
    
    idx = F31_pointer(&size_arr1, arr1);
    printf("F31_pointer(1): %d\n", idx);
    idx = F31_pointer(&size_arr2, arr2);
    printf("F31_pointer(2): %d\n", idx);
    
    int dup1[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 7};
    int dup2[] = {5, 5, 5, 5, 6, 7, 8, 8, 9, 10};
    int len1 = 10, len2 = 10;
    
    printf("\nФрагмент 48: удаление пар одинаковых соседних элементов\n");
    
    // Создаём копии для каждого вызова
    int dup1_val[10], dup2_val[10];
    memcpy(dup1_val, dup1, sizeof(dup1));
    memcpy(dup2_val, dup2, sizeof(dup2));
    
    F48_val(len1, dup1_val);
    printArray("F48_val(1)", dup1_val, 10);
    F48_val(len2, dup2_val);
    printArray("F48_val(2)", dup2_val, 10);
    
    int dup1_ref[10], dup2_ref[10];
    memcpy(dup1_ref, dup1, sizeof(dup1));
    memcpy(dup2_ref, dup2, sizeof(dup2));
    len1 = 10; len2 = 10;
    
    F48_ref(&len1, dup1_ref);
    printArray("F48_ref(1)", dup1_ref, len1);
    F48_ref(&len2, dup2_ref);
    printArray("F48_ref(2)", dup2_ref, len2);
    
    int dup1_ptr[10], dup2_ptr[10];
    memcpy(dup1_ptr, dup1, sizeof(dup1));
    memcpy(dup2_ptr, dup2, sizeof(dup2));
    len1 = 10; len2 = 10;
    
    F48_pointer(&len1, dup1_ptr);
    printArray("F48_pointer(1)", dup1_ptr, len1);
    F48_pointer(&len2, dup2_ptr);
    printArray("F48_pointer(2)", dup2_ptr, len2);
    
    int sign1[] = {-3, 2, -1, 4, -5, 6, -7, 8, -9, 10};
    int sign2[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    
    printf("\nФрагмент 56: подсчёт пар соседних элементов (отрицательный-положительный)\n");
    printf("F56_val(1): %d\n", F56_val(sign1));
    printf("F56_val(2): %d\n", F56_val(sign2));
    printf("F56_ref(1): %d\n", F56_ref(sign1));
    printf("F56_ref(2): %d\n", F56_ref(sign2));
    printf("F56_pointer(1): %d\n", F56_pointer(sign1));
    printf("F56_pointer(2): %d\n", F56_pointer(sign2));
    
    return 0;
}