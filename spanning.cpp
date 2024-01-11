#include<stdio.h>
#include<stdlib.h>

int min,adj[10][10],parent[10];
int i,j,a,b,u,v;
int n,ne=1,mincost=0;
int find(int i)
{
	while(parent[i])
	{
	i=parent[i];
	}
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

int main()
{
	printf("Enter number of vertices:");
	scanf("%d",&n);
	printf("\n enter the cost adjacency matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==0)
				adj[i][j]=999;
		}
	}
	printf("The edges if min cost spanning tree \n:");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;i<=n;i++)
			{
				if(adj[i][j]<min)
				{
					min=adj[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d %d)=%d ",ne++,a,b,min);
			mincost+=min;
		}
		adj[a][b]=adj[b][a]=999;
	}
	printf("min cost %d",mincost);
}
