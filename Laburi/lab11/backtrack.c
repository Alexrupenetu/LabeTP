#include <stdio.h>
#define SIZE 10

int sol[SIZE];

void print(int sol[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", sol[i]);
    printf("\n");
}

int valid(int sol[], int pos) {
    int nr = sol[pos];
    int sum = 0;
    for (int i = 0; i <= pos; i++)
        sum += sol[i];

    for (int i = 0; i < pos; i++)
        if (nr == sol[i])
            return 0;

    if (sum > 150)
        return 0;
    else if (sum == 150)
        return 1;

    return 2; 
}

void back(int *init, int pos, int size) {
    for (int i = 0; i < size; i++) {
        sol[pos] = init[i];
        int val = valid(sol, pos);
        if (val == 1) {
            print(sol, pos + 1);
        } else if (val == 2) {
            back(init, pos + 1, size);
        }
    }
}

int main() {
    int init[] = {1, 5, 10, 20, 50, 100};
    back(init, 0, 6);
    return 0;
}




