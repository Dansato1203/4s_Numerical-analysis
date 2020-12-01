#include <stdio.h>

int main(){
  int i, j, tmp0, tmp1, tmp2, alpha[27] = {};
  int num = 0;
  FILE *fp;
  char str;
  char low[27], up[27];
  char a = 0x61, A = 0x41;
  char output_text[81] = {"random.txt"};

  fp = fopen(output_text, "r");

  if(fp == NULL){
    printf("file open error\n");
    return -1;
  }

  for(i = 0;i < 26;i++){
    low[i] = a;
    up[i] = A;
    a++;
    A++;
  }
  low[26] = 0x20;
  up[26] = 0x20; 
    

  while((str = fgetc(fp)) != EOF){
    if(str >= 0x61 && str <= 0x7A){
      alpha[(int)str - 0x61]++;
      num++;
    }
    if(str >= 0x41 && str <= 0x5A){
      alpha[(int)str - 0x41]++;
      num++;
    }
    if(str == 0x20){
      alpha[26]++;
      num++;
    }
      i++;
  }

  for (i=0; i<27; ++i) {
    for (j=i+1; j<27; ++j) {
      if (alpha[i] < alpha[j]) {
        tmp0 =  alpha[i];
        tmp1 = low[i];
        tmp2 = up[i];
        alpha[i] = alpha[j];
        low[i] = low[j];
        up[i] = up[j];
        alpha[j] = tmp0;
        low[j] = tmp1;
        up[j] = tmp2;
      }
    }
  }


  printf("Frequency of appearance\n");

  for(i = 0;i < 27;i++){
    printf("[No.%d] %c,%c :%d\n", i+1, low[i], up[i], alpha[i]);
  }
  
  printf("Total number of characters: %d\n", num);

  fclose(fp);
  
  return 0;
}
