#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#include"BTree.h"
	void printchar(char item)
	{
		cout<<item<<"  ";
	}
void main( )
{

	char *str2="abc df";
	BTree<char>bt2(str2,6);
	char c='f';
	int h=bt2.dep();
	int n;
	n=pow(2,h*1.0)-1;
	BTreeNode<char> *a[50];
	bt2.layvisit(a,n);
	bt2.Vprnt(a,n,h);
	cout<<"��������������£�"<<endl;
	bt2.inorder(printchar);
	cout<<"�������"<<bt2.dep()<<endl;
	cout<<"Ҷ�ӽ�����Ŀ"<<bt2.countleaf()<<endl;
	BTreeNode<char>*p;
	cout<<"������Ҫ���ҵĽ���ֵ"<<endl;
	cin>>c;
	p=bt2.locate(c);
	if(p==NULL)
		cout<<"���в�����������"<<endl;
	else
	cout<<p->getdata()<<endl;
	bt2.exchange();
	cout<<"������Ķ�����"<<endl;
	bt2.layvisit(a,n);
	bt2.Vprnt(a,n,h);
	BTreeNode<char> b[50];
	cout<<"�����·���� "<<endl;
	bt2.search(b,h);

}
