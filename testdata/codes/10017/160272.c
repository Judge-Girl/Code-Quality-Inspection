#include <stdio.h>
int Ax[50000]={};
int Ay[50000]={};
int Bx[50000]={};
int By[50000]={};
int numa=0,numb=0;
main(){
    int n;
    scanf("%d",&n);
    int i,j,k;
    scanf("%d %d",&Ax[numa],&Ay[numa]);
    numa++;
    for(i=1;i<2*n;i++){
        if(i%2==1){
            scanf("%d %d",&Bx[numb],&By[numb]);
            numb++;
            int min = 10000000;
            for(j=0;j<numa;j++){
                int tp = abs(Bx[numb-1] - Ax[j]) + abs(By[numb-1] - Ay[j]);
                if( tp  < min) min = tp;
            }
            printf("%d\n",min);
        }
        if(i%2==0){
            scanf("%d %d",&Ax[numa],&Ay[numa]);
            numa++;
            int min = 10000000;
            for(j=0;j<numb;j++){
                int tp = abs(Ax[numa-1] - Bx[j]) + abs(Ay[numa-1] - By[j]);
                if( tp  < min) min = tp;
            }
            printf("%d\n",min);
        }
    }
}

