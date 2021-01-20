// 87
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fors(i,s,n) for(int i=0;i<n&&s[i];i++)
#define f1 1?2:3
#define f2 f1,f1
#define f4 f2,f2
#define f8 f4,f4
#define f17 f8&&f8
#define f69 f17+f17,f17||f17
int main(){
    int i,n; cin>>n;
    string s;
    rep(i,n) s[i]=rand(); // 1
    fors(i,s,n){
        if(!isprint(s[i])&&!isspace(s[i]))
            continue;
        cout<<s[i];
    } // 4
    rep(i,n) rep(i,n){} // 2
    f1; // 1
    f2; // 2
    f8; // 8
    f69; // 69
}
