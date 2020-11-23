int tail[100000];
void split(int A[], int *a[], int *head[], int k){
    int i=0,j=0;
    for(j=0 ; j<100000 ; ++j)
        tail[j]=-1;
    while(1){
        if(tail[A[i]%k]==-1){
            head[A[i]%k]=&A[i];
            tail[A[i]%k]=i;
        }
        else{
            a[tail[A[i]%k]]=&A[i];
            tail[A[i]%k]=i;
        }
        if(a[i]==0){
            for(j=0 ; j<k ; ++j){
                a[tail[j]]=0;
            }
            break;
        }
        i++;
    }
}
