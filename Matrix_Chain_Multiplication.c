//MATRIX CHAIN MULTIPLICATION

#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter total no. of order: ");
    scanf("%d",&n);

    int p[n];
    for(int i=0;i<n;i++)
    {
        printf("P[%d]: ",i);
        scanf("%d",&p[i]);
    }

    printf("\nOrder Matrix: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",p[i]);
    }

    printf("\n\nAssigning dimension to (n-1) matrix:\n ");
    for(int i=0;i<n-1;i++)
    {
        printf("Matrix-%d: %d * %d\n",i,p[i],p[i+1]);
    }


    //Initialised DP Table
    
    int r=n-1;
    int m[r][r];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(i==j)
            {
                m[i][j]=0;
            }
            else{
                m[i][j]=-1;
            }
        }
    }

//<===============================MAIN LOGIC==================================>

for(int len=2;len<=r;len++)
{
   for (int i=0;i<=r-len;i++)
   {
    int j=i+len-1;
    m[i][j]=9999;

    for(int k=i;k<j;k++)
    {
        int cost=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];

        if(cost<m[i][j])
        {
            m[i][j]=cost;
        }
    }
   }
}
    
//Print DP Table  
    
for(int i=0;i<r;i++)
{
    for(int j=0;j<r;j++)
    {
        if(i>j)
        {
            printf("-\t");
        }
        else{
            printf("%d\t",m[i][j]);
        }
    }
    printf("\n");
}

    printf("\nMinimum cost of multiplication is %d",m[0][n-2]);
    return 0;
}
