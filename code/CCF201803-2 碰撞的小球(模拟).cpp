#include<iostream>
 using namespace std;
 
 struct ball{
 	int name;//���� 
 	int f;//����1�ң�-1��
	int pos;
	struct ball* next;
 }ball;
 
 int main(void)
 {
 	struct ball* balls,*head,*endn,*temp,*ptr,*pp,*temp1;
 	balls=NULL;
 	int num,len,t,count;
 	int i=1;
 	count=0;//��ʱ 
 	cin>>num>>len>>t;
 	getchar();//�������У�������ȡ���з� 
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
	//head=head->next;//��һ���ڵ� 
	//cout<<endn->name<<" "<<endn->pos<<" "<<endn->f<<endl;
	while(count<t)
	{
		ptr=head->next;
		//�����������λ�� 
		while(ptr!=NULL)
		{
			ptr->pos=(ptr->pos)+(ptr->f);
			ptr=ptr->next;	
		 }	
		 
		 	 //temp1=head->next;while(temp1!=NULL){cout<<temp1->pos<<" "<<temp1->f<<" || ";temp1=temp1->next;}cout<<endl;
		 
		//�ж��Ƿ�ı䷽�� 
		ptr=head->next; 
		//pp=head->next; 
		while(ptr!=NULL)
		{
			//�������������˵����������pos���
			if((ptr->pos==0)||(ptr->pos==len))//����˵����� 
			{
				ptr->f=(ptr->f)*(-1);
			 } 
			 ptr=ptr->next;
		}
		
			 	 
		ptr=head->next; 
		while(ptr!=NULL)
		{
			 pp=ptr->next;
			 while(pp!=NULL)//���򲻿����ڶ˵�����������������������ptr->pos��ȵĵ�ı䷽�򼴿� 
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
