#include <stdio.h>
#include <math.h>

#define N 100 //分割数

double f(double x);
double y_true(double x);

int main(void){
  //初期値
  double x=1.0;
  double y=f(x);
  double h = 1.0;
  int i = 0;

  printf("%d, %5.5lf, %5.5lf\n",i+1,x,y);
  
  for(i = 1; i < 10; i++){
    y = y + h*f(x);
    x = x + h;
    printf("%d, %5.5lf, %5.5lf\n",i+1,x,y);
  }
}

double f(double x){
  return 2*x;
}
