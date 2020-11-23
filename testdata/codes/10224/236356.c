#pragma GCC optimize ("O3")
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
typedef char array_char_32[32];
typedef struct {
    array_char_32 first;
    uint32_t second;
} pair_array_char_32_uint32_t;
typedef struct {
    pair_array_char_32_uint32_t data[32];
} map_array_char_32_uint32_t;
uint32_t* map_array_char_33_uint32_t_at(map_array_char_32_uint32_t* this, array_char_32 key) {
    for (uint32_t i = 0; i < 32; i += 1) {
        if (strcmp(key, this->data[i].first) == 0) return &this->data[i].second; }
    return NULL; }
int main() {
    uint32_t num_users;
    fscanf(stdin, "%u", &num_users);
    map_array_char_32_uint32_t users;
    for (uint32_t i = 0; i < num_users; i += 1) {
        pair_array_char_32_uint32_t user;
        fscanf(stdin, " %s%u", user.first, &user.second);
        users.data[i] = user; }
    while (1) {
        array_char_32 subject;
        array_char_32 action;
        if (fscanf(stdin, " %s %s", subject, &action) != 2) {
            break; }
        if (strstr(action, "earns") != NULL) {
            uint32_t amount;
            fscanf(stdin, "%u", &amount);
            uint32_t* balance = map_array_char_33_uint32_t_at(&users, subject);
            if (balance) *balance += amount; }
        else if (strstr(action, "spends") != NULL) {
            uint32_t amount;
            fscanf(stdin, "%u", &amount);
            uint32_t* balance = map_array_char_33_uint32_t_at(&users, subject);
            if (balance) *balance = *balance >= amount ? *balance - amount : *balance; }
        else if (strstr(action, "gives") != NULL) {
            array_char_32 object;
            uint32_t amount;
            fscanf(stdin, " %s%u", object, &amount);
            uint32_t* subject_balance = map_array_char_33_uint32_t_at(&users, subject);
            uint32_t* object_balance = map_array_char_33_uint32_t_at(&users, object);
            if (subject_balance && object_balance && *subject_balance >= amount) {
                *subject_balance -= amount;
                *object_balance += amount; } }
        else if (strstr(action, "becomes") != NULL) {
            uint32_t amount;
            fscanf(stdin, "%u", &amount);
            uint32_t* balance = map_array_char_33_uint32_t_at(&users, subject);
            if (balance) *balance = amount; }
        else {
            fscanf(stdin, "%*[^\n]");
            fgetc(stdin); } }
    for (uint32_t i = 0; i < num_users; i += 1) {
        fprintf(stdout, "%s %u\n", users.data[i].first, users.data[i].second); } }
