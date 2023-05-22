#include<stdio.h>
int partition(int arr[],int lw,int up){
    int a = lw+1;
    int b = up,t;
    while(a<=b){
        while(arr[a]<arr[lw]) a++;
        while(arr[b]>arr[lw]) b--;
        if(b>a) {
            t = arr[a];
            arr[a] = arr[b];
            arr[b] = t;
        }
    }
    t = arr[b];
    arr[b] = arr[lw];
    arr[lw] = t;
    return b;
}
void quick_sort(int arr[],int lw, int up){
    int pos;
    if(lw<up){
        pos = partition(arr,lw,up);
        quick_sort(arr,lw,pos-1);
        quick_sort(arr,pos+1,up);
    }
    else return;
}
int main(){
    int n,i,j;
        printf("Enter the size of array: ");
        scanf("%d",&n);
        int arr[n];
        printf("Enter the elements: ");
        for(i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("Elements before sorting is: ");
        for(i = 0;i<n;i++){
            printf("%d ",arr[i]);
        }
        int lw = 0,up = n-1;
        quick_sort(arr,lw,up);
        printf("\nElements after sorting is: ");
        for(i = 0;i<n;i++){
            printf("%d ",arr[i]);
        }
}