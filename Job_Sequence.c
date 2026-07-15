//Job Sequence with deadline

#include<stdio.h>
#include<stdlib.h>

void sort(int profit[],int deadline[],int n)   //SORT PROFIT IN DESCENDING ORDER
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(profit[j]<profit[j+1])
            {
                int temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                 temp=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=temp;


            }
        }

    }
}

int max(int deadline[],int n)  //FIND MAX DEADLINE
{
    int key=deadline[0];
    for(int i=1;i<n;i++)
    {
         if(key<deadline[i])
         {
            key=deadline[i];
         }
    }
    return key;
}

int main()
{
    int n;
    printf("\nEnter total no. of jobs: ");
    scanf("%d",&n);

    int deadline[n],profit[n];

    printf("\nScanning profit and deadline:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nProfit[%d]: ",i);
        scanf("%d",&profit[i]);

        printf("\nDeadlinet[%d]: ",i);
        scanf("%d",&deadline[i]);
    }

    printf("\nProfit: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",profit[i]);
    }
     printf("\nDeadline: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",deadline[i]);
    }

    sort(profit,deadline,n);

    int dmax=max(deadline,n);

    printf("\nMaximum Deadline is %d",dmax);
    
    int slot[dmax],total=0;
    for(int i=0;i<n;i++)
    {
        slot[i]=-1;
    }
    
//<=======================MAIN LOGIC================================>
    
    for(int i=0;i<n;i++)
    {
        for(int j=deadline[i]-1;j>=0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=profit[i];
                total=total+profit[i];
                break;
            }

        }
    }

printf("\nMaximum profit is %d",total);


    return 0;
}
