// BIN PACKING -> FIRST FIT

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("\nEnter total items size: ");
    scanf("%d",&n);

    int bin;
    printf("\n\nEnter each bin size: ");
    scanf("%d",&bin);

    printf("\n\nBin size is %d",bin);

    int item[n];
    for(int i=0;i<n;i++)
    {
        printf("\nitem[%d]->",i);
        scanf("%d",&item[i]);

        if(item[i]>bin)
        {
            printf("\n%d exceed bin size.\tAgain scan value!!",item[i]);
            i--;
        }
    }

    printf("\nITEMS:");
    for(int i=0;i<n;i++)
    {
        printf("\t[%d]",item[i]);
    }

    //<===============MANI LOGIC========================>
    int remain[n];
    int count=0;

    for(int i=0;i<n;i++)
    {
        int placed=0;

        for(int j=0;j<count;j++)
        {
            if(item[i] <= remain[j])
            {
                remain[j] = remain[j] - item[i];
                placed = 1;
                break;
            }
        }

        if(placed==0)
        {
            remain[count] = bin - item[i];
            count++;
        }
    }

    printf("\nTotal no. of bins required is %d",count);

    return 0;
}