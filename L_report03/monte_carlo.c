#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double circle(double x, double y){
  return (x - 0.5)*(x - 0.5) + (y - 0.5)*(y - 0.5);
  }

int main(){
  int i, n;
  int count;
  double x, y, radius, area, pi;
  double final_area, final_pi;

  printf("何回試行する？ ==>");
  scanf("%d", &n);

  srand((unsigned int)time(NULL));

  for(i = 1; i <= n; i++){
    x = rand()/(double)RAND_MAX;
    y = rand()/(double)RAND_MAX;

  radius = 0.5*0.5;

    if((circle(x, y)) <= radius){
      count++;
    }

    area = (double)count / (double)i;
    pi = area / radius;

    printf("[round: %d] pi = %f\n", i, pi);

    }

    final_area = (double)count / (double)n;
    final_pi = final_area / radius;

    printf("\npi = %lf\n", final_pi);

    return 0;
}

