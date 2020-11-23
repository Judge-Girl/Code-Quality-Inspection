#include <stdio.h>
#include <string.h>
typedef long long int ll;

void character_to_bits(char c, ll *output, int count)
{
    int num = (int)c;
    for (int i = 0; i < 8; i++)
    {
        if (num & (1 << (7-i)))
            *output |= (1LL << (63-count-i));
    }
    return;
}
void string_to_array(char *str)
{
    ll array[12500] = {0};
    int size = 0;
    int count = 64;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (count >= 64)
        {
            size++;
            count = 0;
        }
        character_to_bits(str[i], &array[size-1], count);
        count += 8;

    }
    for (int i = 0; i < size; i++)
        printf("%lld\n", array[i]);
    return;
}
void bits_to_character(char *str, ll input, int *size)
{
    ll num = 0;
    int count = 0;
    while (count <= 63)
    {
        if (input & (1LL << (63-count)))
            num |= (1 << ((63-count)%8));
        if ((63-count)%8 == 0)
        {
            str[*size] = (char)num;
            (*size)++;
            if (num == 0)
                break;
            else
                num = 0;
        }
        count++;
    }
    return;
}
void array_to_string(ll array[12500], int n)
{
    char str[100000];
    int size = 0;
    for (int i = 0; i < n; i++)
        bits_to_character(str, array[i], &size);
    printf("%s\n", str);
    return;
}
int main(void)
{
    int t;
    scanf("%d", &t);
    if (t == 0)
    {
        char str[100000];
        scanf("%s", str);
        string_to_array(str);
    }
    if (t == 1)
    {
        int n;
        ll array[12500];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &array[i]);
        array_to_string(array, n);
    }
    return 0;
}

