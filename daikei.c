#include <stdio.h>
#include <math.h>

double f (double x){
  return 1 / x;
}

double daikei(double a, double b, int n){
  double delta = (b - a) / n;
  double x, value;
  int i;
  for(int i=0; i<n; i++) {
    
    // i番目の台形の左下X値
    x = a + i * delta;
    
    // 積分値に i 番目の台形の面積を足す
    value += ( f(x) + f(x+delta) ) * delta / 2.0;
}
  printf("%lf\n", value);
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
   daikei(a, b, n);
   return 0;
 }         
