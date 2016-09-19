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
typedef struct
{
   ElemType data;   //����
   int cursor;           //�α�
}Component,StaticLinkList[MAXSIZE];   //ʹ�������±��ʶÿ���ڵ�

//1.��ʼ����̬���� 
Status InitList(StaticLinkList space)
{
	int i;
	for(i = 0;i < MAXSIZE - 1;i++)
	{
		//ÿ���α�ָ����һ���±�,
		//�����0���α�ָ���һ���±��� 
		//��һ�������α�ָ��ڶ����±��� 
		space[i].cursor = i+1;          			
	}
	//���һ�������Ҫ�����α�����Ϊ0 
	space[MAXSIZE - 1].cursor = 0;	
	return OK;
}

//2.��ñ�������Ľ���±�
int GET_Free(StaticLinkList space)
{
	int i = space[0].cursor;  
    //������һ�����Ϊ���ý��  
	if(space[0].cursor)
		space[0] = space[i].cursor;  
	return i;
} 

//3.��þ�̬�����е�Ԫ�ظ���
int GetLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cursor;  //ָ���һ��������α� 
	while(i)
	{
		i = L[i].cursor;
		j++;
	}
	return j;
} 



//3.����̬�����в���Ԫ��
Status ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k = MAXSIZE - 1;  //��������һ��Ԫ�� 
	//���жϲ���λ���Ƿ�Ϸ�
	if(i < 1 || i >GetLength(L) + 1)
	{
		return ERROR;
	} 
	//�ڻ�ȡ�հ׽���������
	j = GET_Free(L);
	if(j)
	{
		for(l = 1;l <= i - 1;i++)
		{
			//�õ���i - 1��Ԫ�ص��±�
			//ע�⣺����ֱ����K = L[K - 1].cursor����ΪԪ�ؿ����ǲ����ڵ�
			k = L[k].cursor; 
		} 
		L[j].cursor = L[k].cursor;
		L[k].cursor = j;
		L[0].cursor = GetLength(L) + 1;  //���±�0��Ԫ��ָ���µĿհ׽�� 
		return OK;
	}
	return ERROR;
}


//4.ɾ����̬�����еĵ�i��Ԫ��
Status ListDelete(StaticLinkList L,int i,ElemType e) 
{	
	int j = 0;
    if(i < 1 || i > ListLength(L))return ERROR;  //�ж�ɾ��λ���Ƿ�Ϸ�
    int k = MAXSIZE - 1;   //��ȡ���һ���ڵ�,��Ϊ����cursorָ���һ����Ч���
    //��ȡ��i - 1��Ԫ�ص��±�
	for(j = 1 ; j < i ; ++j)                      
    {
		k = L[k].cursor   ;
	}
    j = L[k].cursor ;    //�õ���i��Ԫ�ص��±�
    L[k].cursor = L[j].cursor ;  //��ɾ���ڵ��cursor��ֵ��ǰһ�����
    Free_Node(L,j);     //�ͷŵ���i��Ԫ��,�±�Ϊj
    return OK;
}

//5.���±�Ϊk�Ŀ��н�����Ϊ���ý��
void FreeNode(StaticLinkList space,int k)
{
	space[k].cursor = space[0].cursor;   //��֮ǰ�ı�������ĵ�һ������±��ŵ�L[k]��cursor��
	space[0].cursor = k;  //�±�Ϊk��Ԫ�س�Ϊ��һ�����н��
} 

 

