#include<stdio.h>

int top = -1;

void push(int sta[], int element){
    top++;
    sta[top] = element;
}

void pop(int sta[]){
    top--;
}

int top_element(int sta[]){
    return sta[top];
}

int isempty(){
    if(top == -1) return 1;
    return 0;
}

void bfs(int n, int mat[][n+1]){
    int sta[100], mark[n+1];
    int i, j, v;
    for(i = 0; i<=n; i++) mark[i] = 0;

    printf("Enter the starting Vertex: ");
    scanf("%d",&v);
    printf("The DFS Travarsal is: %d ",v); mark[v] = 1;
    push(sta, v);
    while(!isempty()){
        int item = top_element(sta);
        int flag = 0;
        for(i = 1; i <=n; i++){
            if(mat[item][i] != 0 && mark[i] == 0){
                printf("%d ",i);
                mark[i] = 1;
                push(sta, i);
                flag = 1;
                break;
            }
        }
        if(flag == 0) pop(sta);
    }
}

int main(){
    int n;
    printf("Enter the no. of vertices: ");
    scanf("%d",&n);
    int mat[n+1][n+1];
    mat[0][0] = 0;
    printf("Enter the adjacency matrix: \n");
    int i,j;
    for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    bfs(n,mat);
}