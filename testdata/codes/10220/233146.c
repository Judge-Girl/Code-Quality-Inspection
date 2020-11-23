void fill(const int A[1024][1024],const int *D[1024*1024],int N){
  int i,j,temp;
  for(i=0;i<N;i++){
  for(j=0;j<N;j++){
  temp = A[i][j];
  D[temp] = &(A[i][j]);
}
}
return;
}
const int *D[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
  int i,j,value;
  
  for(i=0;i<N;i++){
  for(j=0;j<N;j++){
  B[i][j] = &(A[i][j]);
}
}
  fill(A,D,N);
  for(i=0;i<N;i++){
  for(j=0;j<N;j++){
  value = (*B[i][j]+1)%(N*N);
  B[i][j] = D[value];
}
}

  return;
}
