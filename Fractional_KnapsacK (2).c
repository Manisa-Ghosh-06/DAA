// FRACTIONAL KNAPSACK(BETTER VERSION)

#include <stdio.h>
#include <stdlib.h>

float total(int profit[], int weight[], float ratio[], int n, int W);

void bubblesort(int profit[], int weight[], float ratio[], int n, int choice)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(choice==1)        // Greedy about Profit
            {
                if(profit[j] < profit[j+1])
                {
                    int temp = profit[j];
                    profit[j] = profit[j+1];
                    profit[j+1] = temp;

                    temp = weight[j];
                    weight[j] = weight[j+1];
                    weight[j+1] = temp;

                    float temp2 = ratio[j];
                    ratio[j] = ratio[j+1];
                    ratio[j+1] = temp2;
                }
            }

            else if(choice==2)   // Greedy about Weight
            {
                if(weight[j] > weight[j+1])
                {
                    int temp = weight[j];
                    weight[j] = weight[j+1];
                    weight[j+1] = temp;

                    temp = profit[j];
                    profit[j] = profit[j+1];
                    profit[j+1] = temp;

                    float temp2 = ratio[j];
                    ratio[j] = ratio[j+1];
                    ratio[j+1] = temp2;
                }
            }

            else if(choice==3)   // Greedy about Ratio
            {
                if(ratio[j] < ratio[j+1])
                {
                    float temp = ratio[j];
                    ratio[j] = ratio[j+1];
                    ratio[j+1] = temp;

                    int temp2 = profit[j];
                    profit[j] = profit[j+1];
                    profit[j+1] = temp2;

                    temp2 = weight[j];
                    weight[j] = weight[j+1];
                    weight[j+1] = temp2;
                }
            }
        }
    }
}

float total(int profit[], int weight[], float ratio[], int n, int W)
{
    int remain = W;
    float max = 0.0, fraction;

    for(int i=0; i<n; i++)
    {
        if(weight[i] <= remain)
        {
            remain = remain - weight[i];
            max = max + profit[i];
        }
        else
        {
            fraction = (float)remain / weight[i];
            max = max + fraction * profit[i];
            break;
        }
    }

    return max;
}

int main()
{
    int n;
    printf("Enter total number of items: ");
    scanf("%d",&n);

    int profit[n], weight[n], W;
    float ratio[n];

    printf("\nScanning Profit and Weight:\n");

    for(int i=0; i<n; i++)
    {
        printf("Profit[%d]: ",i);
        scanf("%d",&profit[i]);

        printf("Weight[%d]: ",i);
        scanf("%d",&weight[i]);

        ratio[i] = (float)profit[i] / weight[i];
    }

    printf("\nPROFIT: ");
    for(int i=0; i<n; i++)
        printf("%d\t",profit[i]);

    printf("\nWEIGHT: ");
    for(int i=0; i<n; i++)
        printf("%d\t",weight[i]);

    printf("\nRATIO: ");
    for(int i=0; i<n; i++)
        printf("%.2f\t",ratio[i]);


    printf("\n\nEnter Knapsack Capacity: ");
    scanf("%d",&W);

    // Copy Arrays
    int profit_1[n], profit_2[n], profit_3[n];
    int weight_1[n], weight_2[n], weight_3[n];
    float ratio_1[n], ratio_2[n], ratio_3[n];

    for(int i=0; i<n; i++)
    {
        profit_1[i] = profit_2[i] = profit_3[i] = profit[i];
        weight_1[i] = weight_2[i] = weight_3[i] = weight[i];
        ratio_1[i] = ratio_2[i] = ratio_3[i] = ratio[i];
    }

    float profit_max = 0.0;
    float weight_max = 0.0;
    float ratio_max = 0.0;

    int choice;

while(1)
{
    printf("\n\n1. Greedy about Profit");
    printf("\n2. Greedy about Weight");
    printf("\n3. Greedy about Ratio");
    printf("\n4. Exit");

    printf("\nEnter Choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            bubblesort(profit_1, weight_1, ratio_1, n, 1);

            profit_max = total(profit_1, weight_1, ratio_1, n, W);

            printf("\nMaximum Profit (Profit Greedy): %.2f\n", profit_max);
            break;

        case 2:
            bubblesort(profit_2, weight_2, ratio_2, n, 2);

            weight_max = total(profit_2, weight_2, ratio_2, n, W);

            printf("\nMaximum Profit (Weight Greedy): %.2f\n", weight_max);
            break;

        case 3:
            bubblesort(profit_3, weight_3, ratio_3, n, 3);

            ratio_max = total(profit_3, weight_3, ratio_3, n, W);

            printf("\nMaximum Profit (Ratio Greedy): %.2f\n", ratio_max);
            break;

        case 4:
            printf("\nProgram Ended.\n");
            return 0;

        default:
            printf("\nInvalid Choice!\n");
    }
}


    return 0;
}
