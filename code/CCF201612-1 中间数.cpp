#include<cstdio>
int lessc(int* dl,int len,int m)
{
	int cl,i;
	cl=0;
	for(i=0;i<len;i++)
	{
		if(dl[i]<m) cl++;
	}
	return cl;
}

int greatc(int* dl,int len,int m)
{
	int gc,i;
	gc=0;
	for(i=0;i<len;i++)
	{
		if(dl[i]>m)gc++;
	}
	return gc;
}

int midv(int *dl,int len)
{
	int i,temp,gc,cl,m;
	int count=1;
	gc=0;cl=0;m=0;
	while(count!=0)
	{
		count=0;
		for(i=0;i<len;i++)
		{
			if(dl[i]>dl[i+1])
			{
				temp=dl[i];
				dl[i]=dl[i+1];
				dl[i+1]=temp;
				count++;
			}
		}
	}
	if(len%2==1&&dl[len/2]!=dl[len/2+1]&&dl[len/2+1]!=dl[len/2+2]&&dl[len/2]!=dl[len/2+2]) 
	{
		m++;
		return dl[len/2+1];
	}
	if(len%2==0)
	{
		for(i=0;i<len/2+1;i++)
	{
		if(dl[i]<dl[len/2]) cl++;
	}
	for(i=len/2;i<len;i++)
	{
		if(dl[i]>dl[len/2])gc++;
	}
	if(cl==gc) 
	{
		m++;
		return dl[len/2];
	}
	}
	if(m==0)return -1;
	
}
int main(void)
{
	int n,i,cl,cg,c;
	cl=0;cg=0;c=0;
	scanf("%d",&n);
	int dl[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&dl[i]);
	}
	c=midv(dl,n);
	printf("%d",c);
}
