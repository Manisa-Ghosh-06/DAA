//Activity Selection

#include<stdio.h>

void sort(int start[],int end[],int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(end[j]>end[j+1])
            {
                int temp=end[j];
                end[j]=end[j+1];
                end[j+1]=temp;

                temp=start[j];
                start[j]=start[j+1];
                start[j+1]=temp;

                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;




            }
        }

    }
}

int main()
{
    int n;
    printf("\nEnter total no. of activity: ");
    scanf("%d",&n);

    int start[n],end[n],a[n],slot[n];

    printf("\nScanning Start time and End time\n");
    for(int i=0;i<n;i++)
    {
        printf("\nStart[%d]: ",i);
        scanf("%d",&start[i]);

        printf("\nEnd[%d]: ",i);
        scanf("%d",&end[i]);

        a[i]=i+1;
    }


    printf("\nActivity no:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }

    printf("\nStart:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",start[i]);
    }
    printf("\nEnd:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",end[i]);
    }


    sort(start,end,a,n);

    printf("\n\nAfter sorting End time:\n\n");

    printf("\nActivity no:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }

    printf("\nStart:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",start[i]);
    }
    printf("\nEnd:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",end[i]);
    }


for(int i=0;i<n;i++)
{
    slot[i]=-1;
}

//MAIN LOGIC

int count=1,last=0;

slot[0]=a[0];

for(int i=1;i<n;i++ )
{
    if(start[i]>=end[last])
    {
        count++;
        slot[i]=a[i];
        last=i;
    }
    
}

printf("\n\nMaximum no. of activity selected is %d",count);
printf("\nSelected Activities are : ");

for(int i=0;i<n;i++)
{
    if(slot[i]!=-1)
    {
        printf("A_%d\t",slot[i]);
    }
    
}

return 0;
    
}