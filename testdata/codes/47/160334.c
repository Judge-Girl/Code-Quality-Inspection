#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct node{
    int num;
    char ch; 
}Node;

Node bin[1024][1024];
Node tmp[1024][1024];
int binsize[1024];
int binsum[1024];
int end = 1024;

inline int atoi(char* str){
    int x = 0, i = 0;
    while(str[i])
        x = (x<<3) + (x<<1) + str[i++] - '0';
    return x;
}
void insert(int place, char tar, int num){
    int id = 0, sum = 0;
    if(place == -1)
        for(; id + 1 < end && binsize[id+1]; id++);
    else
        for(; id < end && sum + binsum[id] < place; sum += binsum[id++]);
    int bid = 0, bsum = 0;
    if(place == -1)
        bid = binsize[id] - 1;
    else
        for(; bid + 1 < binsize[id] && bsum + bin[id][bid].num < place - sum; bsum += bin[id][bid++].num);
    int remain = 0;
    if(place != -1)
        remain = bsum + bin[id][bid].num - place + sum;
    if(remain == bin[id][bid].num){
        bid = -1;
        remain = 0;
    }
    if(remain == 0){
        for(int pt = binsize[id]; pt > bid + 1; pt--)
            bin[id][pt] = bin[id][pt-1];
        bin[id][bid+1] = (Node){num, tar};
        binsize[id] += 1;
        binsum[id] += num;
    }else{
        for(int pt = binsize[id]+1; pt > bid+2; pt--)
            bin[id][pt] = bin[id][pt-2];
        bin[id][bid].num -= remain;
        bin[id][bid+1] = (Node){num, tar};
        bin[id][bid+2] = (Node){remain, bin[id][bid].ch};
        binsize[id] += 2;
        binsum[id] += num;
    }
    if(binsize[id] > 1022){
        int count = 0;
        for(int i=0; i<end; i++)
            count += binsize[i];
        memcpy(tmp, bin, sizeof(Node)*1024*1024);
        memset(binsum, 0, sizeof(binsum));
        int ptr = 0, bptr = 0;
        for(int i=0; i<end; i++){
            for(int j=0; j<(count/1024) + (i<count%1024); j++){
                bin[i][j] = tmp[ptr][bptr];
                binsum[i] += tmp[ptr][bptr].num;
                bptr++;
                if(bptr == binsize[ptr]){
                    bptr = 0;
                    ptr ++;
                }
            }
        }
        for(int i=0; i<end; i++)
            binsize[i] = count / 1024 + (i < count % 1024);
    }
}

inline void print(){
    char tar = -1;
    int num = 0;
    for(int i=0; i<end; i++){
        for(int j=0; j<binsize[i]; j++){
            if(bin[i][j].ch == tar)
                num += bin[i][j].num;
            else{
                if(~tar)
                    printf("%c %d ", tar, num);
                tar = bin[i][j].ch;
                num = bin[i][j].num;
            }
        }
    }
    if(~tar)
        printf("%c %d ", tar, num);
    printf("$\n");
}

int main()
{
    char cmd[32] = {0};
    char ch;
    int num;
    while(~scanf("%s", cmd)){
        if(cmd[0] == 'p')
            print();
        else{
            scanf(" %s %c %d", cmd, &ch, &num);
            if(cmd[0] == 'l' && cmd[1] == 'e')
                insert(0, ch, num);
            else if(cmd[0] == 'r' && cmd[1] == 'i')
                insert(-1, ch, num);
            else
                insert(atoi(cmd)-1, ch, num);
        }
    }
    return 0;
}

