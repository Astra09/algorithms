#include<stdio.h>
int max(int,int);
int knapsack(int,int[],int[],int);
int max(int a,int b)
{
    return (a>b)?a:b;
}
int knapsack(int W, int wt[], int val[], int n)
{
    int i,w;
    int k[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0 || w==0)
            {
                k[i][w]=0;
            }
            else if(wt[i-1] <= w)
            {
                k[i][w]=max(val[i-1]+k[i-1][(w-wt[i-1])], k[i-1][w]);
            }
            else
            {
                k[i][w]=k[i-1][w];
            }
        }
    }
    return k[n][W];
}
int main()
{
    int n;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    int wt[n],val[n],W;
    printf("Enter the maximum weight W\n");
    scanf("%d",&W);
    printf("Enter the Value:-\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
    }
    printf("Enter the Weight:-\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&wt[i]);
    }
    printf("Result = %d",knapsack(W,wt,val,n));
    return 0;
}
