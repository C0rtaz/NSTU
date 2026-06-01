// Числовой ребус: ОДИН + ОДИН = МНОГО

#include <stdio.h>

int toDigit(int* A,int a){
    int i,n;
    for (i=0, n=a; n!=0; i++, n=n/10);
    int k=i--;
    for (n=a; n!=0; i--, n=n/10)
        A[i]=n % 10; 
    return k;
}


int main(){
    int vv = 5000;
    int A[4], B[5], M[9];
    for(;vv <= 9999; ++vv){
        toDigit(A, vv);

        for(int i = 0; i < 9; M[i++] = 0);

        int fl = 0;
        for(int j = 0; j < 4; j++){
            int k = A[j];
            if(M[k] != 0){
                fl = 1;
                break;
            }
            else M[k] = 1;
        }
        if(fl) continue;

        toDigit(B, vv * 2);

        if(B[2] != A[0]) continue;
        if(B[4] != A[0]) continue;
        if(B[1] != A[3]) continue;
    
        if(M[B[0]]) continue;
        if(M[B[3]]) continue;

        if(B[0] == B[3]) continue;

        printf("ОДИН = %d; МНОГО = %d\n", vv, vv*2);
        break;
    }

    return 0;
}