#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <math.h>
        typedef struct play{
            int x;
            int y;
        }p;
    int n;
    int a=1,b=0;
    p ac[30005]={0},bc[30005]={0};
int abs(int i){
    return i>0?i:-i;
}
int ad(int x, int y){
    int j,mind=999999;
    for(j=0;j<a;j++){
        int q=abs(x-ac[j].x)+abs(y-ac[j].y);
        if(mind>q)
            mind=q;
    }
    return mind;
}
int bd(int x, int y){
    int j,mind=999999;
    for(j=0;j<b;j++){
        int q=abs(x-bc[j].x)+abs(y-bc[j].y);
        if(mind>q)
            mind=q;
    }
    return mind;
}
int main(){
    scanf("%d",&n);
    n*=2;
    scanf("%d %d",&ac[0].x,&ac[0].y);
    int j;
    for(j=1;j<n;j++){
        int hh=j/2;
        int x,y;
        scanf("%d %d",&x,&y);
        if(j%2==0){
            ac[hh].x=x;
            ac[hh].y=y;
            a++;
            printf("%d\n",bd(x,y));
        }else if(j%2==1){
            bc[hh].x=x;
            bc[hh].y=y;
            b++;
            printf("%d\n",ad(x,y));
        }
    }
return 0;
}

