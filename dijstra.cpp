#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 9999

int mindist(int dist[],int visited[],int n)
{
  int mi=0;
  int min=inf;
  for(int i=0;i<n;i++)
    {
       if(dist[i] < min && !visited[i])
       {
         min = dist[i];
         mi=i;
       }
    }
  return mi;
}

int main()
{
  int n;
  printf("Enter no.of vertices : ");
  scanf("%d",&n);
  int graph[n][n];
  printf("Enter the adj matrix :  \n");
  for (int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        {
          scanf("%d",&graph[i][j]);
          if (graph[i][j]==-1)
            graph[i][j]=inf;
        }
    }
  int dist[n],visited[n],edges=0;
	for(int i=0;i<n;i++)
	{
		dist[i]=inf;
		visited[i]=0;
	}
  dist[0]=0;

  while(edges < n-1)
    {
      int min = mindist(dist,visited,n);
      visited[min]=1;
      for(int i=0;i<n;i++)
        {
          if(dist[min] + graph[min][i] < dist[i] && !visited[i])
          {
            dist[i] = dist[min] + graph[min][i];
          }
        }
      edges++;
    }
  printf("Vertex cost is: ");
  for(int i=0;i<n;i++)
    {
      printf("%d  %d \n",i+1,dist[i]);
    }
  return 0;
}
