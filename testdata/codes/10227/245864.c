#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned long long int power(int x,int y){
    int con1;
    unsigned long long int con2=1;
    for(con1=0;con1<y;con1++){
        con2*=x;
    }
    return con2;
}

void printone(unsigned long long int v){
    int con1;
    for(con1=63;con1>=0;con1--){
        if(v&power(2,con1))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main(){
    int n,m,con1,con2=0,lon;
    long long int con3;
    long long int ans[25001]={0};
    char str[100001];
    char c;
    char *ptr=str;
    scanf("%d",&n);
    if(n==0){
        scanf("%s",&str);
        lon=strlen(ptr);
        for(con1=0;con1<lon;con1++){
            ans[con2]|=ptr[con1];
            if(con1%8==7){
                con2++;
                continue;
            }
            ans[con2]<<=8;
        }
        if(con1%8!=7){
            ans[con2]<<=((7-(con1%8))*8);
        }
        for(con1=0;con1<=con2;con1++){
            printf("%lld\n",ans[con1]);
        }
    }
    else{
        scanf("%d",&m);
        for(con1=0;con1<m;con1++){
            scanf("%lld",&ans[con1]);
            for(con2=0;con2<8;con2++){
                lon=56;
                con3=ans[con1]>>56;
                if(con3==0)
                    break;
                printf("%c",con3);
                ans[con1]<<=8;
            }
        }
    }
}

