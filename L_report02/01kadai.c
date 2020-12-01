#include <stdio.h>

int main(){
  FILE *rp, *wp;
  char str;
  char input_text[81];
  char output_text[81];
  int count;

  printf("Input text_name -->");
  scanf("%s", input_text);
  printf("Output text_name -->");
  scanf("%s", output_text);
 
  rp = fopen(input_text, "r");
  wp = fopen(output_text, "w");

  if(rp == NULL){
    printf("file open error\n");
    return -1;
  }
  if(wp == NULL){
    printf("file open error\n");
    return -1;
  }

  while((str = fgetc(rp)) != EOF){
    if(str >= 0x61 && str <= 0x7a || str >= 0x41 && str <= 0x5a){
      putchar(str);
    }else if(str == 0x20){
      putchar(str);
    }else if(str == 0x0A){
      putchar(str);
      count++;
    }else{
      str = 0x20;
      putchar(str);
    }
    fputc(str, wp);
  }

  fclose(rp);
  fclose(wp);
  printf("\ncomplete!\n");

  return 0;
}
