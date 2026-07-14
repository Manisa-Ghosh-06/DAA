//BELLMAN FORD

#include<stdio.h>
# define inf 999

int main()
{
    int n;
    printf("Enter size of adjacency matrix: ");
    scanf("%d",&n);

    int adj[n][n], dist[n];

    for(int i=0;i<n;i++)
    {
        dist[i]=inf;
    }

    //INPUT ADJACENCY MATRIX

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\tadj[%d][%d]: ",i,j);
             scanf("%d",&adj[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",adj[i][j]);
            
        }
         printf("\n");
    }

    int source;
    printf("\nEnter source vertex: ");
    scanf("%d",&source);

    printf("\nSource vertex is %d",source);

    dist[source]=0;
    for(int i=0;i<n;i++)
    {
        printf("%d\t",dist[i]);
    }

//RELAX  EDGES (N-1)TIMES
for(int k=0;k<n-1;k++)
{
    for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]!=inf && dist[u]!=inf && dist[u]+adj[u][v]<dist[v])
            {
                dist[v]=dist[u]+adj[u][v];
            }
        }
    }
}

//CHECK FOR NEGATIVE CYCLE
for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]!=inf && dist[u]!=inf && dist[u]+adj[u][v]<dist[v])
            {
                printf("\nNegative cycle exist!!");
                return 0;
            }
        }
    }



//DISTANCE ARRAY
 for(int i=0;i<n;i++)
    {
        printf("\n%d->%d: %d",source,i,dist[i]);
    }
    return 0;
}