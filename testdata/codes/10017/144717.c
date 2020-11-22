#include<stdio.h>

int my_abs(int x){
  if(x >= 0){
    return x;
  }
  else{
    return -x;
  }
}

int ax[50000], ay[50000], bx[50000], by[50000];

int main(void){
  int n;
  int amin = -1, bmin = -1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
  }
  for(int i = 0; i < n; i++){
    for(int j = i - 1; j >= 0; j--){
      if(j == i - 1){
        amin = my_abs(ax[i] - bx[j]) + my_abs(ay[i] - by[j]);
      }
      if(my_abs(ax[i] - bx[j]) + my_abs(ay[i] - by[j]) < amin){
        amin = my_abs(ax[i] - bx[j]) + my_abs(ay[i] - by[j]);
      }
    }
    for(int k = i; k >= 0; k--){
      if(k == i){
        bmin = my_abs(bx[i] - ax[k]) + my_abs(by[i] - ay[k]);
      }
      if(my_abs(bx[i] - ax[k]) + my_abs(by[i] - ay[k]) < bmin){
        bmin = my_abs(bx[i] - ax[k]) + my_abs(by[i] - ay[k]);
      }
    }
    if(amin > 0){
      printf("%d\n", amin);
    }
    printf("%d\n", bmin);
  }
}

