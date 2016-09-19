#include <stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;  
typedef int Status;
typedef struct LNode
{
	ElemType data;         //������
	struct LNode *prior;   //ǰ��ָ�� 
	struct LNode *next;   //���ָ��
	 
}LNode;  
typedef struct LNode *LinkList; //��������ֻ�Ƿ���ʹ�ö���~ 

//1.����һ���ձ� 
LinkList InitList()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)exit(ERROR);
	else L ->next = L ->prior = L;
	return L;
} 

//2.�����ÿ�
void ClearList(LinkList L)
{
	LinkList p = L ->next;   //ָ���һ����� 
	while(p != L)
	{
		p = p ->next;  //ָ����һ����� 
		free(p->prior); //�ͷŸý���ǰ����� 
	}
	L ->next = L ->prior = L; //�Լ�ָ�Լ� 
} 

//3.�ж��Ƿ�Ϊ�ձ� 
Status ListEmpty(LinkList L)
{
	return L->next == L && L ->prior == L?TRUE:FALSE;
}

//4.���ٱ�
void DestoryList(LinkList L)
{
	ClearList(L);
	free(L);
	L = NULL;
}

//5.��ñ���
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L ->next;
	while(p != L)
	{
		i++;
		p = p ->next;
	}
	return i;
} 

//6.��ñ��е�i��Ԫ�ص�ֵ
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j = 1;
	LinkList p = L ->next;  //ָ���һ�����
	while(p != L && j < i)   //ָ����� 
	{
		j++;
		p = p ->next;
	} 
	if(p == L || j > i)return ERROR;  //�Ҳ�����Ԫ��
	e = p ->data;
	return OK; 	
}

//7.���ұ����Ƿ��������������Ԫ��
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)) 
{
    int i = 0;
    LinkList p = L ->next ->next;  //ָ���һ�����
    while(p != L ->next)
    {
        i++;
        if(compare(p->data,e))return i;
        p = p ->next; 
    } 
    return 0;   //�Ҳ���������0 
}

//8.���ĳ���ڵ��ֱ��ǰ��
Status BeforeElem(LinkList L,ElemType choose,ElemType *before)
{
	LinkList p = L ->next ->next;  //ָ��ڶ������
	while(p != L)
	{
		if(p ->data == choose)
		{
			before = p ->prior ->data; 
			return OK;
		}
		p = p ->next;
	} 
	return ERROR;
}

//9.���ĳ���ڵ��ֱ�Ӻ��
Status NextElem(LinkList L,ElemType choose,ElemType *behind)
{
	LinkList p = L ->next ->next; //ָ��ڶ������
	while(p != L)
	{
		if(p ->prior ->data == choose)
		{
			behind = p ->data;
			return OK;
		}
		p = p ->next;
	} 
	return ERROR;
}


//10.���ص�i��Ԫ�صĵ�ַ
LinkList GetElemAdd(LinkList L,int i)
{
	int j;
	LinkList p = L;
	if(i < 0 || i > ListLength(L))return NULL; //�ж�iֵλ���Ƿ�Ϸ�
	for(j = 1;j <= i;j++)
	{
		p = p ->next;
	} 
	return p;
}                              


//11.����i��λ�ò���Ԫ��
Status ListInsert(LinkList L,int i,ElemType e)
{
	LinkList p,q;
	//�ж�iֵ�Ƿ�Ϸ�
	if(i < 1 || i > ListLength(L) + 1)return ERROR;
	p =  GetElemAdd(L,i - 1);
	//NULL�Ļ�˵������i������ǰ�������ڣ�
	//�������ͷ�ڵ�Ϊ��һ������ǰ�� 	 
	if(!p)return ERROR; 
	q = (LinkList)malloc(sizeof(LNode));
	if(!q)return ERROR;
	q ->data = e;  //���½�㸳ֵ
	q ->prior = p;  //�½���ǰ��Ϊ��i - 1�����
	q ->next = p ->next; //�½��ĺ��Ϊ��i�����
	p ->next ->prior = q; //��i�����ǰ��ָ���½�� 
	p ->next = q;  //��i-1�����ĺ��ָ���½�� 
	return OK; 
}

//12.ɾ����i��λ�õ�Ԫ��
Status ListDelete(LinkList L,int i,ElemType *e)
{
	LinkList p;
	if(i < 1)return ERROR; //�ж�ɾ��λ���Ƿ�Ϸ�
	p = GetElemAdd(L,i);
	if(!p)return ERROR;  //ΪNULL˵����i��Ԫ�ز�����
	e = p ->data;
	p ->prior ->next = p ->next; //i-1�����ĺ��ָ���i+1�����
	p ->next ->prior = p ->prior; //��i+1������ǰ��ָ���i - 1�����
	free(p); //�ͷŵ�i�����
	return OK; 
}



int main()
{
	LinkList p;
	p = InitList();
	printf("%d\n",ListLength(p));
	return 0;
}