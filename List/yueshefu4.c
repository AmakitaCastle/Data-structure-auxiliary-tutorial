#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

//����ѭ������Ĵ洢�ṹ
typedef int Status; 
typedef struct LNode
{
    int id;         //�ڼ�����
	int pawd;       //���� 
    struct LNode *next;   //ָ���� 
}LNode;  
typedef struct LNode *LinkList;

//1.����һ���������ķ���
LNode *GetNode(int pid,int ppawd)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	if(!p)return ERROR;
	p ->id = pid;
	p ->pawd = ppawd;
	p ->next = NULL;
	return p;
} 

//2.����ѭ��������
Status ListCreate(LinkList L,int n)
{
	int i,ppawd;
	LinkList p,q;
	for(i = 1;i <= n;i++)
	{
		printf("�������%d���˳��е����룺",i);
		scanf("%d",&ppawd);
		p = GetNode(i,ppawd);
		if(L == NULL)
		{
			L = q = p;
			q ->next = L;
		}else{
			p ->next = q ->next;
			q ->next = q;
			q = p;
		}
	}	
	printf("��ɵ���ѭ������Ĵ���!\n");
	return OK;
}  

//3.�ж�ѭ���������Ƿ�Ϊ��
Status ListEmpty(LinkList L)
{
	if(!L)return TRUE;
	return FALSE;
} 

//4.��ӡѭ������ǰ������Ԫ��
void ListPrint(LinkList L)
{
	LinkList p = L;
	if(ListEmpty(L))return;
	do{
		printf("��%d���˵�����Ϊ��%d\n",p ->id,p ->pawd);
		p = p ->next;
	}while(p != L);
	getchar();
} 

//5.��ʼ��Ϸ
void StartGame(LinkList L,int startpawd)
{
	int i,isFlag = 1;
	LinkList p,q,r;
	p = q = L;
	//��pָ��β����㣬Ϊɾ����׼��
	while(p ->next != L)p = p ->next;
	while(isFlag)
	{
		for(i = 1;i < startpawd;i++)
		{
			p = q;
			q = q ->next;
		}
		if(p == q)isFlag = 0;
		r = q;  //ɾ��qָ��Ľ�㣬���˳���
		p ->next = q ->next;
		q = q->next;
		startpawd = q ->pawd;
		printf("��%d���˳��У����ֳֵ������ǣ�%d\n",r ->id,r ->pawd);
		free(r); 
	} 
	L = NULL;
	getchar();
} 



int main()
{
	int n, m;
 	LinkList L = NULL;
 	while(1)
 	{
	  printf("����������n�����%d����: ", MAX_SIZE);  
        scanf("%d", &n);         
        printf("�ͳ�ʼ����m: ");  
        scanf("%d", &m);  
        if (n > MAX_SIZE)  
        {  
            printf("����̫�࣬���������룡\n");  
            continue;  
        }  
        else  
            break;  	
 	}
 	ListCreate(L,n);
    printf("\n------------ ѭ������ԭʼ��ӡ -------------\n");  
    ListPrint(L);  
    printf("\n-------------ɾ�����������ӡ -------------\n");  
    StartGame(L, m);  
	return 0;
}