#include<stdio.h>

float knapsack(int num,float weight[],float profit[],float capacity)
{
	float x[20],tp=0;
	int i,j,u;
	u=capacity;
	for(i=0;i<num;i++)
		x[i]=0.0;
		
	for(i=0;i<num;i++)
	{
		if(weight[i]>u)
			break;
		else{
			x[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
	}
	}
	if ( i < num)
	  x[i]=u/weight[i];
	tp=tp+(x[i]*profit[i]);
	printf("The resultant vector :");
	for(i=0;i<num;i++)
	{
		printf("%f\t",x[i]);
	}
	printf("\nTotal profit %f",tp);
}
int main()
{
	float profit[20],weight[20],capacity;
	int num,i,j;
	float ratio[20],temp;
	
	printf("Enter number of elements :");
	scanf("%d",&num);
	printf("Enter weights and profits :");
	for(i=0;i<num;i++)
	{
		scanf("%f %f",&weight[i],&profit[i]);
	}
	printf("Enter capacity of tank :");
	scanf("%f",&capacity);
	for(i=0;i<num;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[j]=temp;
				
			}
		}
	}
	knapsack(num,weight,profit,capacity);
	return(0);
}
