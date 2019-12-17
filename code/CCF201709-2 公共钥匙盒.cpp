#include<cstdio>
#include<cstdlib>
struct key{
	int id;
	int st;
	int it;
	key* next;
}key;


int main(void)
{
	struct key* ke,*head,*head2,*temp3;
	int i,N,K;
	int w,s,c;
	scanf("%d %d",&N,&K);
//	initk(&ke,N);
	struct key*temp;	
	temp=(struct key*)malloc(sizeof(struct key));
	temp->id=1;
	temp->st=0;
	temp->it=0;
	temp->next=NULL;
	ke=temp;;
	head=ke;
	temp3=head;
	for(i=1;i<N;i++)
	{
		struct key* temp1;
		temp1=(struct key*)malloc(sizeof(struct key));
		temp1->id=i+1;
		temp1->st=0;
		temp1->it=0;
		temp1->next=NULL;
		head->next=temp1;
		head=temp1;
	 } 
	head=ke;
/*	for(i=0;i<N;i++)
	{
		printf("%d ",head->id);
		head=head->next;
	}
*/
//	head=ke;
	
	
	
	struct key*cunf,*tt;
	cunf=(struct key*)malloc(sizeof(struct key));
	cunf->id=0;
	cunf->st-0;
	cunf->it=0;
	cunf->next=NULL;
	head2=cunf;
	tt=head;
	for(i=0;i<K;i++)
	{
		struct key* temp2;
		
		temp2=(struct key*)malloc(sizeof(struct key));
		scanf("%d %d %d",&temp2->id,&temp2->st,&temp2->it);
		temp2->next=NULL;
		
		if(head2->id<=temp2->id)
		{
			head2->next=temp2;
			head2=temp2;
		}	
		else
		{
			head2=cunf;
			tt=head2->next;
			while(tt->id<=temp2->id&&tt!=NULL)
			{
				head2=head2->next;
				tt=head2->next;
			}
			if(tt!=NULL)
			{
				temp2->next=tt;
				head2->next=temp2;
				head2=cunf;
			}
		}
		
	}
	head2=cunf->next;
	head=ke;
	
	for(i=1;i<=10000;i++)
	{
		while(head2!=NULL)
		{
			if(i==(head2->st+head2->it))
			{
				while(temp3->id!=0&&temp3!=NULL)
				{
					temp3=temp3->next;
				}
				if(temp3!=NULL)temp3->id=head2->id;
				temp3=head;
			}
			
			if(i==head2->st)
			{
				while(head!=NULL)
				{
					if(head->id==head2->id)
					{
						head->id=0;
					}
					head=head->next;
				}
				head=ke;
			}
			head2=head2->next;

		}
		head2=cunf->next;
	}
	
 head=ke;
	for(i=0;i<N;i++)
	{
		printf("%d ",head->id);
		head=head->next;
	}
}
