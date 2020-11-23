#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int task;
    scanf("%d", &task);

    if (task) {
        int N;
        scanf("%d", &N);
        char c;
        long long array[N];
        for (int i = 0; i < N; i++) {
            scanf("%lld", &array[i]);
            for (int j = 0; j < 8; j++) {
                c = array[i] >> 7*8;
                if (c != '\0') {
                    printf("%c", c);
                }
                else
                    break;
                array[i] = array[i] << 8;
            }
        }


    }
    else {
        char string[100000];
        scanf("%s", string);
        long long number = 0;
        char * ptr = string;
        int count = 0;
        while (*ptr != '\0') {
            number = *ptr | number;
            count++;
            if (count == 8) {
                printf("%lld\n", number);
                number = 0;
                count = 0;
            }

            number = number << 8;
            ptr++;
        }

        if (count < 8) {
            number = number << 8 * (7 - count);
            printf("%lld\n", number);
        }

    }
    return 0;
}

