#include<stdio.h>

int front = -1, rear = -1;

void enqueue(int q[], int element){
    rear++;
    q[rear] = element;
}

int dqueue(int q[]){
    front++; return q[front];
}

int isempty(){
    if(front==rear) return 1;
    return 0;
}

void bfs(int n, int mat[][n+1]){
    int q[100], mark[n+1];
    int i, j, v;
    for(i = 0; i<=n; i++) mark[i] = 0;

    printf("Enter the starting Vertex: ");
    scanf("%d",&v);
    printf("The BFS Travarsal is: %d ",v); mark[v] = 1;
    enqueue(q,v);
    while(!isempty()){
        int item = dqueue(q);
        for(i = 1; i <=n; i++){
            if(mat[item][i] != 0 && mark[i] == 0){
                printf("%d ",i);
                mark[i] = 1;
                enqueue(q,i);
            }
        }
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