#include <stdio.h>

#define STACK_INIT_SIZE 10 //�洢�ռ�ĳ�ʼ������
#define STACK_INCREMENT 2 //�������� 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char SElemType;
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
    if( !S->base)exit(0);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
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

//��ȡջ�ĵ�ǰ����
int StackLength(SqStack S)
{
	return (S.top - S.base);
} 

int main()
{
	SqStack s;
	char c,e;
	InitStack(&s);
	printf("��������׺���ʽ����#��Ϊ������ǣ�\n");
	scanf("%c",&c);
	printf("���ת������沨��ʽ��\n");
	while(c != '#')
	{	
		//������Ҫ�������ֻ��Ƕ�λ�����
		while(c >= '0' && c <= '9')
		{
			printf("%c", c);
            scanf("%c", &c);
            if( c<'0' || c>'9' )
            {
                printf(" ");
            }
		} 
		//�����������ţ�����ջ�е��ַ���ֱ������������ 
		if( ')' == c )
        {
            PopStack(&s, &e);
            while( '(' != e )
            {
                printf("%c ", e);
                PopStack(&s, &e);
            }
        }
        //�����ǼӼ��� �����ջ��ûԪ�أ�ֱ��ѹջ����Ҫ�����ж�
	 	else if( '+'==c || '-'==c )
        {
            if( !StackLength(s) )
            {
                PushStack(&s, c);
            }
            else
            {
                do
                {
                    PopStack(&s, &e);
                    if( '(' == e )
                    {
                        PushStack(&s, e);
                    }
                    else
                    {
                        printf("%c ", e);
                    }
                }while( StackLength(s) && '('!=e );
                PushStack(&s, c);
            }
        } 
        //�����ǳ˳��������ţ�ֱ��ѹջ 
        else if( '*'==c || '/'==c || '('==c )
        {
            PushStack(&s, c);
        }
		//��#���������ʽ�������
  		else if( '#'== c )
        {
            break;
        }
		//����������ַ�����ӡ�ַ����Ϸ�
		else
        {
            printf("\n�����������\n");
            return -1;
        } 
		scanf("%c", &c);	 
	}
	
	//����ջ�е�ʣ�������
	while( StackLength(s))
    {
        PopStack(&s, &e);
        printf("%c ", e);
    } 
	printf("\n\n");
	return 0;
} 