#include <stdio.h>
#include<malloc.h>


#define MAXSIZE 20
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
typedef struct LNode *LinkList; //��������ֻ�Ƿ���ʹ�ö���~ 


int main(int argc, char *argv[])
{
	return 0;
}

//ͷ�巨������ 
void HeadCreateList(LinkList L,int n)
{
	LinkList p;
	int i;
	srand(time(0));    //��ʼ�����������
	L = (LinkList)malloc(sizeof(LNode));
	L ->next = NULL;
	//����ѭ�����ɽ�㲢��ӵ��������� 
	for(i = 0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));    //�����½�� 
		p ->data = rand()%100 + 1;              //������λ�����100,��λ����1000 
		p ->next = L ->next;    
		L ->next = p;                      //�嵽��ͷ 
	}	
}

//β�巨������ 
void TailCraeteList(LinkList L,int n)
{
	LinkList p,r;
    int i;
    srand(time(0));    //��ʼ�����������
	L = (LinkList)malloc(sizeof(LNode));
	r = L;
	for(i = 0;i < n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));    //�����½�� 
		p ->data = rand()%100 + 1;              //������λ�����100,��λ����1000 
		r ->next = p;        //����β�ն˽���ָ��ָ���½�� 
		r = p;      //����ǰ���½�㶨��Ϊ��β��β��� 
	}
	r->next = NULL;		 //��ǰ������� 
} 

//��ȡ�м��� 
Status GetMidLNode(LinkList *L,ElemType *e)
{
	LinkList p,q;
	p = q = *L;
	while(p ->next ->next != NULL)
	{
		if(p ->next ->next != NULL)
		{
			p = p ->next ->next;
			q = q ->next;
		}else{
			p = p ->next;
		}
	} 
	e = q ->data;
	return OK;
} 


/** 12�����������Ĵ���ʵ�֣�**/ 

//1.�����յĵ�����
void InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)exit(ERROR);
	L ->next = NULL;
}

//2.�����ÿ�
void ClearList(LinkList L)
{
	LinkList p = L ->next;
	L ->next = NULL;
	//���ž����ͷ�ͷ�������Ľ����
	while(p)
	{
		p = L->next;
		free(L);  //�ͷ���Ԫ���
		L = p;    //�ƶ�����ǰ����Ԫ��� 
	} 
} 

//3.�ж��Ƿ�Ϊ�ձ� 
Status ListEmpty(LinkList L)
{
	//ֻ���ж�ͷ����ָ�����Ƿ�Ϊ�ռ���
	if(L ->next)return FALSE;
	else return TRUE;	
}

//4.���ٵ�����
void DestoryList(LinkList L)
{
	LinkList q;
	//ɾ��ͷ�����Ľ�� 
	while(L)
	{
		//ָ����Ԫ��㣬������ͷ���		
		q = L ->next;
		free(L);
		L = q;      //ɾ����ָ����Ԫ 
	}
} 

//5.��ñ��� 
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L ->next;
	while(p)
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
	//ָ����Ԫ��Ȼ�����κ��ƣ����絽�˽�β����j��ֵ����i
	//��û�Ҹ���Ԫ��˵��i���Ϸ�
	LinkList p = L ->next;
	while(p && j < i)
	{
		j++;
		p = p ->next;
	} 
	if(!p || j> i)return ERROR;
	e = p ->data;
	return OK;
}

//7.���ұ����Ƿ��д�������������Ԫ��
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
	int i = 0;  
    LinkList p = L -> next;  
    while(p)  
    {  
        i++;  
        if(compare(p->data,e))return i;  
        p = p -> next;  
    }  
    return 0;  
} 

//8.���ĳ������ֱ��ǰ��
Status BeforeElem(LinkList L,ElemType choose,ElemType *before)
{
	LinkList q,p = L ->next;
	while(p ->next)  //p��ָ����к�� 
	{
		q = p ->next;   //qָ��p�ĺ�� 
		//�ж�p�ĺ���Ƿ�Ϊchoose,�ǵĻ�����OK,����������� 
		if(q ->data == choose)
		{
			before = p ->data;
			return OK; 
		}
		p = q;		
	}
	return ERROR; 
}

//9.���ĳ������ֱ�Ӻ��
Status NextElem(LinkList L,ElemType choose,ElemType *behind)
{
	LinkList p = L ->next;
	while(p ->next)
	{
		if(p ->data == choose)
		{
			behind = p ->next ->data;
			return OK;
		}
		p = p ->next;
	}
	return ERROR;	
}

//10. �����е�i��λ�ò���Ԫ��
Status ListInsert(LinkList L,int i,ElemType e)
{
	int j = 0;
	LinkList p,q =L;  //��qָ��ͷ���
	while(p && j < i - 1)
	{
		j++;
		p = p ->next;  //pָ����һ���ڵ� 
	}
	if(!p || j > i - 1)return ERROR;
	p = (LinkList)malloc(sizeof(LNode));
	//Ҫ���ò���Ľ���ָ����ָ�����λ�õĺ�̽��  
    //���ò���ڵ��ǰ����ָ����ָ�������  
    //������˳������Ŷ1   
	p ->data = e;
	p ->next = q ->next;
	q ->next = p;
	return OK;
} 

//11.ɾ�����е�i��Ԫ��
Status ListDelete(LinkList L,int i,ElemType *e)
{
	int j = 0;
	LinkList p,q = L;
	while(q ->next && j < i -1)
	{
		j++;
		q = q->next;
	}
	if(!q || j >i -1)return ERROR;
	p = q ->next;   //ָ��׼��ɾ���Ľ��
	q ->next = p ->next; //ɾ������ǰ����ָ����ָ��ɾ�����ĺ��   
	e = p ->data; 
	free(p);    //�ͷ�Ҫɾ���Ľ��  
	return OK;
}


//12.�����������е�����Ԫ��
void ListTraverser(LinkList L,void(*visit)(ElemType))
{
	LinkList p = L ->next;
	while(p)
	{
		visit(p ->data);
		p = p ->next;
	}
	printf("\n");
}