#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define MAXN 32
#define STRLEN 32
 
int nameToIndex(char *name, char names[][STRLEN], int N)
{
  for (int i = 0; i < N; i++)
    if (strcmp(name, names[i]) == 0)
      return i;
 
  return -1;
}
 
#define EARNS 0
#define SPENDS 1
#define BECOMES 2
#define GIVES 3
 
int actionToCode(char *action)
{
  char *actions[4] = {"earns", "spends", "becomes", "gives"};
  for (int i = 0; i < 4; i++)
    if (strstr(action, actions[i]) != NULL)
      return i;
 
  return -1;
 
}
 
int main()
{
  int N;
  scanf("%d", &N);
  char names[MAXN][STRLEN];
  int balance[MAXN];
  for (int i = 0; i < N; i++) 
    scanf("%s%d", names[i], &(balance[i]));
 
  char name1[STRLEN], name2[STRLEN];
 
  while (scanf("%s", name1) != EOF) {
    int name1index = nameToIndex(name1, names, N);
    int amount;
    char action[STRLEN], next[STRLEN];
    scanf("%s", action);
    int code = actionToCode(action);
    switch (code) {
    case EARNS:
      scanf("%d", &amount);
      if (name1index >= 0)
    balance[name1index] += amount;
      break;
    case SPENDS:
      scanf("%d", &amount);
      if (name1index >= 0 && balance[name1index] >= amount)
    balance[name1index] -= amount;
      break;
    case BECOMES:
      scanf("%d", &amount);
      if (name1index >= 0)
    balance[name1index] = amount;
      break;
    case GIVES:
      scanf("%s%d", name2, &amount);
      int name2index = nameToIndex(name2, names, N);
      if (name1index>=0&&balance[name1index] >= amount && name2index >= 0) {
    balance[name1index] -= amount;
    balance[name2index] += amount;
      }
      break;
    default:
      scanf("%s", next);
      if (isalpha(next[0]))     /* users */
    scanf("%s", next);    /* skip another string */
      break;
    }
  }
 
  for (int i = 0; i < N; i++)
    printf("%s %d\n", names[i], balance[i]);
  return 0;
}
