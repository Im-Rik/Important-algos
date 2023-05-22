#include<stdio.h>
int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}
int knapsack(int cap, int wt[], int pft[], int n) {
   int i, w;
   int knap[n+1][cap+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= cap; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(pft[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][cap];
}
int main() {
   int profit[] = {60,100,120};
   int weight[] = {10,20,30};
   int capacity = 50;
   int n = sizeof(profit)/sizeof(profit[0]);
   printf("The solution is : %d", knapsack(capacity, weight, profit, n));
   return 0;
}