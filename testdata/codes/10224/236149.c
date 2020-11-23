#include <stdio.h>
#include <string.h>

typedef struct {
  char name[35];
  int balance;
} Datum;

int Index(Datum data[], int n, char *name) {
  for (int i = 0; i < n; ++i)
    if (strcmp(data[i].name, name) == 0) return i;
  return -1;
}

enum {
  EARNS,
  SPENDS,
  GIVES,
  BECOMES
};

int Convert(char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    for (int checkLen = 5; checkLen <= len - i; ++checkLen) {
      if (strncmp(s + i, "earns", checkLen) == 0) return EARNS;
      if (strncmp(s + i, "spends", checkLen) == 0) return SPENDS;
      if (strncmp(s + i, "gives", checkLen) == 0) return GIVES;
      if (strncmp(s + i, "becomes", checkLen) == 0) return BECOMES;
    } 
  }
  return -1;
}

int Number(char *s) {
  int len = strlen(s);
  int num = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] >= '0' && s[i] <= '9') return -1; 
    num = num * 10 + s[i] - '0';
  }
  return num;
}

int main() {
#ifdef DEBUG
  // Unit testing function "Convert"
  printf("learns should be 0, is %d\n", Convert("learns"));
  printf("suspends should be 1, is %d\n", Convert("spends"));
  printf("forgives should be 2, is %d\n", Convert("forgives"));
  printf("bebecomesout should be 3, is %d\n", Convert("bebecomesout"));
  printf("borrows should be -1, is %d\n", Convert("borrows"));
#endif

  Datum data[35] = {0};
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s%d", data[i].name, &data[i].balance);

  char instruction[35];
  while (scanf("%s", instruction) != EOF) {
    int idx = Index(data, n, instruction);
    if (idx == -1) continue;
    scanf("%s", instruction);
    int num, idx2;
    switch (Convert(instruction)) {
    case EARNS:
      scanf("%d", &num);
      data[idx].balance += num;
      break;
    case SPENDS:
      scanf("%d", &num);
      if (data[idx].balance >= num) data[idx].balance -= num;
      break;
    case GIVES:
      scanf("%s%d", instruction, &num);
      idx2 = Index(data, n, instruction);
      if (idx2 != -1 && data[idx].balance >= num) {
        data[idx].balance -= num;
        data[idx2].balance += num;
      }
      break;
    case BECOMES:
      scanf("%d", &num);
      data[idx].balance = num;
      break;
    }
  }

  for (int i = 0; i < n; ++i)
    printf("%s %d\n", data[i].name, data[i].balance);
}


