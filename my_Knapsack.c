#include <stdio.h>

#define MAX_WEIGHT 20
#define ARR_LEN 5

char namesArr[ARR_LEN];
int valuesArr[ARR_LEN];
int weightsArr[ARR_LEN];
int selected_bool[ARR_LEN + 1][MAX_WEIGHT + 1] = {0};

void printArr(int arr[]){
    for(int i = 0 ; i < ARR_LEN; i++){
        printf("%d \n" , arr[i]);
    }
}

void printCharArr(char arr[]) {
    for(int i = 0 ; i < ARR_LEN; i++) {
        printf("%c \n" , arr[i]);
    }
}

void setupIntArr(int arr[]){
    for(int i = 0 ; i < ARR_LEN; i++){
        scanf(" %d", &arr[i]);
    }
}

void setupCharArr(char arr[]) {
    for(int i = 0 ; i < ARR_LEN; i++) {
        scanf(" %c", &arr[i]);
    }
}

void Knapsack(int weights[], int values[], int selected_bool[][MAX_WEIGHT+1]) {
    int K[ARR_LEN + 1][MAX_WEIGHT + 1];
    int i, w;

    for (i = 0; i <= ARR_LEN; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w) {
                if (values[i - 1] + K[i - 1][w - weights[i - 1]] > K[i - 1][w]) {
                    K[i][w] = values[i - 1] + K[i - 1][w - weights[i - 1]];
                    selected_bool[i][w] = 1;
                } else {
                    K[i][w] = K[i - 1][w];
                    selected_bool[i][w] = 0;
                }
            } else {
                K[i][w] = K[i - 1][w];
                selected_bool[i][w] = 0;
            }
        }
    }

    int result[ARR_LEN];
    int total_weight = MAX_WEIGHT;
    int max_value = K[ARR_LEN][MAX_WEIGHT];

    int j = 0;
    for (i = ARR_LEN; i > 0; i--) {
        if (selected_bool[i][total_weight]) {
            result[j++] = i;
            total_weight -= weights[i - 1];
        }
    }

    printf("Maximum profit: %d\n", max_value);
    printf("Selected items:");
    for (i = j - 1; i >= 0; i--) {
        printf(" %c", namesArr[result[i] - 1]);
    }
}


int main(){
    int i;
    for(i = 0; i < ARR_LEN; i++){
        scanf(" %c", &namesArr[i]);
        scanf(" %d", &valuesArr[i]);
        scanf(" %d", &weightsArr[i]);
    }
    Knapsack(weightsArr, valuesArr, selected_bool);
}
