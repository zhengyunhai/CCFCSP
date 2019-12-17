#include<cstdio>
#include<cstdlib>
int po(int* dui,int n,int p)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(dui[i]==p) return i;
	}
}

void mov(int* dui,int pos,int q)
{
	int temp,i,c;
	c=pos;
	temp=dui[pos];
	if(q>0)
	{
		for(i=0;i<q;i++)
		{
			dui[pos]=dui[pos+1];
			pos++;
		}
		dui[c+q]=temp;
	}
	else
	{
		q=-q;
		for(i=0;i<q;i++)
		{
			dui[pos]=dui[pos-1];
			pos--;
		}
		dui[c-q]=temp;
	}
	
	
}
int main(void)
{
	int n,m,p,q,i,j,k,pos;
	char temp;
	scanf("%d",&n);
	scanf("%d",&m);
	int dui[n];
	for(i=0;i<n;i++)
	{
		dui[i]=i+1;
	}
/*	for(i=0;i<n;i++)
	{
		printf("%d ",dui[i]);
	}
*/	
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&p,&q);
		pos=po(dui,n,p);
		mov(dui,pos,q);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",dui[i]);
	}

}
