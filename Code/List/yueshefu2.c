#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//����ѭ������Ĵ洢�ṹ
typedef struct LNode
{
    int data;         //������
    struct LNode *next;   //ָ���� 
}LNode;  
typedef struct LNode *LinkList;

//����ѭ������ĳ�ʼ������
LinkList createList(int n)
{
	printf("\n��ʼ��ѭ������\n\n"); 
	LinkList head,s,p;
	int i = 1;
	head = (LinkList)malloc(sizeof(LNode));
	p = head;
	if(n != 0)
	{
		while(i <= n)
		{
			s = (LinkList)malloc(sizeof(LNode));
			s ->data = i++;
			p ->next = s;
			p = s;
		}
		 s->next = head->next;  
	}
    free(head);  
    return s->next;  
}



int main()
{
	int n,m,i;
	printf("����μӵ�����:\n");  
    scanf("%d",&n);  
    printf("����ÿ��������һ����:\n");  
    scanf("%d",&m);
	LinkList p = createList(n);
	LinkList temp;
	m %= n;  //Ϊ�˷�ֹ�������˴��ڲ�����ˣ�����������Ϊ��ͷ��ʼ
	while(p != p ->next)
	{
		for(i = 1;i < m -1;i++)
		{
			p = p ->next; 
		}
		printf("��%d������ɱ��\t",p ->next->data);
		temp = p ->next;
		p ->next = temp ->next;
		free(temp);
		p = p ->next; 
	} 
	printf("\n��%d���˻������ˣ�\n\n", p->data );    
    return 0;  
}
