#include<stdio.h>
#include<conio.h>
int a[10][10], n, m, i, j, source, s[10], b[10];
int visited[10];

void create()
{
    printf("\nEnter the number of vertices of the digraph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs()
{
    int q[10], u, front=0, rear=-1;
    printf("\nEnter the source vertex to find other nodes reachable or not: ");
    scanf("%d", &source);
    q[++rear] = source;
    visited[source] = 1;
    printf("\nThe reachable vertices are: ");
    while(front<=rear)
    {
        u = q[front++];
        for(i=1; i<=n; i++)
        {
            if(a[u][i] == 1 && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
                printf("\n%d", i);
            }
        }
    }
}

void main()
{
    int ch;
    create();
    bfs();
    for(i=1;i<=n;i++)
    if(visited[i]==0){
        printf("\nThe vertex that is not rechable %d" ,i);
    }
}