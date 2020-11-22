#include <stdio.h>
#include <string.h>

int main()
{
    char str[10001];
    char mark_i[10001], mark_j[10001], mark_o[10001];
    int i, j;
    while ( scanf("%s%d%d", str, &i, &j) != EOF ) {
        int count = 0, k;
        for ( k = 0; str[k] != '\0'; k++) {
            if ( count == i ) {
                mark_i[k] = str[k];
            } else {
                mark_i[k] = '+';
            }
            if ( count == j ) {
                mark_j[k] = str[k];
            } else {
                mark_j[k] = '+';
            }
            if ( count != i && count != j ) {
                mark_o[k] = str[k];
            } else {
                mark_o[k] = '+';
            }
            if ( str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u' ) {
                count++;
            }
        }
        mark_i[k] = mark_j[k] = mark_o[k] = '\0';
        printf("%s\n%s\n%s\n", mark_i, mark_j, mark_o);
    }
    return 0;
}
