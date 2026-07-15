//Dijkstra

#include<stdio.h>
#define inf 999

int main()
{
    int n;
    printf("\nEnter size of adjacency matrix: ");
    scanf("%d",&n);

    int adj[n][n],dist[n],visited[n];


    //initialsized 
    for(int i=0;i<n;i++)
    {   visited[i]=0;
        dist[i]= inf;
    }

    //INPUT ADJACENCY MATRIX
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nAdj[%d][%d]: ",i,j);
            scanf("%d",&adj[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency Matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\t%d",adj[i][j]);
            
        }
        printf("\n");
    }

    int source;
    printf("\nEnter Source vertex: ");
    scanf("%d",&source);

    printf("\nSource vertex is %d ",source);

    dist[source]=0;

    //<===========================MAIN LOGIC=====================================>

    for(int i=0;i<n;i++)
    {
        int u=-1,min=inf;

        //find unvisited minimum weight vertex

        for(int j=0;j<n;j++)
        {
            if(visited[j]==0 && dist[j]<min)
            {
                min=dist[j];
                u=j; //'U' keep track of vetex we are visiting now
            }
        }


        if(u==-1) //No unvisited vertex found
        {
            break;
        }
        visited[u]=1; //'U' is visited so mark it as visited


       //update the weight of visited vertex
       for(int v=0;v<n;v++)
       {
        if(visited[v]==0 && adj[u][v]!=0 && adj[u][v]!=inf)
        {
            
            if( dist[v] > dist[u]+adj[u][v])
            {
                dist[v]=dist[u]+adj[u][v];
            }
        }
       }

    }

    printf("\n\nShortest distance from Source: %d\n",source);
    printf("\nSOURCE->VERTEX\tDISTANCE\n");

    for(int i=0;i<n;i++)
    {
        if(dist[i]==inf)
        {
            printf("\t%d->%d\t\tinf\n",source,i);
        }
        else{
             printf("\t%d->%d\t\t%d\n",source,i,dist[i]);
        }
    }
return 0;
}