#include<stdio.h>
#include<string.h>
struct bank{
    char username[32];
    int money;
};
struct bank bank1[32];
int i , j;
int findperson(int num,char target[])
{
    for(i = 0 ; i < num ; i++)
    {
        if(strcmp(target,bank1[i].username)==0)
            return i;
    }
    return -1;
}
int main()
{
    int num;
    scanf("%d",&num);
    for(i = 0 ; i < num ; i++)
    {
        scanf("%s%d",bank1[i].username,&bank1[i].money);
    }
    char target[32],command[32];
    int amount;
    while(scanf("%s%s",target,command)!=EOF)
    {
        int id = findperson(num,target);
        char *ptr1 = strstr(command,"earns");
        char *ptr2 = strstr(command,"spends");
        char *ptr3 = strstr(command,"gives");
        char *ptr4 = strstr(command,"becomes");
        if(ptr1!=NULL)
        {
            scanf("%d",&amount);
            if(id==-1)
                continue;
            else
            {
                bank1[id].money += amount;
            }
        }
        else if(ptr2!=NULL)
        {
            scanf("%d",&amount);
            if(id == -1 )
                continue;
            else
            {
                if(bank1[id].money >= amount)
                    bank1[id].money -= amount;
            }
 
        }
        else if(ptr3!=NULL)
        {
            char target1[32];
            scanf("%s%d",target1,&amount);
            int id1 = findperson(num,target1);
            if(id == -1 || id1 ==-1 )
                continue;
            else
            {
                if(bank1[id].money >= amount)
                {
                    bank1[id].money -= amount;
                    bank1[id1].money += amount;
                }
            }
        }
        else if(ptr4!=NULL)
        {
            scanf("%d",&amount);
            if(id == -1)
                continue;
            else
                bank1[id].money = amount;
        }
        else
        {
            char tar[100];
            fgets(tar,100,stdin);
        }
    }
        int i;
        for(i = 0 ; i < num; i ++)
        printf("%s %d\n",bank1[i].username,bank1[i].money);
 
}

