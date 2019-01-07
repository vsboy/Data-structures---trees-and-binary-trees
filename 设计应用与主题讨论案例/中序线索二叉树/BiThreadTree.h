template<class T> class BiThreadTree
{
	protected:
		BiTThreadNode<T>*root;
		BiTThreadNode<T>*current;
	public:
		BiThreadTree(BiTThreadNode<T>*&t)//���캯��
		{
			root=t;
			current=root;
		}
		~BiThreadTree(){}
		T &VData()//���ؽ������ֵ
		{
			if(root==NULL)
			{
				cout<<"������Ϊ��"<<endl;
				exit(0);
			}
			return current->data;
		}
		virtual BiTThreadNode<T>* Next(BiTThreadNode<T>*t)=0;//��̽��
};