#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[35];
    int balance;
} User;
User user[32];
int main(){
    int N; scanf("%d", &N);
    int i;
    for(i=0;i<N;i++){
        scanf("%s %d", user[i].name, &user[i].balance);
    }
    char line[35 * 4];
    while(fgets(line, 35 * 4, stdin) != NULL){
        char tmpname[35], command[35];
        sscanf(line, "%s %s", tmpname, command);
        int index = strlen(tmpname) + strlen(command) + 2;
        for(i=0;i<N;i++){
            if(strcmp(tmpname, user[i].name) == 0){
                char *ptr;
                ptr = strstr(command, "earns");
                if(ptr != NULL){
                    int value;
                    sscanf(line + index, "%d", &value);
                    user[i].balance += value;
                }
                ptr = strstr(command, "spends");
                if(ptr != NULL){
                    int value;
                    sscanf(line + index, "%d", &value);
                    if(user[i].balance >= value)
                        user[i].balance -= value;
                }
                ptr = strstr(command, "gives");
                if(ptr != NULL){
                    char target[35]; int value;
                    sscanf(line + index, "%s %d", target, &value);
                    if(user[i].balance >= value){
                        int j;
                        for(j=0;j<N;j++){
                            if(strcmp(target, user[j].name) == 0){
                                user[i].balance -= value;
                                user[j].balance += value;
                                break;
                            }
                        }
                    }
                }
                ptr = strstr(command, "becomes");
                if(ptr != NULL){
                    int value;
                    sscanf(line + index, "%d", &value);
                    user[i].balance = value;
                }
                break;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%s %d\n", user[i].name, user[i].balance);
    }
    return 0;
}

