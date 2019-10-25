//  main.c
//  spiral
//  Copyright © 2018 Kunwar Saaim. All rights reserved.
#include <stdio.h>
#include "stdlib.h"

int main(void) {
    int **a,i,j,n,count=0;
    int start,end;
    printf("Enter order of matrix : ");
    scanf("%d",&n);
    a = (int **)malloc(n*sizeof(int));
    for (i=0; i<n; i++) {
        *(a+i) = (int *)malloc(n*sizeof(int));
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            // printf("enter a[%d][%d] :",i,j);
            //scanf("%d",(*(a+i)+j));
            *(*(a+i)+j) = ++count;
        }
    }
    printf("The matrix is : \n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d\t",*(*(a+i)+j));
        }
        printf("\n");
    }
    printf("\n");
    for (start=0, end = n-1;start<=end; start++,end--) {
        for (i=start; i<=end; i++)
            printf("%d\t",*(*(a+start)+i));
        
        for (i=start+1; i<=end; i++)
            printf("%d\t",*(*(a+i)+end));
        
        for (i=end-1; i>=start; i--)
            printf("%d\t",*(*(a+end)+i));
        
        for (i=end-1; i>=start+1; i--)
            printf("%d\t",*(*(a+i)+start));
    }
    printf("\n");
    return 0;
}
