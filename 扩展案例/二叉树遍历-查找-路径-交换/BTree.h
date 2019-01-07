#include"BTreeNode.h"
template <class T>
class BTree
 {
	T *a; //��Ž����Ϣ��һά����
	int n;//������
   BTreeNode<T> *build0(int i);
 protected:
   BTreeNode<T> *root;
 public:
   BTree(BTreeNode<T> *p=NULL){ copybt(root,p);}
   BTree(T a[],int n);
   int  num();
   static int  num(BTreeNode<T> *p);
   int  dep();
   static int  dep(BTreeNode<T> *p);
   static int countleaf(BTreeNode<T> *p);
   int countleaf();
   void inorder(void visit(T item));
   static void inorder(BTreeNode<T> *p,void visit(T item));
   //����ͺ��������Ӧ��д��
   static void prnt(BTreeNode<T> *p, int l);
   void prnt(){prnt(root,1);}
   static BTreeNode<T>* locate(BTreeNode<T>* p,T elem);//��������ֵΪelem�Ľ��
   BTreeNode<T>* locate(T elem);
   static void exchange(BTreeNode<T>* p);//����������������
   void exchange();
   static void search(BTreeNode<T> *p,BTreeNode<T> a[],int height);//�����·��
   void search(BTreeNode<T> a[],int height);
   static void layvisit(BTreeNode<T> *p,BTreeNode<T> *a[],int n);//������α�����ŵ�����
   void layvisit(BTreeNode<T> *a[],int n);
   static void Vprnt(BTreeNode<T> *p,BTreeNode<T> *a[],int n,int high);// ���������
   void Vprnt(BTreeNode<T> *a[],int n,int high);

 };
template <class T>
BTree<T>:: BTree(T a[],int n)
{ this->a=a; this->n=n;
  root=build0(1);
}
template <class T>
BTreeNode<T> * BTree<T>::build0(int i)
{
	BTreeNode<T> *p; int l,r;
	if ((i <= n) && (a[i-1]!=' '))
	{
		p=new BTreeNode<T>; p->data=a[i-1];
		l=2*i;  r=2*i+1;
		p->lchild=build0(l);
		p->rchild=build0(r);
		return(p);
	}
  else
      return(NULL);
}
template <class T>
int BTree<T>::num(BTreeNode<T> *p)
{ 
	if(p==NULL)return(0);
	else 
		return(num(p->lchild)+num(p->rchild)+1);
}
template <class T>
int BTree<T>::num()
{ 
	return(num(root));
}
template <class T>
int BTree<T>::dep(BTreeNode<T> *p)
{ 
  int max;
  if(p==NULL)return(0);
  else {
		max=dep(p->lchild);
        if (dep(p->rchild)>max) max=dep(p->rchild);
        return(max+1);
       }
}
template <class T>
int BTree<T>::dep()
{ 
	return(dep(root));
}
template <class T>
int BTree<T>::countleaf()
{ 
	return(countleaf(root));
}
template <class T>
int BTree<T>::countleaf(BTreeNode<T> *p)
{
	if(p==NULL)return(0);
	if(p->lchild==NULL&& p->rchild==NULL) return(1);
	else
	return(countleaf(p->lchild)+countleaf(p->rchild));
}

