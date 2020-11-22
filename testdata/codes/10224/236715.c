#include <stdio.h>
#include <string.h>

int main()
{
    char username[32][32];
    int money[32] = {};
    char person1[32], command[32], person2[32];
    char trash[128];
    int price = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s%d", username[i], &money[i]);
    }
    while(scanf("%s", person1) != EOF)
    {
        scanf("%s", command);
        int len = strlen(command);
        for(int i = 0; i < len; i++)
        {
            if(command[i] == 'e')
            {
                if(command[i+1] == 'a')
                {
                    if(command[i+2] == 'r')
                    {
                        if(command[i+3] == 'n')
                        {
                            if(command[i+4] == 's') 
                            {
                                strcpy(command, "earns");
                                break;
                            }
                        }
                    }
                }
            }
            if(command[i] == 's')
            {
                if(command[i+1] == 'p')
                {
                    if(command[i+2] == 'e')
                    {
                        if(command[i+3] == 'n')
                        {
                            if(command[i+4] == 'd')
                            {
                                if(command[i+5] == 's') 
                                {
                                    strcpy(command, "spends");
                                    break;
                                }
                            }

                        }
                    }
                }
            }
            if(command[i] == 'g')
            {
                if(command[i+1] == 'i')
                {
                    if(command[i+2] == 'v')
                    {
                        if(command[i+3] == 'e')
                        {
                            if(command[i+4] == 's')
                            {
                                strcpy(command, "gives");
                                break;
                            }
                        }
                    }
                }
            }
            if(command[i] == 'b')
            {
                if(command[i+1] == 'e')
                {
                    if(command[i+2] == 'c')
                    {
                        if(command[i+3] == 'o')
                        {
                            if(command[i+4] == 'm')
                            {
                                if(command[i+5] == 'e')
                                {
                                    if(command[i+6] == 's') 
                                    {
                                        strcpy(command, "becomes");
                                        break;
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
        // if(!(strcmp(command, "earns") == 0 || strcmp(command, "spends") == 0 || strcmp(command, "gives") == 0 || strcmp(command, "becomes") == 0))
        //     continue;
        if(strcmp(command, "earns") == 0)
        {
            scanf("%d", &price);
            for(int i = 0; i < n; i++)
            {
                if(strcmp(person1, username[i]) == 0)
                {
                    money[i] += price;
                } 
            }
        }
        else if(strcmp(command, "spends") == 0)
        {
            scanf("%d", &price);
            for(int i = 0; i < n; i++)
            {
                if(strcmp(person1, username[i]) == 0)
                {
                    if(price > money[i]) break;
                    else money[i] -= price;
                } 
            }
        }
        else if(strcmp(command, "gives") == 0)
        {
            scanf("%s%d", person2, &price);
            for(int i = 0; i < n; i++)
            {
                if(strcmp(person1, username[i]) == 0)
                {
                    if(price > money[i]) break;
                    for(int j = 0; j < n; j++)
                    {
                        if(strcmp(person2, username[j]) == 0)
                        {
                            money[i] -= price;
                            money[j] += price;
                        }
                    }
                } 
            }
        }
        else if(strcmp(command, "becomes") == 0)
        {
            scanf("%d", &price);
            for(int i = 0; i < n; i++)
            {
                if(strcmp(person1, username[i]) == 0)
                {
                    money[i] = price;
                } 
            }
        }
        else fgets(trash, 128, stdin);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%s %d\n", username[i], money[i]);
    }
    return 0;
}
