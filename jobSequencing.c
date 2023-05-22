#include<stdio.h>
#include<stdlib.h>

//For Swaping elements in 2D array.........
void swaping(int i, int j, int sequence[][3]){
    char ch = sequence[i][0]; int t1 = sequence[i][1]; int t2 = sequence[i][2];
    sequence[i][0] = sequence[j][0]; sequence[i][1] = sequence[j][1]; sequence[i][2] = sequence[j][2];
    sequence[j][0] = ch; sequence[j][1] = t1; sequence[j][2] = t2;
}

// Sorting the elements according to their profit.....
void sorting(int n, int sequence[][3]){
    int i,j;
    for(i = 0; i<n; i++){
        for(j = i; j<n-1; j++){
            if(sequence[j][2]<sequence[j+1][2]){
                swaping(j,j+1,sequence);
            }
        }
    }
}

//Job sequencing function.....
void jobSequence(int job[], int sequence[][3],int n){
    int profit = 0;
    int i,j;
    printf("The Sequence of job is: ");
    for(i = 0; i<n; i++){
        for(j = sequence[i][1]; j>=1; j--){
            if(job[j]==0){
                printf("%c ",sequence[i][0]);
                profit += sequence[i][2];
                job[j] = 1;
                break;
            }
        }
    }
    printf("\nThe maximum profit is: %d",profit);
}
int main(){
    int n = 5;
    int sequence[][3] = {{'a',2,20},{'b',2,15},{'c',1,1},{'d',3,5},{'e',3,10}};
    int maxdead = -1, i;
    for(i = 0; i<n; i++){
        if(sequence[i][1] > maxdead) maxdead = sequence[i][1];
    }
    int job[maxdead+1];
    for(i = 0; i<maxdead+1; i++){
        job[i] = 0;
    }
    sorting(5,sequence);
    jobSequence(job, sequence, n);
}