template <class T>
void BTree<T>::prnt(BTreeNode<T> *p, int l)
{ if (p!=NULL )
  { prnt(p->rchild,l+1);
    for (int i=0;i<6*(l-1);i++)cout<<" ";
    cout<<"..."<<p->data<<endl;
    prnt(p->lchild,l+1);
  }
}
template <class T>
void BTree<T>::inorder(void visit(T item))
{ inorder(root,visit);  cout<<endl;
}
template <class T>
void BTree<T>::inorder(BTreeNode<T> *p,
                       void visit(T item))
{ if (p!=NULL )
  { inorder(p->lchild,visit);
    visit(p->data);
    inorder(p->rchild,visit);
  }
}
template<class T>
BTreeNode<T>* BTree<T>::locate(BTreeNode<T>* p,T elem)
{
	if(p==NULL) return NULL;
	else if(p->data==elem) return(p);
	else
	{
		BTreeNode<T>*q=locate(p->lchild,elem);
		if(q!=NULL) 
			return q;
		else
		return(locate(p->rchild,elem));
		
	}
}
template<class T>
BTreeNode<T>* BTree<T>::locate(T elem)
{
		BTreeNode<T> *p;
		p=locate(root,elem);
		return(p);
}
template <class T>
void BTree<T>::search(BTreeNode<T> *p,BTreeNode<T> a[],int height)
{
	int k=0;
	if(p==NULL)
	cout<<"�������� "<<endl;
	while(k>=0 && k<height)
	{
		while(p)
		{
			a[k].data=p->data;
			a[k].lchild=p->lchild;
			a[k].rchild=p->rchild;
			k++;
			p=p->lchild;
		}
		if(p==NULL&&k<height)
		{
			{
				k--;
				p=a[k].rchild;
				while(p==NULL)
				{
					k--;
					p=a[k].rchild;
				}
				k++;
			}
		}
	}
	for(int i=0;i<k-1;i++)
		cout<<a[i].data<<"--->";
		cout<<a[k-1].data<<endl;
}
template <class T>
void BTree<T>::search(BTreeNode<T> a[],int height)
{
	search(root,a,height);
}
template<class T>
void BTree<T>::exchange(BTreeNode<T>* p)
{
	if(p)
	{
		exchange(p->lchild);
		exchange(p->rchild);
		BTreeNode<T>* q;
		q=p->lchild;
		p->lchild=p->rchild;
		p->rchild=q;
	}
}
template<class T>
void BTree<T>::exchange()
{
	exchange(root);
}
template<class T>
void BTree<T>::layvisit(BTreeNode<T> *p,BTreeNode<T> *a[],int n)
{
	int front,rear;
	BTreeNode<T> *q;
	front=rear=0;
	if(p)
	{
		a[rear]=p;
		rear++;
		while(rear<n)
		{
			q=a[front];
			if(q)
			{
				a[rear++]=q->lchild;
				a[rear++]=q->rchild;
				front++;
			}
			else
				front++;
		}
	}
}
template<class T>
void BTree<T>::layvisit(BTreeNode<T> *a[],int n)
{
	layvisit(root,a,n);
}
template<class T>
void BTree<T>::Vprnt(BTreeNode<T> *p,BTreeNode<T> *a[],int n,int high)
{
	int first,firstleft,linestep;
	//first��ʾÿһ����Ԫ�ص��±ꣻ
	//firstleft��ʾ��Ԫ�ؾ�����Ļ��ߵľ��룻
	//linestep��ʾÿ��Ԫ��֮��ļ��
	//high��ʾ���Ĳ�������߶�
	for(int i=1;i<=high;i++)
		//��ӡ��Ԫ��
	{	
		firstleft=(pow(2,(high-i)*1.0)-1)*2;//������Ԫ�ص���ʼλ��
		for(int j=1;j<=firstleft;j++)
			cout<<" ";
			first=pow(2,(i-1)*1.0)-1;//��Ԫ�ص��±�
			if(a[first])//��������
				cout<<setw(2)<<a[first]->getdata();
			else//������
				cout<<setw(2)<<" ";
		//��ӡͬ�е�����Ԫ��
		for(int k=pow(2,(i-1)*1.0)+1;k<=pow(2,i*1.0)-1;k++)
		{
			linestep=pow(2,(high-i)*1.0)*4;//�������Ԫ�ؼ��
			if(a[k-1])//��������
				cout<<setw(linestep)<<a[k-1]->getdata();
			else
				cout<<setw(linestep)<<" ";
		}
		//���д�ӡ��ϣ�����
		cout<<endl;
	}
}
template<class T>
void BTree<T>::Vprnt(BTreeNode<T> *a[],int n,int high)
{
	Vprnt(root,a,n,high);
}
