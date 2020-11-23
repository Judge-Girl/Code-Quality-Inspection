#include<stdio.h>
#include<string.h>
int crypt( char ins[32] ){
    if( strstr( ins, "earns" ) != NULL )
        return 1;
    else if( strstr( ins, "spends") != NULL )
        return 2;
    else if( strstr( ins, "gives") != NULL )
        return 3;
    else if( strstr( ins, "becomes") != NULL )
        return 4;
    return 0;
}
int main(){
    char name[32][32];
    int balance[32] = {0};
    int N;
    scanf("%d",&N);
    for( int i = 0; i < N; i++ )
        scanf("%s%d", name[i], &balance[i]);
    char user1[32];
    while( scanf("%s", user1) != EOF ){
        int code1, code1same = 0;
        for( int i = 0; i < N; i++ )
            if( strcmp(user1, name[i]) == 0 ){
                code1 = i;
                code1same = 1;
            }
        if( !code1same )
            continue;
        char ins[32], user2[32] ;
        int money;
        scanf("%s", ins);
        if( crypt(ins) == 1 ){
            scanf("%d", &money);
            balance[code1] += money;
        }
        else if( crypt(ins) == 2 ){
            scanf("%d", &money);
            if( money <= balance[code1] )
                balance[code1] -= money;
        }
        else if( crypt(ins) == 3 ){
            scanf("%s%d", user2, &money);
            int code2, code2same = 0;
            for( int i = 0; i < N; i++ )
                if( strcmp(user2, name[i]) == 0 ){
                    code2 = i;
                    code2same = 1;
                }
            if( !code2same )
                continue;
            if( balance[code1] >= money ){
                balance[code1] -= money;
                balance[code2] += money;
            }
        }
        else if( crypt(ins) == 4 ){
            scanf("%d", &money);
            balance[code1] = money;
        }
        else{
            char c;
            while( scanf("%c", &c) ){
                if( c == '\n' )
                break;
            }
        }
    }
    for( int i = 0; i < N; i++ )
        printf("%s %d\n", name[i], balance[i]);
}
