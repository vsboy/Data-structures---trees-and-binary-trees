template<class T>
class InThreadBTree:public BiThreadTree<T>
{
	private:
		void InThread(BiTThreadNode<T>*&current,BiTThreadNode<T>*&pre)//线索化
		{
			if(current!=NULL)
			{
				InThread(current->Left(),pre);
				if(current->Left()==NULL)
				{
					current->LTag=1;
					current->Left()=pre;
				}
				if(pre->Right()==NULL)
				{
					pre->RTag=1;
					pre->Right()=current;
				}
				pre=current;
				InThread(current->Right(),pre);
			}
		}
	public:
		InThreadBTree(BiTThreadNode<T>*&tree):BiThreadTree<T>(tree)//构造函数,注意!!调用基类的构造函数必须用冒号书写格式
		{
		
		}
		void CreateInThread()
		{
			BiTThreadNode<T>*t=root;
			root=new BiTThreadNode<T>();
			root->LTag=0;
			root->RTag=1;
			if(t==NULL)
			{
				root->Left()=root;
				root->Right()=root;
			}
			else
			{
				root->Left()=t;
				current=t;
				BiTThreadNode<T>*pre=root;
				InThread(current,pre);
				pre->Right()=root;
				pre->RTag=1;
				root->Right()=pre;
			}
		}
		virtual BiTThreadNode<T>* Next(BiTThreadNode<T>*t)//后继结点
		{
			if(t==NULL) return NULL;
			else
			{
				
				if(t->RTag==1)
					return t->Right();
				else
				{
					BiTThreadNode<T>*p=t->Right();
					while(p->LTag==0)
						p=p->Left();
					return p;
				}
			}
		}
};

				




