// (0/1) Knapsack

#include<stdio.h>
int max(int a, int b)
{
    if(a>b)
     {return a;}
    else
       {return b;} 
}

int main()
{
    int n;
    printf("\nEnter total no. of items: ");
    scanf("%d",&n);

    
    int profit[n+1],weight[n+1],W;

    printf("\nEnter Knapsack  weight: ");
    scanf("%d",&W);

    printf("\nKnapsack weight is %d",W);

//Initialised DP Table
    
    int r=n+1,c=W+1;
    int k[r][c];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i*j==0)
            {
                k[i][j]=0;
            }
            else{
                k[i][j]=-1;

            }
        }
    }


    weight[0]=0, profit[0]=0;


    printf("\nScanning Profit and Weight: \n");

    for(int i=1;i<n+1;i++)
    {
    printf("Profit[%d]: ",i);
    scanf("%d",&profit[i]);

    printf("Weight[%d]: ",i);
    scanf("%d",&weight[i]);
    }

    printf("\nPROFIT: ");
    for(int i=0;i<n+1;i++)
    {
        printf("%d\t",profit[i]);
    }
    printf("\nWEIGHT: ");
    for(int i=0;i<n+1;i++)
    {
        printf("%d\t",weight[i]);
    }

    //<===================MAIN LOGIC================================>
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(weight[i]<=j)
            {
                k[i][j]= max(profit[i]+k[i-1][j-weight[i]], k[i-1][j]);
            }
            else{
                k[i][j]=k[i-1][j];
            }
        }
    }

    printf("\n\n<---DP TABLE--->\n\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",k[i][j]);
        }
        printf("\n");
    }
    
    printf("Maximum profit is %d",k[n][W]);
    return 0;

}
