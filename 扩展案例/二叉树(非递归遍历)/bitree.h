//������BiTree������ṹBiNode,�ļ���Ϊbitree.h
#ifndef BITREE_H
#define BITREE_H

template <class T>
struct BiNode   //�������Ľ��ṹ
{
  T data;       
  BiNode<T> *lchild, *rchild;
  int flag;
};
template <class T>
class BiTree
{
public:
    BiTree( );             //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
    ~BiTree(void);         //�����������ͷŶ��������и����Ĵ洢�ռ�
	BiNode<T>* Getroot();  //���ָ�������ָ��
    void PreOrder(BiNode<T> *root);     //ǰ�����������
    void InOrder(BiNode<T> *root);      //�������������
    void PostOrder(BiNode<T> *root);    //�������������
    void LeverOrder(BiNode<T> *root);   //�������������
	void NrecursionPreOrder(BiNode<T> *root);//�ǵݹ����������
	void NrecursionInOrder(BiNode<T> *root);//�ǵݹ����������
	void NrecursionPostOrder(BiNode<T> *root);//�ǵݹ����������
	void countNode(BiNode<T> *root,int& count);//������������
	int depth(BiNode<T> *root);//�����������
private:
    BiNode<T> *root;         //ָ�������ͷָ��
    BiNode<T> *Creat( );     //�вι��캯������
    void Release(BiNode<T> *root);   //������������ 
};
#endif