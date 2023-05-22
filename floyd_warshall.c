#include<stdio.h>
int main(){
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    int D[n][n];
    int i,j,k;
    printf("Enter the distance between two nodes:\nEnter 999 for infinity: \n");
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            //printf("Distance between %d and %d: ",i,j);
            scanf("%d",&D[i][j]);
        }
    }
    for(k = 0; k<n; k++){
        for(i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    printf("The shortest path matrix is: \n");
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
}