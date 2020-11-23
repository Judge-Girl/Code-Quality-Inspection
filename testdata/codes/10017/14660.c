#include<stdio.h>
int ab(int x){
    if(x>=0) return x;
    if(x<0) return -x;
}
main(){
    int a[50000][4],b,c,i,j;
    while(scanf("%d",&b)==1){
        for(i=0;i<b;i++){
            scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
            if(i==0){
                printf("%d\n",(ab(a[i][0]-a[i][2])+ab(a[i][1]-a[i][3])));
            }
            else{
                c=70000;
                for(j=0;j<i;j++){
                    if(c>ab(a[i][0]-a[j][2])+ab(a[i][1]-a[j][3])) c=ab(a[i][0]-a[j][2])+ab(a[i][1]-a[j][3]);
                }
                printf("%d\n",c);
                c=70000;
                for(j=0;j<=i;j++){
                    if(c>ab(a[j][0]-a[i][2])+ab(a[j][1]-a[i][3])) c=ab(a[j][0]-a[i][2])+ab(a[j][1]-a[i][3]);
                }
                printf("%d\n",c);
            }
        }
    }
}

