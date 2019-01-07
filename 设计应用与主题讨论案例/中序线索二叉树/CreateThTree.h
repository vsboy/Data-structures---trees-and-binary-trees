template<class T >//创建二叉树结点
BiTThreadNode<T>*CreateTree(T item,int LeftTag=0,int RightTag=0,BiTThreadNode<T>*LChild=NULL,BiTThreadNode<T>*RChild=NULL)
{
	BiTThreadNode<T>*p;
	p=new BiTThreadNode<T>(item,LeftTag,RightTag,LChild,RChild);
	if(p==NULL)
	{
		cout<<"结点申请失败"<<endl;
		exit(0);
	}
	return p;
}
template<class T>
void MyBTree(BiTThreadNode<T>*&root)
{
	BiTThreadNode<char>*b,*c,*d,*e,*f,*g;
	g=CreateTree('G');
	d=CreateTree('D',0,0,g);
	e=CreateTree('E');
	b=CreateTree('B',0,0,d,e);
	f=CreateTree('F');
	c=CreateTree('C',0,0,f);
	root=CreateTree('A',0,0,b,c);
}
