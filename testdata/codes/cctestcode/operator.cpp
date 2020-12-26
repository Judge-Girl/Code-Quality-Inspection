// 11
int main(){
    int a,b,c,d,e;
    a?1:2; // 1
    a?(b?c:d):e+a*07; // 2
    a&&b||(c,0)&&d+1; // 3
    a&&(b,0)||(c&&c); // 3
    a?:b+(c&&a); // 2
}
