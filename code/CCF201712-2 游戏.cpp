#include<cstdio>
#include<cstdlib>
struct dl{
	int id;
	int num;
	dl* pre;
	dl* next;
}dl;

void gendl(struct dl*temp,int n)
{
	int i;
	struct dl* r=temp;
	struct dl* head;
	head=r;
	for(i=0;i<n;i++)
	{
		struct dl* temp1;
		temp1=(struct dl*)malloc(sizeof(struct dl));
		temp1->id=i+2;
		temp1->num=0;
		temp1->next=NULL;
		r->next=temp1;
		temp1->pre=r;
		r=temp1;
	}
	r->next=head;
	head->pre=r;
}

int pd(int a,int k)
{
	int b,c;
	b=a%k;
	c=a%10;
	if(b==0)return 1;
	else if(c==k)return 1;
	else return 0;
}

int main(void)
{
	int n,k,count,temp;
	scanf("%d %d",&n,&k);
	count=n;
	struct dl *head,*h,*temp1;
	head=(struct dl*)malloc(sizeof(struct dl));
	h=head;
	head->id=1;
	head->num=1;
	head->pre=NULL;
	head->next=NULL;
	int i;
	gendl(head,n-1); 
/*	for(i=0;i<n;i++)
	 {
	 	printf("%d ",head->num);
	 	head=head->pre;
	 }
*/
	head=h;
	while(count!=1)
	{
		temp=head->num;
		temp1=head;
		head=head->next;
		if(pd(temp1->num,k))
		 	{	
		 		temp1->pre->next=temp1->next;
		 		temp1->next->pre=temp1->pre;
				temp1->pre=NULL;
				temp1->next=NULL;
				free(temp1); 
				count--;
			 }
		head->num=temp+1;
		
		
	 } 
	printf("%d",head->id);
	 
}
