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
	cout<<"中序遍历序列如下："<<endl;
	bt2.inorder(printchar);
	cout<<"树的深度"<<bt2.dep()<<endl;
	cout<<"叶子结点的数目"<<bt2.countleaf()<<endl;
	BTreeNode<char>*p;
	cout<<"请输入要查找的结点的值"<<endl;
	cin>>c;
	p=bt2.locate(c);
	if(p==NULL)
		cout<<"树中不存在这个结点"<<endl;
	else
	cout<<p->getdata()<<endl;
	bt2.exchange();
	cout<<"交换后的二叉树"<<endl;
	bt2.layvisit(a,n);
	bt2.Vprnt(a,n,h);
	BTreeNode<char> b[50];
	cout<<"最长的左路径是 "<<endl;
	bt2.search(b,h);

}
