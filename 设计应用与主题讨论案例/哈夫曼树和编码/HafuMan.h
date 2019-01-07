const int MaxValue=10000;//��ʼ�趨��Ȩֵ���ֵ
const int MaxBit=10;//��ʼ�趨��������λ��
const int MaxN=10;   //��ʼ�趨����������
struct HaffNode                       //���������Ľ��ṹ
{
int weight;             //Ȩֵ
int  flag;                 //���
int parent;            //˫�׽���±�
int leftChild;        //������
int rightChild;//�Һ����±�
};
struct  Code//��Ź��������������Ԫ�ؽṹ
{
int bit[MaxN];     //����
int  start;        //�������ʼ�±�
int  weight;      //�ַ���Ȩֵ
};
void  Haffman(int weight[],int n,HaffNode haffTree[])
//����Ҷ������ΪnȨֵ����Ϊweight�Ĺ�������haffTree
{
int j,m1,m2,x1,x2;
//��������haffTree�ۣݳ�ʼ����n��Ҷ��㹲��2n-1�����
for(int i=0;i<2*n-1;i++)
{
if(i<n)
	haffTree[i].weight=weight[i];
else 
	haffTree[i].weight=0;
	haffTree[i].parent=0;
	haffTree[i].flag=0;
	haffTree[i].leftChild=-1;
	haffTree[i].rightChild=-1;
}
//�����������haffTree[]��n-1����Ҷ���
for(int i=0;i<n-1;i++)
{
	m1=m2=MaxValue;
	x1=x2=0;
	for(j=0;j<n+i;j++)
	{
		if(haffTree[j].weight<m1&&haffTree[j].flag==0)//������СȨֵm1�ͱ��Ϊx1��m2��x2Ϊ����С
		{
			m2=m1;
			x2=x1;
			m1=haffTree[j].weight;
			x1=j;
		}
		else if(haffTree[j].weight<m2&&haffTree[j].flag==0)
		{
            m2=haffTree[j].weight;
            x2=j;
		}
	}
//���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
		haffTree[x1].parent=n+i;
		haffTree[x2].parent=n+i;
		haffTree[x1].flag=1;
		haffTree[x2].flag=1;
		haffTree[n+i].weight=haffTree[x1].weight+haffTree[x2].weight;
		haffTree[n+i].leftChild=x1;
		haffTree[n+i].rightChild=x2;
	}
}
void HaffmanCode(HaffNode haffTree[],int n,Code haffCode[])
//��n�����Ĺ�������haffTree[]�������������haffCode[]
{
	Code*cd=new Code;
	int child,parent;
//��n��Ҷ���Ĺ���������
	for(int i=0;i<n;i++)
	{
	cd->start=n-1;//���ȳ���������һλΪn-1
	cd->weight=haffTree[i].weight;
//ȡ�ñ����ӦȨֵ���ַ�
	child=i;
	parent=haffTree[child].parent;
//��Ҷ�������ֱ�������
	while(parent!=0)
	{
	if(haffTree[parent].leftChild==child)
		cd->bit[cd->start]=0;//���ӽ�����0
	else
	cd->bit[cd->start]=1;//�Һ��ӽ�����1
	cd->start--;
	child=parent;
	parent=haffTree[child].parent;
	}
//����ÿ��Ҷ���ı���Ͳ��ȳ��������ʼλ
	for(int j=cd->start+1;j<n;j++)
		haffCode[i].bit[j]=cd->bit[j];
		haffCode[i].start=cd->start;
		haffCode[i].weight=cd->weight;
//��ס�����ӦȨֵ���ַ�
	}
}

