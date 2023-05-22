#include<stdio.h>
int max,min,max1,min1;
void maxmin(int arr[],int lw,int up){
    int i = lw,j = up;
    if(lw==up){
        max = min = arr[i];
    }
    else if(lw==up-1){
        if(arr[i]>arr[j]){
            max = arr[i];
            min = arr[j];
        }
        else{
            max = arr[j];
            min = arr[i];
        }
    }
    else{
        int mid = (lw+up)/2;
        maxmin(arr,lw,mid);
        max1 = max; min1 = min;
        maxmin(arr,mid+1,up);
        if(max1>max) max = max1;
        if(min1<min) min = min1;
    }
}
int main(){
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array: ");
    for (i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lw = 0,up = n-1;
    maxmin(arr,lw,up);
    printf("The max element is: %d",max);
    printf("\nThe min element is: %d",min);
}