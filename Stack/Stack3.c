#include <stdio.h>

#define STACK_INIT_SIZE 10 //�洢�ռ�ĳ�ʼ������
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; 
typedef int SElemType;

//�洢�ṹ 
typedef struct StackNode
{
    SElemType data;   //��ŵ�����
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;   //Topָ��
    int count;          //ջԪ�ؼ�����
}LinkStack;


//1.����һ����ջ
Status InitStack(LinkStack *S)
{
	S ->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S ->top)return ERROR;
	S ->top = NULL;
	S ->count = 0;
	return OK;
} 

//2.��ջ�ÿ�
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p,q;
 	p = S->top;
	while(p)
	{
		q = p;
		p = p ->next;
		free(q);
	}
	S ->count = 0;
	return OK;	 
}

//3.�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S)
{
	return S.count == 0?TRUE:FALSE;
}

//4.���ջ�е�Ԫ�ظ���
int StackLength(LinkStack S)
{
	return S.count;
}

//5.���ջ��Ԫ��
Status GetTop(LinkStack *S,SElemType *e)
{
	 LinkStackPtr p;
	 if(StackEmpty(*S))return ERROR;
	 *e = S ->top->data;
	 p = S ->top;
	 return OK;
}

//6. ����ջ�в���Ԫ��(��ջ)
Status PushStack(LinkStack *S,SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!s)return ERROR;
	s ->data = e;
	s ->next = S ->top;
	S ->top = s;
	S ->count++;
	return OK;
} 

//7.ɾ��ջ��Ԫ��*��ջ( 
 
Status PopStack(LinkStack *S,SElemType *e) 
{
	LinkStackPtr p;
	if(StackEmpty(*S))return ERROR;
	* e = S ->top ->data;
	p = S ->top;  //��ȡջ�����
	S ->top = S ->top ->next;  //ջ��ָ������һλ 
	free(p);   //�ͷŽ��p
	S ->count--;
	return OK;
}

//8.����ջ
Status StackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while(p)
	{
 		visit(p->data);
        p=p->next;
	}
	printf("\n");
	return OK; 
} 

//����һ����ӡԪ�صķ��� 
Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

int main()
{
	int i,e;
	LinkStack s;
	InitStack(&s);
	printf("��ʼ����ջ�����Ų���10��Ԫ��~\n");
	for(i = 1;i <= 10;i++)
	{
		PushStack(&s,i);
	}
	printf("��ʱջ�е�Ԫ������Ϊ��\n");
	StackTraverse(s);
	printf("��ʱջ����%d��Ԫ��\n",StackLength(s));	
	PopStack(&s,&e);
	printf("��ջ����ջ���Ϊ��%d\n",e);
	printf("��ʱջ�е�Ԫ������Ϊ��\n ");
	StackTraverse(s);
	ClearStack(&s);
	printf("���ջ����ʱջ����%d��Ԫ�أ�\n\n",StackLength(s));	
	return 0;
}