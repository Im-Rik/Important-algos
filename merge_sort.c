#include<stdio.h>
int n;
int temp[2];

void display(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int merge(int arr[],int lw,int mid,int up){
    int i,j,k=lw;
    int t = up-lw+1;
    for(i=lw,j=mid+1;i<=mid && j<=up; ){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;k++;
        }
        else if(arr[j]<arr[i]){
            temp[k]=arr[j];
            j++;k++;
        }
        else{
            temp[k]=arr[i];k++;
            temp[k]=arr[i];
            i++;j++;k++;
        }
    }
    for( ;i<=mid; i++){
        temp[k]=arr[i];k++;
    }
    for( ;j<=up;j++){
        temp[k]= arr[j];k++;
    }
    for(i = lw;i<=up;i++){
        arr[i]=temp[i];
    }
}
int merge_sort(int arr[],int lw,int up){
    if(lw<up){
        int mid = (lw+up)/2;
        merge_sort(arr,lw,mid);
        merge_sort(arr,mid+1,up);
        merge(arr,lw,mid,up);
    }
    else{
        return;
    }
}
int main(){
    int i;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter value in the array: ");
    for (i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array value before merge sorting: ");
    display(arr,n);
    int lw=0,up=n-1;
    merge_sort(arr,lw,up);
    printf("The array value after performing merge sort: ");
    display(arr,n);
}