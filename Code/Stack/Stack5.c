#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 10 //�洢�ռ�ĳ�ʼ������
#define STACK_INCREMENT 2 //�������� 
#define MAX_BUFFER_SIZE 10

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef double SElemType;
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

//�ж��Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S)
{
    return S.top == S.base?TRUE:FALSE;
} 

int main()
{
	char c;
	double d,e;
	int i = 0;
	char buffer[MAX_BUFFER_SIZE];
	SqStack s;
    InitStack(&s);
    printf("��������Ҫ������ʽ���沨�����ʽ������(����С��)֮���ÿո�ֿ�����#��ʾ������\n");
    scanf("%c",&c);
    while(c!='#')
    {
    	//�ж��ַ��Ƿ�Ϊ���ֻ�С���� 
  	 	while(isdigit(c)||c=='.')
  	 	{
 	 	 	buffer[i++]=c;
            buffer[i]='\0';	
             if(i>=10){
                printf("\n����������󻺳�����С��\n");
                return -1;
            }
            scanf("%c",&c);
            //�ж��Ƿ�Ϊ�ո��ǵĻ�������������ַ���ת��Ϊdouble���͵����ݣ�ѹ��ջ�� 
			if(c == ' ')
			{
				d = atof(buffer);
                PushStack(&s,d);
                i=0;
                break;
			} 
 	  	}
 	  	//�����������򣬵���ջ�е�����Ԫ�أ���Ϊ�����������㣬�����ѹ��ջ�� 
		//���⣬Ҫע�⣺������������Ϊ0 
 	  	switch(c)
 	  	{
	  		case '+':
            	PopStack(&s,&d);
            	PopStack(&s,&e);
            	PushStack(&s,d+e);
            	break;
			case '-':
            	PopStack(&s,&d);
            	PopStack(&s,&e);
            	PushStack(&s,e-d);
            	break;
		 	case '*':
            	PopStack(&s,&d);
            	PopStack(&s,&e);
            	PushStack(&s,d*e);
            	break;
            case '/':
            	PopStack(&s,&d);
            	PopStack(&s,&e);
            	if(e!=0)PushStack(&s,e/d);
				else{
                	printf("\n������������Ϊ0��");
                	return -1;
            	}
            	break;		
 	 	}
 	 	scanf("%c",&c);
    }
    PopStack(&s,&d);
    printf("\n���ս��Ϊ��%f\n",d);
	return 0;
}