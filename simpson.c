#include <stdio.h>
#include <math.h>

double f(double x){
  return 1 / x;
}

double simpson(double a, double b, int n){
  double delta = (b - a) / n;
  double x, y;
  x = f(a);
  x += f(a + delta * n);
  int i;
  for(i=1; i<n; i+=2){
      x += 4.0 * f(a + delta * i);
  }
  for(i=2; i<n; i+=2){
      x += 2.0 * f(a + delta * i);
  }

  y = x*delta/3.0;
  printf("%lf\n", y);
  return 0;
}

int main(){
  double a, b;
  int n;
  printf("区間[a,b]を入力\n");
  printf("a : ");
  scanf("%lf", &a);
  printf("b : ");
  scanf("%lf", &b);
  printf("分割数nを入力\n");
  printf("n : ");
  scanf("%d", &n);
  simpson(a, b, n);
  return 0;
}
