template <class T> class BTree;//二叉树类
template <class T> class BSTree;//二叉排序树类
template <class T>
class BTreeNode
{  friend  class BTree <T>;
   friend  class BSTree <T>;
   T  data;
   BTreeNode<T> *lchild,*rchild;
 public:
   BTreeNode():lchild(NULL),rchild(NULL){}
   BTreeNode(T d, BTreeNode<T> *l=NULL, BTreeNode<T> *r=NULL)
     :data(d),lchild(l),rchild(r){}
   BTreeNode(BTreeNode &p)
   {
	    data=.data;
		lchild=p.lchild;
		rchild=p.rchild;
   }
   T getdata(){return data;}
   BTreeNode<T> *getleft(){return lchild}//获取左孩子
   BTreeNode<T> *getright(){return rchild}//获取右孩子
   BTreeNode<T>*operator=(BTreeNode<T>*p)
   {
	    data=p->data;
		lchild=p->lchild;
		rchild=p->rchild;
		return this;
   }
};
