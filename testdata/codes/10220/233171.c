#include "constructPointerArray.h"
#include <inttypes.h>
#include <stdlib.h>
typedef uint16_t array_uint16_t_2[2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N) {
    array_uint16_t_2* good = malloc(2 * 2 * N * N);
    for (uint16_t i = 0; i < N; i += 1) {
        for (uint16_t j = 0; j < N; j += 1) {
            good[A[i][j]][0] = j;
            good[A[i][j]][1] = i; } }
    for (uint32_t i = 0; i < N * N - 1; i += 1) {
        B[good[i][1]][good[i][0]] = &A[good[i + 1][1]][good[i + 1][0]]; }
    B[good[N * N + -1][1]][good[N * N + -1][0]] = &A[good[0][1]][good[0][0]];
    free(good); }
