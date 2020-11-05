#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return cos(x)+x;
}

double d_f(double x){
  return -sin(x)+1;
}

int main(){
  FILE *outputfile;
  int  n_max;
  int n = 0;
  double x, eps, del;

  outputfile = fopen("graph.txt", "w");
  if(outputfile == NULL){
    printf("cannnot open\n");
  }

  printf("初期値x,小さい数eps,最大繰り返し回数n_maxを入力\n");
  printf("x = ");
  scanf("%lf", &x);
  fprintf(outputfile,"%.10lf 0\n", x);
  printf("eps = ");
  scanf("%lf", &eps);
  printf("n_max = ");
  scanf("%d", &n_max);
  
  do {
    del = -f(x) / d_f(x);
    x = x + del;
    n++;
    printf("[round: %d], x = %.10lf\n", n, x);
    fprintf(outputfile, "%.10lf 0\n", x);
  }while(fabs(del) > eps && n <= n_max);

  if(n == n_max){
    printf("失敗。解が見つからない\n");
  }else{
    printf("近似解は%.10lf\n試行回数は%d回\n", x, n);
  }

  return 0;
}
