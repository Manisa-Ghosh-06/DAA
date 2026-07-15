//FORD WARSHALL

#include<stdio.h>
#define inf 999

int main()
{
    int n;
    printf("\nEnter size of adjacency matrix: ");
    scanf("%d",&n);

    int adj[n][n];

    //INPUT ADJACENCY MATRIX

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Adj[%d][%d]: ",i,j);
            scanf("%d",&adj[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency Matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",adj[i][j]);
            
        }
        printf("\n");
    }

//<===================MAIN LOGIC==================>
for(int k=0;k<n;k++)
{
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if( adj[i][k]!= inf && adj[k][j]!=inf && adj[i][j]>adj[i][k]+adj[k][j])
            {
                adj[i][j]=adj[i][k]+adj[k][j];
            }
        }
        
    }
    printf("\nMatrix-%d\n",k+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",adj[i][j]);
            
        }
        printf("\n");
    }
}

    return 0;
}
