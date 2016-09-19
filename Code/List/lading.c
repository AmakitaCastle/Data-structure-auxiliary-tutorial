#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
	int data;         
	struct LNode *next;   
}LNode;  
typedef struct LNode *LinkList; 

//����һ����ʼ������ķ���
LinkList ListCreate(int n)
{
	LinkList head = NULL,p,q = head;
	int i;
	for(i = 1;i <= n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p ->data = i;
		if(head == NULL)head = p;
		else q ->next = p;
		q = p;
	}
	q ->next = head;
	return head;
} 

int main()
{
	LinkList p,q;
	int i,num = 0;
	printf("��������Ҫ��������������Ĺ�ģ(����3*3������3����)\n");
	scanf("%d",&num);
	p = ListCreate(num);
	printf("%d * %d ���������󹹽���ϣ���������\n\n",num,num);
	for(i = 0;i < num;i++)
	{
		q = p;
		while(1)
		{
			printf("%d  ",p ->data);
			p = p ->next;
			if(p == q)break;  //�Ѿ�����һ���� 
		}
		p = p ->next; 
		printf("\n");
	}
	printf("���������ӡ���~~\n\n");
	return 0;
}
