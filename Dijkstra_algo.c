#include<stdio.h>

int least_dis(int n, int d[], int mark[]){
    int min = 999999, i,index;
    for(i = 0; i<n; i++){
        if(mark[i]==0 && d[i]<min){
            index = i; min = d[i];
        }
    }
    return index;
}

void dijkstra(int n, int arr[][n], int source){
    
    int d[n],mark[n];
    int i,j;
    for(i = 0; i<n; i++){
        d[i] = 999;
        mark[i] = 0;
    }
    d[source] = 0;
    
    for(i = 0; i<n; i++){
        int ld = least_dis(n,d,mark);
        mark[ld] = 1;
        for(j = 0; j<n; j++){
            if(arr[ld][j]>0){
                int temp = d[ld] + arr[ld][j];
                if(temp<d[j]){
                    d[j] = temp;
                }
            }
        }
    }

    printf("The shortest distances from the source node are:\n");
    for(i = 0; i<n; i++){
        printf("%d ",d[i]);
    }
}

int main(){
    int n = 5;
    int arr[5][5] = {{0,10,5,-1,-1},{-1,0,-1,2,-1},{-1,3,0,9,2},{-1,-1,-1,0,-1},{2,-1,-1,6,0}};
    int k;
    printf("Enter the source node: ");
    scanf("%d",&k);
    dijkstra(n,arr,k);
}