#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define inf 99999
int bellman(int v,int e,int g[][3],int src){
	int dist[v];
	for(int i=0;i<v;i++)
	    dist[i]=inf;
	dist[src]=0;
	for(int i=0;i<v-1;i++){
		for(int j=0;j<e;j++){
			if(dist[g[j][0]]!=inf &&dist[g[j][0]]+g[j][2]<dist[g[j][1]])
			     dist[g[j][1]]=dist[g[j][0]]+g[j][2];
		}
	}
	for(int j=0;j<e;j++){
		if(dist[g[j][0]]+g[j][2]<dist[g[j][1]])
		   printf("\n Negative cycles present in the graph");	
	}
	printf("Minimum distance from source vertex to all vertices");
	for(int i=0;i<v;i++)
	    printf("\n %d -%d -> %d",src,i+1,dist[i]);
}
int main(){
	int v,e,src;
	printf("\n Enter the no.of vertices,no.of edges and source vertex");
	scanf("%d%d%d",&v,&e,&src);
	int g[e][3];
	printf("\n Enter source vertex destination vertex and its distance");
	for(int i=0;i<e;i++){
		for(int j=0;j<3;j++){
		scanf("%d",&g[i][j]);
	}
}
	bellman(v,e,g,src);
	
}
