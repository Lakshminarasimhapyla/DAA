#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ptr_pref_suf(char* ptr,int m,int* pps)
{
	int length=0;
	int i=1;
	pps[0]=0;
	while(i<m)
	{
		if(ptr[i]==ptr[length])
		{
			length++;
			pps[i]=length;
			i++;
		}
		else if(length!=0)
		{
			length=pps[length-1];
		}
		else 
		{
			pps[i]=0;
			i++;
		}
	}
}
void kmp(char *text,char * ptr)
{
	int n=strlen(text);
	int m=strlen(ptr);
	int pps[m];
	ptr_pref_suf(ptr,m,pps);
	int i=0,j=0;
	while(i<n)
	{
		if(text[i]==ptr[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			printf("Pattern found at index %d \n ",(i-j));
			j=pps[j-1];
		}
		else if(text[i]!=ptr[j])
		{
			if(j==0)
				i++;
			else
				j=pps[j-1];
		}
	}
}
int main()
{
	char text[]="abababcababd";
	char ptr[]="ababd";
	kmp(text,ptr);
	
}
