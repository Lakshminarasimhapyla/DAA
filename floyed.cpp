#include<stdio.h>
#include<stdlib.h>
#define inf 999
#define v 4

void printsolution(int dist[][v])
{
	int i,j;
	printf("the resultant adgacent matrix : \n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(dist[i][j]== inf)
				printf("%5s","inf");
			else
				printf("%5d",dist[i][j]);
		}
		printf("\n");
	}
}
void floyed(int dist[][v])
{
	int i,j,k;
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printsolution(dist);
}


int main()
{
	int i,j;
	int graph[v][v];
	printf("Enter the adjacency matrix for the  graph (%d x %d):\n",v,v);
	printf("Enter -1 to represent infinity :\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==-1)
				graph[i][j]=inf;
		}
	}
	floyed(graph);
	return 0;
}
