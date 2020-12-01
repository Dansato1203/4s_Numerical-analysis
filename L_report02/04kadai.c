#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int num = 0, cou = 0;
  int c, i, k;
  FILE *rp, *wp;
  char output_text[81] = {"output.txt"};
  char random_text[81] = {"random.txt"};
  char str;

  srand((unsigned int)time(NULL));

  rp = fopen(output_text, "r");
  wp = fopen(random_text, "w");

  if(rp == NULL || wp == NULL){
    printf("file open error\n");
    return -1;
  }

  while(1){
    c = fgetc(rp);
    if(c == EOF){
      break;
    }
    if(c != '\n'){
    num++;
    }
  }
  
  printf("Total number of characters: %d\n", num);
  printf("-- 1st approximation -- \n");
  for(i = 0;i < 101;i++){
    rewind(rp);
    k = rand() % num + 1;
    while((str = fgetc(rp)) != EOF){
      if(cou == k){
       printf("%c", str);
       fprintf(wp, "%c", str);
      }
     cou++;
    }
    cou = 0;
  }
      
  printf("\n");

  fclose(wp);
  fclose(rp);
  return 0;
}
