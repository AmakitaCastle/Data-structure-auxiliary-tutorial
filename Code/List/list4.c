#include <stdio.h>
#include<malloc.h>


#define MAXSIZE 100
#define INCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;  
typedef struct LNode
{
	ElemType data;         //������
	struct LNode *next;   //ָ���� 
}LNode;  
typedef struct LNode *LinkList;

int main()
{
	LinkList list;
	InitList(list);
	int i = ListLength(list);
	printf("%d\n",i);
	return 0;
}


//1)�����ձ� 
Status InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)exit(ERROR);
	L ->next = L;   //�Լ�ָ�Լ�~��ͷ�ڵ�ָ����ָ��ͷ��㣩 
	return OK;
}

//2�������ÿ�
void ClearList(LinkList L)
{
	LinkList p,q;
	L = L ->next;     //ָ��ͷ��� 
	p = L ->next;    //ָ���һ����� 
	while(p!=L)
	{
		q = p ->next;
		free(p);
		p = q;
	}
	L ->next = L; //�Լ�ָ�Լ� 
} 

//3���ж��Ƿ�Ϊ�ձ�(��ͷ�ڵ�����) 
Status ListEmpty(LinkList L)
{
	return L!=L ->next?FALSE:TRUE; 
}

//4�����ٱ�
void DestoryList(LinkList L) 
{
	ClearList(L);  //�����ÿ�
	free(L);    //�ͷ�ͷ�ڵ� 
	L = NULL; 
}

// 5����ñ���
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L ->next;  //ָ��ͷ��� 
	while(p != L)
	{
		i++;
		p = p ->next;
	} 
	return i;
} 

// 6����ñ��е�i��Ԫ�ص�ֵ
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j = 1;
	LinkList p = L ->next ->next;	//ָ���һ�����
	if(i <= 0||i >ListLength)return ERROR;  //�жϲ���λ���Ƿ�Ϸ� 
	while(j < i)
	{
		j++;
		p = p ->next;
	} 
	e = p ->data;
	return OK;
} 

//7)���ұ����Ƿ��������������Ԫ��
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

//8�����ĳ���ڵ��ֱ��ǰ��
Status BeforeElem(LinkList L,ElemType choose,ElemType *before)
{
	LinkList q,p = L ->next ->next;  //ָ���һ�����
	q = p ->next;  
	while(q != L ->next)
	{		
		if(q ->data == choose)
		{
			before = p ->data;
			return OK;
		}
		p = q; //��������
		q = q ->next; 
	}
	return ERROR;  	
}


//9�����ĳ���ڵ��ֱ�Ӻ��
Status NextElem(LinkList L,ElemType choose,ElemType *behind)
{
	LinkList p = L ->next ->next;  //ָ���һ�����
	while(p != L)
	{
		if(p ->data == choose)
		{
			behind = p ->next ->data;
			return OK;
		}
	}
}

//10������i��λ�ò���Ԫ��
Status ListInsert(LinkList L,int i,ElemType e)
{
	LinkList s,p = L ->next;
	int j = 0;
	if(i <= 0 || i > ListLength(L) + 1)return ERROR;  //�жϲ���λ���Ƿ�Ϸ�
	//Ѱ�Ҳ������ǰһ����� 
	while(j < i - 1) 
	{
		j++;
		p = p ->next;	
	}
	//�����½��
	s = (LinkList)malloc(sizeof(LNode)); 
	s ->data = e; //��e��ֵ���½��
	s ->next = p ->next; //�½��ָ��ԭ���ĵ�i����� 
	p ->next = s;   //ԭi - 1�����ָ���½�� 
	//��������λ���Ǳ�β�����µı�β��ַ��βָ�� 
	if(p == L)
	{
		L = s;
	}
	return OK;
} 


//11��ɾ�����е�i��Ԫ��
Status ListDelete(LinkList L,int i,ElemType *e)
{
	LinkList s,p = L ->next;
	int j = 0;
	if(i <= 0||i > ListLength(L))return ERROR;//�ж�ɾ��λ���Ƿ�Ϸ� 
	//Ѱ�Ҳ������ǰһ����� 
	while(j < i - 1) 
	{
		j++;
		p = p ->next;
	}
	s = p ->next;
	p ->next = s ->next; 
	e = s ->data;
	if(s == L)
	L = p;
	free(q);  //�ͷŽ��
	return OK; 
}


//12������ѭ�������������Ԫ��
void ListTraverser(LinkList L,void(*visit)(ElemType))
{
	LinkList p = L ->next ->next;   //ָ���һ����� 
    while(p != L ->next)
    {
        visit(p ->data);
        p = p ->next;
    }
    printf("\n");
}
