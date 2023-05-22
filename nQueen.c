#include<stdio.h>
int x[100];
void display(int x[],int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
int isSafe(int k, int i, int x[]){
    int j;
    for(j = 0; j<k; j++){
        int t1 = x[j] - i; int t2 = j - k;
        if(t1<0) t1 *= -1;
        if(t2<0) t2 *= -1;
        if(x[j] == i || t1==t2) return 0;
    }
    return 1;
}
int nQueen(int k, int n){
    int i;
    for(i = 0; i<n; i++){
        if(isSafe(k,i,x)){
            x[k] = i;
            if(k == n-1) display(x,n);
            else nQueen(k+1,n);
        }
    }
}
int main(){
    int n;
    printf("Enter the no. of queen: ");
    scanf("%d",&n);
    int k = 0;
    nQueen(k,n);
}
    