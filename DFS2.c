#include<stdio.h>
#include<stdbool.h>

int edges[100][100];

void print(int n,int sv,bool *visited)
{
    printf("%d-->",sv);
    visited[sv]=true;
    for(int i=1;i<=n;i++)
    {
        if(edges[sv][i] && !visited[i] && i!=sv)
        {
            print(n,i,visited);
        }
    }
}

int  main()
{
    int n,e;
    printf("Enter the number of edges and vertex respectively:-\n");
    scanf("%d%d",&n,&e);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            edges[i][j]=0;
        }
    }
    printf("Enter the source and destination of the connected vertices respectively:-\n");
    for(int i=1;i<=e;i++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        edges[s][d]=1;
        edges[d][s]=1;
    }
    bool visited[n];
    for(int i=1;i<=n;i++)
    {
        visited[i]=false;
    }
    print(n,1,visited);
    return 0;
}
