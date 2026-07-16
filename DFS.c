// DFS (Depth First Search)

#include <stdio.h>

int adj[20][20], visited[20], n;

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {   printf("\tadj[%d][%d]: ",i,j);
            scanf("%d", &adj[i][j]);
        }
        printf("\n");
    }

    printf("Adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {   printf("%d\t",adj[i][j]);
            
        }
        printf("\n");
    }
    
   int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
