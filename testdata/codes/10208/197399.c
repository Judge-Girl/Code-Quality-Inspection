#include<stdio.h>
int main(){
int ax,ay,bx,by,cx,cy;
scanf("%d %d %d %d %d",&ay,&bx,&by,&cx,&cy);
printf("%d\n",ay*bx*by/(ay*bx-cx*cy));
return 0;
}

