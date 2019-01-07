template<class T> class BiThreadTree;
template<class T> class BiTThreadNode
{
	friend class BiThreadTree<T>;
	private:
		BiTThreadNode<T>*LChild;
		BiTThreadNode<T>*RChild;
	public:
		T data;
		int LTag;//左标志
		int RTag;//右标志
		BiTThreadNode(int LeftTag=0,int RightTag=0,BiTThreadNode<T>*Left=NULL,BiTThreadNode<T>*Right=NULL)
		{
			LTag=LeftTag;
			RTag=RightTag;
			LChild=Left;
			RChild=Right;
		}
		BiTThreadNode(T item,int LeftTag=0,int RightTag=0,BiTThreadNode<T>*Left=NULL,BiTThreadNode<T>*Right=NULL)
		{
			data=item;
			LTag=LeftTag;
			RTag=RightTag;
			LChild=Left;
			RChild=Right;
		}
		~BiTThreadNode(){}
		BiTThreadNode<T>*&Left()
		{return LChild;}
		BiTThreadNode<T>*&Right()
		{return RChild;}
};


