#include<iostream>
using namespace std;
#include"HafuMan.h"
void main(void)
{
     int i,j,n=7;
     int weight[]={1,4,5,7,6,11,10};
     HaffNode*myHaffTree=new HaffNode[2*n+1];
     Code*myHaffCode=new Code[n];
     if(n>MaxN)
		{
		cout<<"定义的n越界，修改MaxN!"<<endl;
		exit(1);
		}
	Haffman(weight,n,myHaffTree);
	HaffmanCode(myHaffTree,n,myHaffCode);
//输出每个叶结点的哈夫曼编码
	cout<<"1,4,5,7,6,11,10为权值的哈夫曼编码是："<<endl;
	for(i=0;i<n;i++)
	{
	cout<<"Weight="<<myHaffCode[i].weight<<"  "<<"Code=";
	for(j=myHaffCode[i].start+1;j<n;j++)
		cout<<myHaffCode[i].bit[j];
	cout<<endl;
	}
	
}

