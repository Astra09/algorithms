#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int edges[100][100];
int V;
int find_min_vertex(int distance[], bool visited[])
{
    int min=INT_MAX, min_index;

    for(int v=0;v<V;v++)
    {
        if(!visited[v] && distance[v]<min)
            min=distance[v], min_index=v;
    }
    return min_index;
}

void dijkstra()
{
    int distance[V];
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=find_min_vertex(distance,visited);
        visited[u]=true;
        for(int v=0;v<V;v++)
        {
            if(!visited[v] && edges[u][v])
            {
                int dist=distance[u]+edges[u][v];
                if(dist<distance[v])
                {
                    distance[v]=dist;
                }
            }
        }
    }
    printf("Result:-\n");
    for(int i=0;i<V;i++)
    {
        printf("%d---->%d\n",i,distance[i]);
    }
}
int main()
{
    int e,s,d,val;
	printf("Enter the number of vertex\n");
	scanf("%d",&V);
	for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    printf("Enter the source, destination and weight respectively\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d%d",&s,&d,&val);
        edges[s][d]=val;
        edges[d][s]=val;
    }
	dijkstra();
	return 0;
}
