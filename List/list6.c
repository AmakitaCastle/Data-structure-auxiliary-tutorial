#include <stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;  
typedef int Status;
typedef struct LNode
{
	ElemType data;         //������
	struct LNode *prior;   //ǰ��ָ�� 
	struct LNode *next;   //���ָ��
	 
}LNode;  
typedef struct LNode *LinkList;

//����һ������N�����ķ���
 LinkList ListCreate(int N)
 {
 	LinkList p,q,head;
 	int i,data;
 	q = head;
 	head = (LinkList)malloc(sizeof(LNode));	
 	head ->prior = head;
 	head ->next = head;
 	p = head;
 	for(i = 0;i < N;i++)
 	{
	 	printf("�������%d������ֵ��",i + 1);
	 	scanf("%d",&data);
	 	q = (LinkList)malloc(sizeof(LNode));
	 	q ->data = data;
	 	p ->next = q;
	 	q ->prior = p;
		q ->next = head; 
		head ->prior = q; 
		p = q; 
 	}
 	return head;
 } 
 
 //����һ����ӡ������ݵķ���
 void PrintNode(ElemType e)
 {
 	printf("%d\t",e);
 } 
 
 //����һ�������������ķ���
 void ListTraverse(LinkList L)
 {
 	LinkList p = L->next;  //ָ����Ԫ���
	while(p!=L)
	{
		PrintNode(p->data);
		p = p ->next;
	} 
	printf("\n");
 } 
 
 //����һ�������������ķ���
 void ListTraverseBack(LinkList L)
 {
 	LinkList p = L ->prior;  //ָ�����һ����� 
	while(p!=L)
	{
		PrintNode(p->data);
		p = p ->prior;
	} 
	printf("\n");
 } 
 
 
 int main()
 {
 	LinkList p;
 	int N = 0;
 	printf("������˫������Ľ�������");
 	scanf("%d", &N);
 	p = ListCreate(N);
 	printf("�����ӡ�����еĽ�㣺\n");
 	ListTraverse(p);
 	printf("�����ӡ�����еĽ�㣺\n");
 	ListTraverseBack(p); 
 	return 0;
 }