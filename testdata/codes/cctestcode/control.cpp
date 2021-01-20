// 22
#include<iostream>
 # include <cstdlib>
int main(){
    int a,b,c,d,e,f,g,n;
    if(a);else; // 1
    if(a);else if(b);else if(c); // 3
    if(a){
    }else if(b){}
    else{
    } // 2
    switch(a){
        case 0:
        case 1:
        case 2:
            break;
        case 3:
            ;
    } // 4
    switch(a){
        case 0:
        default:
            ;
    } // 1
    for(;;); // 1
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j*=2); 
    } // 2
    while(1){} // 1
    while(a){
        while(0); 
    } // 2
    try{
    }
    catch(std::string s){}
    catch(...){
    } // 2
    for(;;){while(5);if(a);else;} // 3
}
