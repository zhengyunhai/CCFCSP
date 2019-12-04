#include<iostream>
//https://blog.csdn.net/tigerisland45/article/details/54755895
using namespace std;

int main(void)
{
	int plus,ste,res;
	plus=0;
	res=0;
	while(cin>>ste)
	{
		res=res+ste;
		if(ste==0) {
		cout<<"res="<<res<<endl;
		return 0;
		}
		if(ste==1) plus=0;
		if(ste==2)
		{
			res=res+plus;
			plus=plus+2;
		}
	}
	//cout<<"res="<<res<<endl;
	
 } 
