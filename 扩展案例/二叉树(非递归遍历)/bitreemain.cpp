//二叉树的主函数，文件名为bitreemain.cpp
#include<iostream>
#include<string>
#include"SeqStack.cpp"
#include"bitree.cpp"
using namespace std;

void main()
{	
	int count=0;
	int l=0,r=0;
	BiTree<string> bt; //创建一棵树
	BiNode<string>* root = bt.Getroot( );  //获取指向根结点的指针 
	cout<<"------前序遍历------ "<<endl;
	bt.NrecursionPreOrder(root);
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	bt.NrecursionInOrder(root);
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	bt.NrecursionPostOrder(root);
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	bt.LeverOrder(root);
	cout<<endl;
	bt.countNode(root,count);
	cout<<"二叉树结点个数"<<count<<endl;
	cout<<"二叉树的深度"<<bt.depth(root)<<endl;
}