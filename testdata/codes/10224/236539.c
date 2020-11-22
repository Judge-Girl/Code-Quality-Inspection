#include <stdio.h>
#include <string.h>

int main(void){
  char user[35][35];
  int balance[35];
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%s", &user[i]);
    scanf("%d", &balance[i]);
  }
  char who[35], whoo[35], ins[35];
  int money;
  while (scanf("%s", &who) != EOF){
    int first = N, second = N;
    for (int i = 0; i < N; i++){
      if (strcmp(user[i], who) == 0){
        first = i;
        break;
      }
    }
    if (first != N){
      scanf("%s", &ins);
      if (strstr(ins, "earns") != NULL){
        scanf("%d", &money);
        balance[first] += money;
      }
      else if (strstr(ins, "spends") != NULL){
        scanf("%d", &money);
        if (balance[first] >= money){
          balance[first] -= money;
        }
      }
      else if (strstr(ins, "becomes") != NULL){
        scanf("%d", &money);
        balance[first] = money;
      }
      else if (strstr(ins, "gives") != NULL){
        scanf("%s", &whoo);
        for (int i = 0; i < N; i++){
          if (strcmp(user[i], whoo) == 0){
            second = i;
            break;
          }
        }
        if (second != N){
          scanf("%d", &money);
          if (balance[first] >= money){
            balance[first] -= money;
            balance[second] += money;
          }
        }
      }
    }
    char c;
    do scanf("%c", &c);
    while (c != '\n');
  }

  for (int i = 0; i < N; i++){
    printf("%s ", user[i]);
    printf("%d\n", balance[i]);
  }


  return 0;
}

