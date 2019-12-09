#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include "laplace2d.h"
#include <sys/time.h>


#define SIZE 4000

double a[SIZE][SIZE];
double b[SIZE][SIZE];
double c[SIZE][SIZE];
double d[SIZE][SIZE];

int main()
{
  int i,j,k;
  double tmp;

  
  // Initialize matrices.
  for (i = 0; i < SIZE; ++i) {
    for (j = 0; j < SIZE; ++j) {
      a[i][j] = (double)(i + j);
      b[i][j] = (double)(i - j);
      c[i][j] = 0.0f;
      d[i][j] = 0.0f;
    }
  }



    long double time_spent = 0.000000;

    clock_t begin = clock();
    
  // Compute matrix multiplication.
#pragma acc data copyin(a,b) copy(c)
#pragma acc kernels
#pragma acc loop tile(32,32)
  for (i = 0; i < SIZE; ++i) {
    for (j = 0; j < SIZE; ++j) {
      tmp=0.0f;
#pragma acc loop reduction(+:tmp)
      for (k = 0; k < SIZE; ++k) {
        tmp += a[i][k] * b[k][j];
      }
      c[i][j] = tmp;
    }
  }
     clock_t end = clock();
    
    time_spent += (long double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time elpased is %Lf seconds",(long double) time_spent);
    
#ifdef CHECK
  // ****************
  // double-check the OpenACC result 
  // ****************
#pragma omp parallel for default(none) shared(a,b,d) private(i,j,k)
  for (i = 0; i < SIZE; ++i) 
    for (j = 0; j < SIZE; ++j) 
      for (k = 0; k < SIZE; ++k) 
    d[i][j] += a[i][k] * b[k][j];
 
  // Check the OpenACC matrix
  for (i = 0; i < SIZE; ++i)
    for (j = 0; j < SIZE; ++j)
      if(c[i][j] != d[i][j]) {
    printf("Error %d %d %f %f \n", i,j, c[i][j], d[i][j]);
    exit(1);
      }
  printf("OpenACC matrix multiplication test was successful!\n");
#endif
  
  return 0;
}
