//�����������������ļ���Ϊbitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

void main()
{	
	cout<<"�����봴��һ�ö������Ľ������,��������ԭ�򣬿ս����#����"<<endl;
	BiTree<string> bt; //����һ����
	BiNode<string>* root = bt.Getroot( );  //��ȡָ�������ָ�� 

	cout<<"------ǰ�����------ "<<endl;
	bt.PreOrder(root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	bt.InOrder(root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	bt.LeverOrder(root);
	cout<<endl;
}