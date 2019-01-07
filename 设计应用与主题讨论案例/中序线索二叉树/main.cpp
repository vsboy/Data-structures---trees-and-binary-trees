#include<iostream>
using namespace std;
#include"BiTThreadNode.h"
#include"CreateThTree.h"
#include"BiThreadTree.h"
#include"InThreadBTree.h"
template<class T>
BiTThreadNode<T>*Search(BiTThreadNode<T>*p,T item)//����Ԫ��ֵΪitem�Ľ��
{
			if(p==NULL) return NULL;
			if(p->data==item) return p;
			BiTThreadNode<T>*temp;
			if((temp=Search(p->Left(),item))!=NULL) return temp;
			if((temp=Search(p->Right(),item))!=NULL) return temp;
}
void main()
{
	BiTThreadNode<char>*root,*p,*q;
	MyBTree(root);
	p=Search(root,'F');
	InThreadBTree<char>thread(root);
	thread.CreateInThread();
	q=thread.Next(p);
	cout<<p->data<<"����������"<<q->data<<endl;
}