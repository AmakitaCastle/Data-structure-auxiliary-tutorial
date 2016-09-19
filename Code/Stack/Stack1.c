#include <stdio.h>

#define STACK_INIT_SIZE 10 //�洢�ռ�ĳ�ʼ������
#define STACK_INCREMENT 2 //�������� 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;
typedef struct LNode
{
	SElemType *base;  //ջ��ָ����� 
	SElemType *top;  //ջ��ָ����� 
	int stacksize;  //��ǰ�����õ�������� 
}LNode;
typedef LNode *SqStack;

//1.�����ջ
void InitStack(SqStack S)
{
	S ->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base)exit(ERROR);
	S ->top = S ->base;  //ջ��ָ��ջ��
	S ->stacksize = STACK_INIT_SIZE; 
} 

//2.��ջ�ÿ�
void ClearStack(SqStack S)
{
	S ->top = S ->base;  //ջ��ָ��ջ�� 
} 

//3.�ж��Ƿ�Ϊ��ջ
int StackEmpty(SqStack S)
{
	return S ->top == S ->base?TRUE:FALSE;
} 

//4.����ջ
void DestoryStack(SqStack S)
{
	free(S ->base); //�ͷ�ջ�ռ�
	S ->top = S ->base = NULL;  //��ջ����ջ������ΪNULL 
	S ->stacksize = 0;     //�洢�ռ�����Ϊ0 
} 

//5. ���ջ�е�Ԫ�ظ���
int StackLength(SqStack S)
{
	return S ->top - S ->base;
} 


//6.���ջ��Ԫ��
Status GetTop(SqStack S,SElemType *e)
{
	if(S ->top > S ->base)
	{
		e = S ->top - 1;
		return OK;
	}else{
		return ERROR;
	}
}

//7.��ջ�в���Ԫ��(ѹջ)
void PushStack(SqStack S,SElemType e) 
{
	//�жϵ�ǰջ�����Ƿ����ˣ�������Ҫ���ӿռ� 
	if(S ->top - S ->base == S ->stacksize)	
	{
		S ->base = (SElemType *)realloc(S ->base,
		     (S ->stacksize + STACK_INCREMENT)*sizeof(SElemType));
  		if(!S->base)exit(ERROR);
  		S ->top = S ->base + S ->stacksize;  //�޸�ջ��ָ��ָ���µ�ջ��
		S ->stacksize += STACK_INCREMENT;   //�������� 
	}
	*(S ->top ++) = e; 
}

//8.����ջ�е�Ԫ��
 Status PopStack(SqStack S,SElemType e) 
 {
 	if(S ->top == S ->base)return ERROR;  //ջΪ��
	e = *(--S ->top);   //ջ��Ԫ��ֵ����e,ջ��ָ������ 
	return OK;  	
 }
 
 //9.����ջ�е�Ԫ��
 void StackTraverse(SqStack S,void *visit(SElemType))
 {
 	//��ջ�׿�ʼ��ջ�� 
 	while(S ->top > S ->base)
 	visit(*(S ->base ++));
 	printf("\n");
 }

int main()
{
	printf("�Ǻ�");
	return 0;
}