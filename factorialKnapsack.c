#include<stdio.h>
int n;
void factknapsack(int profit[], float weight[], int capacity){
    int i, j = 0;
    int maxProfit = 0;
    while(capacity>0 && j<n){
        float ratio = -1.0;
        int index = -1;
        for(i = 0; i<n; i++){
            if(profit[i] != -1){
                float temp = profit[i]/weight[i];
                if(temp>ratio){
                    ratio = temp; index = i;
                }
            }
        }
        if(capacity<weight[index]){
            maxProfit += (capacity/weight[index]) * profit[index];
        }
        else maxProfit += profit[index];
        capacity -= weight[index];
        profit[index] = -1; j++;
    }
    printf("The maximum profit is: %d",maxProfit);
}
int main(){
    n = 5;
    int profit[] = {30,40,45,77,90};
    float weight[] = {5.0 ,10.0 ,15.0 ,22.0 ,25.0};
    int capacity = 60;
    factknapsack(profit, weight, capacity);
}