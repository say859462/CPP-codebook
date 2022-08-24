#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{
	int i,n,m,j;
	int a[51],b[51];
	int max;
	int temp;
	int count;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	max=0;
	count=0;
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(b[j]%a[i]==0)
			{
				temp=b[j]/a[i];
				if(max<temp)
				{
					max=temp;
					count=1;
				}
				else if(max==temp)
				{
					count++;
				}
			}
		}
	}
 
	printf("%d\n",count);
	
 
	return 0;
}
