#include<cstdio>
#include<cstdlib>
struct dg{
	int id;
	int wei;
	dg* next;
}dg;

int main(void)
{
	int n,k,count,ws;
	count=0;
	ws=0;
	scanf("%d %d",&n,&k);
	int i;
	struct dg* dang,*head;
	dang=(struct dg*)malloc(sizeof(struct dg));
	dang->id=0;
	dang->wei=0;
	dang->next=NULL;
	head=dang;
	for(i=0;i<n;i++)
	{
		struct dg*temp;
		temp=(struct dg*)malloc(sizeof(struct dg));
		temp->id=i+1;
		scanf("%d",&temp->wei);
		temp->next=NULL;
		head->next=temp;
		head=temp;
	}
	head=dang->next;
	struct dg* ptr;
	ptr=head;
	while(head!=NULL)
	{
		while(ws<k&&head!=NULL)
		{
			ws=ws+head->wei;
			head=head->next;
		 } 
		if(ws>=k)
		{
			count++;
		}
		if(ws<k&&head==NULL)count++;
		ws=0;
	}
	printf("%d",count);
}
