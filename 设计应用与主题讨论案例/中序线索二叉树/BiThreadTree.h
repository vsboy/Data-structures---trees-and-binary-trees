template<class T> class BiThreadTree
{
	protected:
		BiTThreadNode<T>*root;
		BiTThreadNode<T>*current;
	public:
		BiThreadTree(BiTThreadNode<T>*&t)//构造函数
		{
			root=t;
			current=root;
		}
		~BiThreadTree(){}
		T &VData()//返回结点数据值
		{
			if(root==NULL)
			{
				cout<<"二叉树为空"<<endl;
				exit(0);
			}
			return current->data;
		}
		virtual BiTThreadNode<T>* Next(BiTThreadNode<T>*t)=0;//后继结点
};