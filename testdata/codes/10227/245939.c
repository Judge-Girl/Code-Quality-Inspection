#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    int f = 0;
    int count = 0;
    int count2;
    char in[100000];
    unsigned char a = 255;
    char b = a;
    //unsigned char in2 [100000];
    long long ans = 0;
    scanf("%d",&t);
    if (t == 0){
        scanf("%s",&in);
        int l = strlen(in);
        //printf("%d\n",l);
        for(i = 0;i<l;i++){
            ans <<= 8;
            //printf("%d",in[i]);
            /*if(in[i] == '\0'){
                count++;
                printf("&d\n",count);
                break;
            }*/
            ans |=(int)(in[i]);
            count ++;
            //printf("%lld\n",ans);
            if(count == 8){
                printf("%lld\n",ans);
                count = 0;
            }
        }
        while (count != 8 && count != 0){
            f = 1;
            ans <<= 8;
            count ++;
        }
        if (f == 1)
            printf("%lld",ans);
        if(l%8==0)
            printf("0");
    }
    else {
        int no;
        scanf("%d",&no);
        for(i = 0;i<no;i++){
            scanf("%lld",&ans);
            count2 = 7;
            while (count2!=-1){
                in[count] = (char)(ans>>count2*8);
                if (in[count] == '\0'){
                    break;
                }
                count2--;
                printf("%c",in[count]);
                count++;
            }
        }
    }
}

