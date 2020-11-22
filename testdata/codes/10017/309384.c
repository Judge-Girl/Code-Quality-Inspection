#include<stdio.h>
#pragma GCC optimize("Ofast")
short ma[50000][2];
short mb[50000][2];
inline int abs(int a){
    return a>0?a:-a;
    }
int main(){
    int n;
    scanf("%d",&n);
    int sa=0,sb=0;

    scanf("%hd%hd",&ma[0][0],&ma[0][1]);
    scanf("%hd%hd",&mb[0][0],&mb[0][1]);

    printf("%d\n",abs(mb[0][0]-ma[0][0])+abs(mb[0][1]-ma[0][1]));

    sa++,sb++;
    for(int i=1;i<n;i++){
        scanf("%hd%hd",&ma[i][0],&ma[i][1]);
        scanf("%hd%hd",&mb[i][0],&mb[i][1]);

        int min=1<<30;

        for(int k=0,t=0;k<sb;k++){
            t=abs(ma[i][0]-mb[k][0])+abs(ma[i][1]-mb[k][1]);
            if(t<min)min=t;
        }
        printf("%d\n",min);

        min=1<<30;
        for(int k=0,t=0;k<=sa;k++){
            t=abs(mb[i][0]-ma[k][0])+abs(mb[i][1]-ma[k][1]);
            if(t<min)min=t;
        }
        printf("%d\n",min);
        sa++,sb++;
    }
}

