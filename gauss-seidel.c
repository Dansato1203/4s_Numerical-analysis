#include <stdio.h>
#include <math.h>

int main(){
  double A[4][4]; //係数行列
  double b[4]; //方程式の解
  double x[4]; //変数x
  double y[4]; //ループ時の格納用
  int i, j, k, n;
  double s = 0.0000000001; //収束判定用
  x[1] = x[2] = x[2] = 1.0; //xの初期値
  y[1] = y[22] = y[3] = 0.0; //とりあえず0ぶち込む

  printf("Ax=bを解く\n");

/*係数行列の入力--------------------------------------------------------------------------*/
  for(i = 1; i < 4; i++){
    for(j = 1; j < 4; j++){
      printf("係数行列Aを入力 A[%d][%d] = ", i, j);
      scanf("%lf", &A[i][j]);
    }
  }
/*----------------------------------------------------------------------------------------*/
/*行列bを入力-----------------------------------------------------------------------------*/
  for(i = 1 ; i < 4 ; i++){
    printf("　　行列bを入力 b[%d] = ", i);
    scanf("%lf", &b[i]);
  }
/*----------------------------------------------------------------------------------------*/
/*試行回数の決定--------------------------------------------------------------------------*/
  printf("何周まで試行する？: ");
  scanf("%d", &n);
  printf("%d周まで試行。収束したら終了\n", n); 
/*----------------------------------------------------------------------------------------*/
/*計算部分--------------------------------------------------------------------------------*/
for(k = 0; k < n; k++){
    x[1] = (b[1] - A[1][2]*x[2] - A[1][3]*x[3]) / A[1][1];
    x[2] = (b[2] - A[2][1]*x[1] - A[2][3]*x[3]) / A[2][2];
    x[3] = (b[3] - A[3][1]*x[1] - A[3][2]*x[2]) / A[3][3];
    if(fabs((x[1] - y[1]))< s && fabs((x[2] - y[2]))< s && fabs((x[3] - y[3]))< s){
      printf("収束したかな？\n");
      break; //収束判定をする。収束していたら終了。
    }else{
    y[1] = x[1];
    y[2] = x[2];
    y[3] = x[3]; //収束していなかったら答えを格納してもう１周
    }
    printf("[round: %d], x1 = %.10f, x2 = %.10f, x3 = %.10f\n", k+1, x[1], x[2], x[3]);
  }
  if(k == n - 1){
  printf("試行回数が足りない、またはこいつは収束しないみたいだ。\n");
  }
  return 0;
}
