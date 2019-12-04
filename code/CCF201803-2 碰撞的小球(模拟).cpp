#include<iostream>
 using namespace std;
 
 struct ball{
 	int name;//球名 
 	int f;//方向：1右，-1左
	int pos;
	struct ball* next;
 }ball;
 
 int main(void)
 {
 	struct ball* balls,*head,*endn,*temp,*ptr,*pp,*temp1;
 	balls=NULL;
 	int num,len,t,count;
 	int i=1;
 	count=0;//计时 
 	cin>>num>>len>>t;
 	getchar();//输入两行，用作读取换行符 
 //	num=100;len=1000;t=100;
 	int n=2;
 	endn=(struct ball*)malloc(sizeof(struct ball));
 	endn->name=0;
 	endn->f=0;
 	endn->pos=-1;
 	endn->next=NULL;
 	balls=endn;
 	head=endn;
 	while(i<=num)
 	{
  		temp=(struct ball*)malloc(sizeof(struct ball));
  		temp->name=i;
  		temp->f=1;
		cin>>temp->pos;
		//temp->pos=n;
		n=n+2;
		temp->next=NULL;
		endn->next=temp;
		endn=temp;
		i++;
	 }
	//head=head->next;//第一个节点 
	//cout<<endn->name<<" "<<endn->pos<<" "<<endn->f<<endl;
	while(count<t)
	{
		ptr=head->next;
		//更新所有球的位置 
		while(ptr!=NULL)
		{
			ptr->pos=(ptr->pos)+(ptr->f);
			ptr=ptr->next;	
		 }	
		 
		 	 //temp1=head->next;while(temp1!=NULL){cout<<temp1->pos<<" "<<temp1->f<<" || ";temp1=temp1->next;}cout<<endl;
		 
		//判断是否改变方向 
		ptr=head->next; 
		//pp=head->next; 
		while(ptr!=NULL)
		{
			//两种情况，到达端点或有两个球pos相等
			if((ptr->pos==0)||(ptr->pos==len))//到达端点的情况 
			{
				ptr->f=(ptr->f)*(-1);
			 } 
			 ptr=ptr->next;
		}
		
			 	 
		ptr=head->next; 
		while(ptr!=NULL)
		{
			 pp=ptr->next;
			 while(pp!=NULL)//两球不可能在端点相遇，故在链表中搜索与ptr->pos相等的点改变方向即可 
			 {
			 	if(pp->pos==ptr->pos)
			 	{
			 		pp->f=(pp->f)*(-1);
			 		ptr->f=(ptr->f)*(-1);
				 }
				 pp=pp->next;
			 }
			ptr=ptr->next;
		}
		//temp1=head->next;while(temp1!=NULL){cout<<temp1->pos<<" "<<temp1->f<<" || ";temp1=temp1->next;}cout<<endl;

		count++;	
	}
	
	//shuchu
	temp1=head->next;
	while(temp1!=NULL)
	{
		cout<<temp1->pos<<" ";
		temp1=temp1->next;
	 } 	
	//free
	while(balls!=NULL)
	{
		ptr=balls;
		balls=balls->next;
		free(ptr);
	}
 }
