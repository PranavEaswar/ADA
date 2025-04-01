#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int stackindex=0;
int vertices=0;

void addEdge(int src, int dest)
{
    graph[src][dest]=1;
}

void dfs(int v)
{
    visited[v]=1;
    for (int i=0; i<vertices; i++)
    {
        if (graph[v][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
    }
    stack[stackindex++]=v;
}

void toposort()
{
    for (int i=0; i<vertices; i++)
    {
        if (visited[i]==0)
        {
            dfs(i);
        }
    }
    printf("Topological sorting of vertices: ");
    for (int i=stackindex-1; i>=0; i--)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    int edges, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (format: src dest): \n");
    for (int i=0; i<edges; i++)
    {
        scanf("%d %d", &src, &dest);
        graph[src][dest]=1;
    }
    for (int i=0; i<vertices; i++)
    {
        visited[i]=0;
    }
    toposort();
    return 0;
}
