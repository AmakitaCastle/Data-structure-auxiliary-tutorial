#include <stdio.h>

#define STACK_INIT_SIZE 10 //�洢�ռ�ĳ�ʼ������
#define STACK_INCREMENT 2 //�������� 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;
typedef struct SqStack
{
	SElemType *base;  //ջ��ָ����� 
	SElemType *top;  //ջ��ָ����� 
	int stacksize;  //��ǰ�����õ�������� 
}SqStack;

//��ʼ��ջ 
void InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if( !S->base )exit(0);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

//��ȡջ�ĵ�ǰ����
int StackLength(SqStack S)
{
	return (S.top - S.base);
}  

//��ջ
void PushStack(SqStack *S, SElemType e)
{
    if(S->top - S->base >= S->stacksize )
    {
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if( !S->base )exit(0);
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize + STACK_INCREMENT;
    }
    *(S->top) = e;
    S->top++;
}

//��ջ 
void PopStack(SqStack *S, SElemType *e)
{
    if(S->top == S->base )return;
    *e = *--(S->top);
}

int main()
{
	SqStack s;
	SElemType n,m,e;
	InitStack(&s);
	printf("������Ҫת���Ľ��ƣ�n >= 0\n");
	scanf("%d",&n);
	printf("������Ҫ����ת����ʮ��������\n");
	scanf("%d",&m);
	while(m)
	{
		PushStack(&s,m % n);
		m = m / n;
	}
	printf("���ʮ����ת%d���ƺ��ֵ��\n",n);
	while(StackLength(s))
	{
		PopStack(&s,&e);
		if(n == 16)
		{
			printf("%X ",e);  //���ʮ�����ƵĽ��
		}
		else printf("%d ",e);
	}
	printf("\n\n");
	return 0; 
}