#include <sys/resource.h>
void increase_stack_size() {
  const rlim_t ks = 64*1024*1024;
  struct rlimit rl;
  int res=getrlimit(RLIMIT_STACK, &rl);
  if(res==0){
    if(rl.rlim_cur<ks){
      rl.rlim_cur=ks;
      res=setrlimit(RLIMIT_STACK, &rl);
    }
  }
}

#define MAXN 1024
void constructPointerArray(const int A[MAXN][MAXN], const int *ptrArray[MAXN][MAXN], int N)
{
	increase_stack_size();
    const int* tmp[N*N+1];
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            tmp[A[i][j]]=&A[i][j];
    }
    tmp[N*N]=tmp[0];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            ptrArray[i][j]=tmp[A[i][j]+1];
    }
}
