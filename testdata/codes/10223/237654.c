#include <stdio.h>
#include <string.h>

int main()
{
    char str[10001], mark_i[10001], mark_j[10001], mark_o[10001];
    int i, j;
    while ( scanf("%s%d%d", str, &i, &j) != EOF ) {
        int count = 0, k;
        for ( k = 0; str[k] != '\0'; k++) {
            mark_i[k] = count == i ? str[k] : '+';
            mark_j[k] = count == j ? str[k] : '+';
            mark_o[k] = (count != i && count != j) ? str[k] : '+';
            if ( str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u' )
                count++;
        }
        mark_i[k] = mark_j[k] = mark_o[k] = '\0';
        printf("%s\n%s\n%s\n", mark_i, mark_j, mark_o);
    }
    return 0;
}
