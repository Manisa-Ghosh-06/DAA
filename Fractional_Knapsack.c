//FRACTIONAL KNAPSACK

#include<stdio.h>
#include<stdlib.h>

void bubblesort(int profit[],int weight[],float ratio[],int n)
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

                int temp1=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp1;

                float temp2=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp2;
                
            }
        }
    }
}
void ratiosort(float ratio[],int profit[],int weight[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                float temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;


                int temp2=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp2;

                int temp1=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp1;

                
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter total number of items: ");
    scanf("%d",&n);

    int profit[n],weight[n],W;
    float ratio[n],fraction,max=0.0;
    printf("\nScanning Profit and Weight: \n");
    for(int i=0;i<n;i++)
    {
        printf("Profit[%d]: ",i);
        scanf("%d",&profit[i]);
        printf("Weight[%d]: ",i);
        scanf("%d",&weight[i]);
    }

for(int i=0;i<n;i++)
    {
        ratio[i]=(float)profit[i]/weight[i];
    }

    printf("\nPROFIT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",profit[i]);
    }
    printf("\nWEIGHT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",weight[i]);
    }

    printf("\nRATIO: ");
    for(int i=0;i<n;i++)
    {
        printf("%.2f\t",ratio[i]);
    }
    
    printf("\nEnter knapsack capacity: ");
    scanf("%d",&W);

 printf("Knapsack capacity is %d",W);

 bubblesort(profit,weight,ratio,n);

 printf("\n\nAfter sorting based on profit:\n ");
 printf("\nPROFIT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",profit[i]);
    }
    printf("\nWEIGHT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",weight[i]);
    }

int remain=W;

for(int i=0;i<n;i++)
{
    if(weight[i]<=remain)
    {
        max=max+profit[i];
        remain=remain-weight[i];
    }
    else
    {
         fraction=(float)remain/weight[i];
         max=max+fraction*profit[i];
         break;;
    }
}
printf("\n\nMaximum Profit base on (PROFIT) is %.2f ",max);



bubblesort(weight,profit,ratio,n);

for(int i=0;i<n/2;i++)
{
    int temp=weight[i];
    weight[i]=weight[n-1-i];
    weight[n-1-i]=temp;

    temp = profit[i];
    profit[i] = profit[n-1-i];
    profit[n-1-i] = temp;

    float temp3 = ratio[i];
    ratio[i] = ratio[n-1-i];
    ratio[n-1-i] = temp3;
}

 printf("\n\nAfter sorting based on weight:\n ");
 printf("\nPROFIT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",profit[i]);
    }
    printf("\nWEIGHT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",weight[i]);
    }

    max=0.0, remain=W;
for(int i=0;i<n;i++)
{
    if(weight[i]<=remain)
    {
        max=max+profit[i];
        remain=remain-weight[i];
    }
    else
    {
         fraction=(float)remain/weight[i];
         max=max+fraction*profit[i];
         break;;
    }
}
  printf("\n\nMaximum Profit base on (WEIGHT) is %.2f ",max);  
ratiosort(ratio,profit,weight,n);

 printf("\n\nAfter sorting based on ratio:\n ");
 printf("\nPROFIT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",profit[i]);
    }
    printf("\nWEIGHT: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",weight[i]);
    }
    printf("\nRATIO: ");
    for(int i=0;i<n;i++)
    {
        printf("%.2f\t",ratio[i]);
    }

       max=0.0, remain=W;
for(int i=0;i<n;i++)
{
    if(weight[i]<=remain)
    {
        max=max+profit[i];
        remain=remain-weight[i];
    }
    else
    {
         fraction=(float)remain/weight[i];
         max=max+fraction*profit[i];
         break;;
    }
}

printf("\n\nMaximum Profit base on (RATIO) is %.2f ",max);
    return 0;
}