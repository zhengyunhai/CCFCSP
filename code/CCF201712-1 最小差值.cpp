#include<cstdio>
void ms(int *a,int n)//�������� 
{
	int max;
	int lop=1;
	int temp;
	int i;
	while(lop)
	{
	lop=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1]) {
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
			lop++;	
		} 
	}
 } 
}
int absv(int a)
{
	if(a>=0) return a;
	else return -a;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n-1]={0}; 
	int min;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	//����
	ms(a,n);

	//�������ڲ�ֵ�������С 
	 for(i=0;i<n-1;i++)
	 {
	 	b[i]=absv(a[i+1]-a[i]);
	  } 
	  ms(b,n-1);
	  printf("%d",b[0]); 
 } 
