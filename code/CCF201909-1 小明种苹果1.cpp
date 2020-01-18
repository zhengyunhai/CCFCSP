#include<iostream>
#include<math.h>
using namespace std;

struct apptre{
	int appnum;
	int putdownnum;
}apptre; 

int main(void)
{
	int N,M;
	cin>>N>>M;//N为棵数，M为轮数
	int app[N][M+3];
	for(int i=0;i<N;i++)
	{
		app[i][M+1]=0;
		app[i][M+2]=0;
		for(int j=0;j<M+1;j++)
		{
			cin>>app[i][j];//0或负数 
		}
		for(int j=1;j<M+1;j++)
		{
			app[i][M+1]=app[i][M+1]+abs(app[i][j]);//去除 
		}
		app[i][M+2]=app[i][0]-app[i][M+1];//剩余 
	}
	int max= abs(app[0][M+1]); 
	int id,appsum;
	appsum=0;
	for(int i=0;i<N;i++) 
	{
		appsum=appsum+app[i][M+2];
		if(app[i][M+1]>=max)
		{
			max= abs(app[i][M+1]); 
			id=i+1;
		}
	}
	cout<<appsum<<" "<<id<<" "<<max; 
} 
