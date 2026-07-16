//BIN PACKING->(NEXT FIT)

#include <stdio.h>
#include <stdlib.h>

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



   int count=1,remain=bin;
   for(int i=0;i<n;i++)
   {
       if(item[i]<=remain)
       {

           remain=remain-item[i];


       }
       else{

             count++;
             remain=bin-item[i];


       }
   }
   printf("\nTotal no. of bins required is %d",count);
   return 0;
}
