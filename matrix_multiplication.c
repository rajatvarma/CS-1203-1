#include <stdio.h>

int main(){
    int c[3][3];

    int a[3][3] = {{1, 2, 3}, {2, 3, 2}, {3, 2, 1}};
    int b[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] = a[i][k]*b[k][j];
            }

        }
    }

    for(int i=0; i<3; i++) {    
        for(int j=0; j<3; j++) {    
            printf("%d\t",c[i][j]);
        }    
        printf("\n");    
    }    
    return 0;  
}