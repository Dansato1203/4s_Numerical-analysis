#include <stdio.h>
#include <math.h>
#define N 4

int main(void){
  int i, j, k, l, m;
  int flag = 0;
  double x[N][N];
  double y[N][N];
  double diff = 0;

  x[0][0] = -2; x[0][1] = 1; x[0][2] = 4; x[0][3] = 2;
  x[1][0] = 3; x[1][1] = -3; x[1][2] = 3; x[1][3] = 1;
  x[2][0] = 5; x[2][1] = 2; x[2][2] = -2; x[2][3] = 1;

  for(j = 0;j < N;j++){
    i = 1;
    y[i][j] = 0;
  }

  for(i = 0;i < N - 2;i++){
  /*  if(x[i][i] == 0){
      for(l = i + 1; l < N;l++){
        if(x[l][l] != 0){
          for(m = 0;m < N;m++){
            y[i][m] = x[i][m];
            x[i][m] = x[i][l];
            x[l][m] = y[i][m];
          }
          break;
        }
      else if(l == N-1){
        flag = 1;
        printf("解が、、、");
        break;
      }
    }
  }*/
   for (j = i + 1; j < N - 1;j ++) { 
     diff = x[j][i]/x[i][i];
     for (k = i; k < N; k++) {
       x[j][k] -= x[i][k] * diff;
     } 
   }
   if(flag == 1) break;
  }

 for(i = N - 2;i > 0;i--){
   if(flag == 1) break;               
   for(j = i - 1;j >= 0;j--) {
     diff = x[j][i] / x[i][i];      
     for(k = N - 1;k >= 0;k--) {
       x[j][k] -= diff * x[i][k];
     }
   }
 } 
 for(i = 0;i < N - 1;i++) {
  x[i][N-1] /= x[i][i];            
  x[i][i] /= x[i][i]; 
 }
 double a = x[0][3];
 double b = x[1][3];
 double c = x[2][3]; 
 printf("x1 = %f,x2 = %f,x3 = %f\n",a, b, c);
 }                                
  

