//�����������������ļ���Ϊbitreemain.cpp
#include<iostream>
#include<string>
#include"SeqStack.cpp"
#include"bitree.cpp"
using namespace std;

void main()
{	
	int count=0;
	int l=0,r=0;
	BiTree<string> bt; //����һ����
	BiNode<string>* root = bt.Getroot( );  //��ȡָ�������ָ�� 
	cout<<"------ǰ�����------ "<<endl;
	bt.NrecursionPreOrder(root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	bt.NrecursionInOrder(root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	bt.NrecursionPostOrder(root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	bt.LeverOrder(root);
	cout<<endl;
	bt.countNode(root,count);
	cout<<"������������"<<count<<endl;
	cout<<"�����������"<<bt.depth(root)<<endl;
}