#include <stdio.h>
 
void merge(int A[], int B[], int* a[], int* b[]){
   int as=1,bs=1,ai=0,bi=0, turn,flag = 1,t=0; // turn = 1,a, turn = 0,b
   int anum = 0,bnum = 0;
   while(a[anum]!=NULL){
       anum++;
   }
   while(b[bnum]!=NULL){
       bnum++;
   }
   if(anum!=0 && bnum!=0){
        if(A[0]<B[0]){
            if(A[1] > B[0]){
                a[0] = &B[0];
                turn = 0;
                ai++;
            }
            else{
                a[0] = &A[1];
                ai = 1;
                as = 2;
                bi = 0;
                bs = 0;
                turn = 1;
            }
        }
        else{
            if(B[1] > A[0]){
                b[0] = &A[0];
                turn = 1;
                bi++;
            }
            else{
                b[0] = &B[1];
                bi = 1;
                bs = 2;
                ai = 0;
                as = 0;
                turn = 0;
            }
        }
        while(flag){
            if(A[as]<B[bs]){
                if(turn==0){
                    b[bi] = &A[as];
                    bi++;
                    as++;
                    turn = 1;
                }
                else{
                    a[ai] = &A[as];
                    ai++;
                    as++;
                    turn = 1;
                }
            }
            else{
                if(turn==0){
                    b[bi] = &B[bs];
                    bi++;
                    bs++;
                    turn = 0;
                }
                else{
                    a[ai] = &B[bs];
                    ai++;
                    bs++;
                    turn = 0;
                }
            }
            if(a[ai]==NULL && turn==1){
                a[ai] = &B[bs++];
                while(b[bi]!=NULL){
                    b[bi++] = &B[bs++];
                }
                break;
            }
            if(b[bi]==NULL && turn==0){
                b[bi] = &A[as++];
                while(a[ai]!=NULL){
                    a[ai++] = &A[as++];
                }
                break;
            }
        }
   }
   else if(anum==0 && bnum==0){
       if(A[0]>B[0]){
           b[0] = &A[0];
       }
       else a[0] = &B[0];
   }
   else if(anum==0 || bnum==0){
       if(anum==0){
           int bindex = 0, Bindex = 0;
           if(A[0]>B[0]){
               b[0] = &B[1];
               bindex = 1;
               Bindex = 2;
                while(A[0]>B[Bindex]){
                    b[bindex++] = &B[Bindex++];
                    if(b[bindex]==NULL){
                        flag = 0;
                        break;
                    }
                }
                b[bindex++] = &A[0];
                if(b[Bindex-1]!=NULL && flag==0){
                    a[0] = &B[Bindex++];
                    while(b[Bindex-1]!=NULL){
                        b[bindex++] = &B[Bindex++];
                    }
                }
           }
           else{
               a[0] = &B[Bindex++];
               while(b[bindex]!=NULL){
                   b[bindex++] = &B[Bindex++];
               }
           }
       }
       else if(bnum==0){
            int bindex = 0, Bindex = 0;
            if(B[0]>A[0]){
               a[0] = &A[1];
               bindex = 1;
               Bindex = 2;
 
                while(B[0]>A[Bindex]){
                    a[bindex++] = &A[Bindex++];
                    if(a[bindex]==NULL){
                        flag = 0;
                        break;
                    }
                }
                a[bindex++] = &B[0];
                if(a[Bindex-1]!=NULL && flag==1){
                    b[0] = &A[Bindex++];
                    while(a[Bindex-1]!=NULL){
                        a[bindex++] = &A[Bindex++];
                    }
                }
            }
            else{
                b[0] = &A[Bindex++];
                while(a[bindex]!=NULL){
                    a[bindex++] = &A[Bindex++];
                }
            }
       }
   }
}
