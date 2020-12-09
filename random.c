#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define C 100000
#define M 10

int main(){
  int i, x;
  srand((unsigned)time(NULL));
  for(i = 0; i < C; i++){
    x =(int)( rand() / (double)RAND_MAX * M );
    printf("%d\n", x);
  }
  return 0;
}
