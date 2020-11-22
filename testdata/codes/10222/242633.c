void split(int A[], int *a[], int *head[], int k){
    int count = 0;
    while(a[count]!=0) count++;
    count++;
    int **tail[k];
    for(int i=0; i<k; i++){
        head[i] = 0;
        tail[i] = 0;
    }
    for(int i=0; i<count; i++){
        int t = A[i] % k;
        if(head[t]==0){
            head[t] = &A[i];
            tail[t] = &a[i];
        }
        else{
            *tail[t] = &A[i];
            tail[t] = &a[i]; 
        }
    }
    for(int i=0; i<k; i++){
        if(tail[i]!=0){
            *tail[i] = 0;
        }
    }
}
