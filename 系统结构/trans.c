/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
	if(N==32 && M==32){
		int t1,t2,t3,t4,t5,t6,t7,t8;
		int i,j;
		for(i=0;i<M;i+=8){
			for(j=0;j<N;j++){
				t1=A[j][i];
				t2=A[j][i+1];
				t3=A[j][i+2];
				t4=A[j][i+3];
				t5=A[j][i+4];
				t6=A[j][i+5];
				t7=A[j][i+6];
				t8=A[j][i+7];
				B[i][j]=t1;
				B[i+1][j]=t2;
				B[i+2][j]=t3;
				B[i+3][j]=t4;
				B[i+4][j]=t5;
				B[i+5][j]=t6;
				B[i+6][j]=t7;
				B[i+7][j]=t8;
			}
		}
	}else
	if(N==64){
		int t1,t2,t3,t4;
		int i,j,k;
		for(i=0;i<M;i+=4)
			for(j=0;j<N;j+=4)
				for(k=j;k<j+4;k++){
					t1=A[k][i];
					t2=A[k][i+1];
					t3=A[k][i+2];
					t4=A[k][i+3];
					B[i][k]=t1;
					B[i+1][k]=t2;
					B[i+2][k]=t3;
					B[i+3][k]=t4;
				}
	}else{
		int i,j,k,l;
		for(i=0;i<N;i+=16)
			for(j=0;j<M;j+=16)
				for(k=i;k<i+16&&k<N;k++)
					for(l=j;l<j+16&&j<M;l++)
						B[l][k]=A[k][l];
	}
}				
					/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

