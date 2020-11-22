#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tonumber(char *s)
{
  int sum = 0;
  int l = strlen(s);
  for (int i = 0; i < l; i++) {
    sum *= 10;
    sum += (s[i] - '0');
  }
  return sum;
}
int valid_name(char *s, char userNmae[32][32])
{
  int i;
  for (i = 0; i < 32; i++) {
    if (strcmp(s, userNmae[i]) == 0)
      return i;
  }
  return -1;
}
int decide_op(char *s)
{
  if (strstr(s, "earns") != NULL)
    return 1;
  if (strstr(s, "spends") != NULL)
    return 2;
  if (strstr(s, "gives") != NULL)
    return 3;
  if (strstr(s, "becomes") != NULL)
    return 4;
  return 0;
}

void deal_ins(char userName[32][32], int balance[32])
{
  char de[2];
  de[0] = ' ';
  de[1] = '\0';
  char file[4][32];
  char ins[128];
  scanf("%c", &(ins[0]));
  while (scanf("%c", &(ins[0])) != EOF) {
    for (int i = 1; i < 128; i++) {
      scanf("%c", &(ins[i]));
      if (ins[i] == '\n' || ins[i] == '\0') {
        ins[i] = '\0';
        break;
      }
    }
    char *ptr = ins;
    ptr = strtok(ptr, de);
    int len;
    for (len = 0; ptr != NULL; len++) {
      strcpy(file[len], ptr);
      ptr = strtok(NULL, de);
    }
    int p1 = valid_name(file[0], userName);
    if (p1 < 0)
      continue;
    int op = decide_op(file[1]);
    int amount;
    if (op == 0)
      continue;
    int p2 = -1;
    if (op == 3) {
      amount = tonumber(file[3]);
      p2 = valid_name(file[2], userName);
      if (p2 < 0)
        continue;
    } else
      amount = tonumber(file[2]);
     switch (op) {
     case 1:
       balance[p1] += amount;
       break;
     case 2:
       if (balance[p1] >= amount)
         balance[p1] -= amount;
       break;
     case 3:
       if (balance[p1] >= amount) {
         balance[p1] -= amount;
         balance[p2] += amount;
       }
       break;
     case 4:
       balance[p1] = amount;
       break;
     default:
        printf("wrong");
     }
  }
}

int main()
{
  char userName[32][32];
  int balance[32];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s%d", userName[i], &(balance[i]));
  deal_ins(userName, balance);
  for (int i = 0; i < n; i++)
    printf("%s %d\n", userName[i], balance[i]);
  return 0;
}

