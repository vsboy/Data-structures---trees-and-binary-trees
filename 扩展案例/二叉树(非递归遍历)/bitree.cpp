//�������еĳ�Ա�������ļ���Ϊbitree.cpp
#include<iostream>
#include<string>
#include"bitree.h"
#include"SeqStack.h"
using namespace std;

/*
 *ǰ��������������������
 *��    �룺��
 *��    �ܣ�����һ�ö�����
 *��    ������
 *��������������һ�ö����� 
 */
template<class T>
BiTree<T>::BiTree( )
{
	this->root = Creat( );
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷŶ��������и����Ĵ洢�ռ�
 *��    ������
 *���������������������� 
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ���ȡָ�������������ָ��
 *��    ����ָ�������������ָ��
 *�������������������� 
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot( )
{
	return root;
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�����������
 *��    �����������н���һ����������
 *�������������������� 
 */
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if(root==NULL)  return;
	else{		
		cout<<root->data<<" ";
        PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //�ݹ���õĽ�������	          
    else{	
        InOrder(root->lchild);    //����ݹ����root��������
        cout<<root->data<<" ";    //���ʸ�����������
        InOrder(root->rchild);    //����ݹ����root��������
	}
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //�ݹ���õĽ�������
    else{	
        PostOrder(root->lchild);    //����ݹ����root��������
        PostOrder(root->rchild);    //����ݹ����root��������
        cout<<root->data<<" ";      //���ʸ�����������
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //����˳����У����ٶ����ᷢ������

	BiNode<T>* Q[MaxSize];
    BiNode<T>* q;

	if (root==NULL) return;
	else{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
     		cout<<q->data<<'\t'; 		
    		if (q->lchild != NULL)    Q[rear++] = q->lchild;		
			if (q->rchild != NULL)    Q[rear++] = q->rchild;
		}
	}
}

/*
 *ǰ���������ն�����
 *��    �룺����ch;
 *��    �ܣ���ʼ��һ�ö�����,���캯������
 *��    ������
 *��������������һ�ö�����
 */
template <class T>
BiNode<T>* BiTree<T>::Creat( )
{
	BiNode<T>* root;
	T ch;
	cout<<"�����봴��һ�ö������Ľ������"<<endl;
	cin>>ch;
    if (ch=="#") root = NULL;
    else{ 
	     root = new BiNode<T>;       //����һ�����
         root->data=ch;
         root->lchild = Creat( );    //�ݹ齨��������
         root->rchild = Creat( );    //�ݹ齨��������
    } 
    return root;
}

/*
 *ǰ���������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
 *��    ������
 *����������������������
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //�ͷ�������
      Release(root->rchild);   //�ͷ�������
      delete root;
  }  
}
template<class T>
void BiTree<T>::NrecursionPreOrder(BiNode<T> *root)
{
	SeqStack<BiNode<T>*> S;
	BiNode<T>*p;
	p=root;
	while(p!=NULL || S.Empty()!=1)
	{
		while(p!=NULL)
		{
			cout<<p->data<<'\t';
			S.Push(p);
			p=p->lchild;
		}
		if(S.Empty()!=1)
		{
			p=S.Pop();
			p=p->rchild;
		}
	}
}
template<class T>
void BiTree<T>::NrecursionInOrder(BiNode<T> *root)
{
	SeqStack<BiNode<T>*> S;
	BiNode<T>*p;
	p=root;
	while(p!=NULL || S.Empty()!=1)
	{
		while(p!=NULL)
		{
			S.Push(p);
			p=p->lchild;
		}
		if(S.Empty()!=1)
		{
			p=S.Pop();
			cout<<p->data<<'\t';
			p=p->rchild;
		}
	}
}
template<class T>
void BiTree<T>::NrecursionPostOrder(BiNode<T> *root)
{
	SeqStack<BiNode<T>*> S;
	BiNode<T>*p;
	p=root;
	while(p!=NULL||S.Empty()!=1)
	{
		while(p!=NULL)
		{
			p->flag=1;
			S.Push(p);
			p=p->lchild;
		}
		while(S.Empty()!=1 && S.GetTop()->flag==2)
			cout<<S.Pop()->data<<'\t';
		if(S.Empty()!=1)
		{
			S.GetTop()->flag=2;
			p=S.GetTop()->rchild;
		}
	}
}
template<class T>
void BiTree<T>::countNode(BiNode<T> *root,int& count)
{
	if(root)
	{
		countNode(root->lchild,count);
		count++;
		countNode(root->rchild,count);
	}
}
template<class T>
int BiTree<T>::depth(BiNode<T> *root)
{
	int l,r;
	if(root==NULL) 
		return  0;
	 l=depth(root->lchild);
	 r=depth(root->rchild);
	return l>r ?l+1:r+1;
}
