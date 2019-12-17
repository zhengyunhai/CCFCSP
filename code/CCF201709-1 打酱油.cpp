#include<cstdio>
int main(void)
{
	int N;
	int c1,c2,r1,r2,s1,s2,p1,p2,sum;
	sum=0;
	scanf("%d",&N);
	N=N/10;
	if(N>=5)
	{
		r1=N/5;
		N=N%5;
		p1=r1*2;
		sum=r1*5+p1;
	}
	if(N>=3)
	{
		r2=N/3;
		N=N%3;
		p2=r2;
		sum=sum+r2*3+p2;
	}
	if(N<3)
	{
		sum=sum+N;
	}
	printf("%d",sum);
 } 
