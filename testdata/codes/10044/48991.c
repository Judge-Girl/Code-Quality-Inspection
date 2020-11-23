#include<stdio.h>
int map[105][105],n,max=0,find=0;

int choice[105]={0};

typedef struct hello{
    int q[105];
    int n;
}asd;

int maxchange(int a){
    if(max<a){
        max=a;
        return 1;
    }
    return 0;
}


void dfs(int ptr,int num,asd q,int flag){
    if(find)return;
    max= max<num? num : max;
    if(ptr==n){
        if(maxchange(num)){
            find=flag;
        }
        //if(flag)printf("num=%d\n",num);
        return;
    }
    for(int i=ptr;i<n&&max<num+n-i&&max<num+q.n;++i){
        if(q.q[i])continue;
        asd tmp=q;
        tmp.n=0;
        for(int j=ptr+1;j<n;++j){
            if(!map[i][j])tmp.q[j]=1;
            tmp.n+= tmp.q[j]? 0 : 1;
        }
        //for(int j=0;j<ptr;++j)if(choice[j]&&!map[j][i]){flag=1;break;}
        //if(flag)continue;
        //choice[i]=1;
        dfs(1+i,num+1,tmp,ptr==n-1);
        //choice[i]=0;
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)scanf("%d",&map[i][j]);
    //int tmp=dfs(0,0);
    asd q;
    q.n=n;
    for(int i=0;i<n;++i)q.q[i]=0;
    dfs(0,0,q,0);
    printf("%d",max);
    return 0;
}

