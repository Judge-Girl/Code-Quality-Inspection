#include<stdio.h>

int main(){
    int n,a=0,b=0,ax[50010],ay[50010],bx[50010],by[50010];
    scanf("%d",&n);
    for(int i=0;i<2*n;++i){
        if(i%2){
            scanf("%d%d",&bx[b],&by[b]);
            int min=10000000;
            for(int j=0;j<a;++j){
                int tmp= ( (bx[b]-ax[j])>0?(bx[b]-ax[j]):(ax[j]-bx[b]) ) + ( (by[b]-ay[j])>0?(by[b]-ay[j]):(ay[j]-by[b]) ) ;
                if(tmp<min)min=tmp;
            }
            printf("%d\n",min);
            b++;
        }else{
            scanf("%d%d",&ax[a],&ay[a]);
            int min=10000000;
            for(int j=0;j<b;++j){
                int tmp= ( (ax[a]-bx[j])>0?(ax[a]-bx[j]):(bx[j]-ax[a]) ) + ( (ay[a]-by[j])>0?(ay[a]-by[j]):(by[j]-ay[a]) ) ;
                if(tmp<min)min=tmp;
            }
            if(i)printf("%d\n",min);
            a++;
        }
    }
    return 0;
}

