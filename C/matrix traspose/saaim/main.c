//
//  main.c
//  saaim
//
//  Created by Kunwar Rehan on 08/08/18.
//  Copyright © 2018 Kunwar Saaim. All rights reserved.
//

#include <stdio.h>
#define row 3
#define col 4
int main(void){
    int mat1[row][col],mat2[col][row];
    int i,j;
    printf("enter matrix mat1(%dx%d)row-wise :\n",row,col);
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            scanf("%d",&mat1[i][j]);
        }
    }
    for (i=0; i<col; i++) {
        for (j=0; j<row; j++) {
            mat2[i][j] = mat1[j][i];
            
        }
    }
    printf("the transpose of matrix is :\n");
    for (i=0; i<col; i++) {
        for (j=0; j<row; j++) {
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
