#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 

void main(){
    int tid;
    int i,j;
    int rows, cols;
    printf("Please enter the number of rows of matrices: ");
    scanf("%d",&rows);
    printf("Please enter the number of cols of matrices: ");
    scanf("%d",&cols);

    int a[rows][cols];
    int b[rows][cols];
    int c[rows][cols];

    int *d, *e, *f;

    printf("Enter %d elements of first matrix: ", rows*cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter %d elements of second matrix: ", rows*cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d", &b[i][j]);
        }
    }

    d = (int *)malloc(sizeof(int)*rows*cols);
    e = (int *)malloc(sizeof(int)*rows*cols);
    f = (int *)malloc(sizeof(int)*rows*cols);

    d = (int *)a;
    e = (int *)b;
    f = (int *)c;

    #pragma omp parallel num_threads(rows*cols)
    {
        tid = omp_get_thread_num();
        f[tid] = d[tid] + e[tid];
    }

    printf("Values of  Result Matrix A are: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("A[%d][%d] = %d\t", i, j,a[i][j]);
        }printf("\n");
    }
    printf("\nValues of  Result Matrix B are: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("B[%d][%d] = %d\t", i, j,b[i][j]);
        }printf("\n");
    }
    printf("\nValues of  Result Matrix C are: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("C[%d][%d] = %d\t", i, j,c[i][j]);
        }printf("\n");
    }
    
}