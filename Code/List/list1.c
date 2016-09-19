#include <stdio.h>
#include<malloc.h>


#define MAXSIZE 20
#define INCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//����һ��int�������͵ı���  
//������Ϊ��ʾ����int,ʵ��ʹ�õ�ͨ���Ǹ��ϵ��������� 
typedef int ElemType;  
typedef int Status;
typedef struct{
	ElemType *elem;   //�洢�ռ����ʼ��ַ
	int length;       //��ĵ�ǰ����
	int listsize;     //����ܴ洢����(sizeof(ElemType)) 
}SqList;

void printList(SqList L);
void InitList(SqList *L);
Status ListInsert(SqList *L,int i,ElemType e);

int main(int argc, char *argv[])
{
	SqList list;
	ElemType c;
	InitList(&list);
	int i;
	for(i = 1;i <= 11;i++){
		ListInsert(&list,i,i * 2);	
	}
	printf("�����ı�\n");
	printList(list);
	ListDelete(&list,2,&c);
	printf("ɾ����ı�\n"); 
	printList(list);
	printf("Hello C-Free!\n");
	return 0;
}



//1)����һ���ձ� 
void InitList(SqList *L){
	L -> elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if(!L -> elem)exit(ERROR);
	L -> length = 0;
	L -> listsize = MAXSIZE;
}

//2)������Ϊ�ձ�
void ClearList(SqList *L)  
{  
    L ->length = 0;  
}

//3)�жϱ��Ƿ�Ϊ��
Status ListEmpty(SqList L)
{	
	return L.length == 0?TRUE:FALSE;
} 


//4)���ٱ�
void DestoryList(SqList *L)
{
	free(L ->elem);
	L ->elem = NULL;
	L ->length = 0;
	L ->listsize = 0;
} 

//5)��õ�ǰ����Ԫ�ص���Ŀ  
int ListLength(SqList L)  
{  
    return L.length;   
}

//6)��ñ��е�i������Ԫ�ص�ֵ
Status GetElem(SqList L,int i,ElemType *e)
{
	if(i < 1||i > L.length)return ERROR;
	e = *(L.elem + i - 1);
	return OK; 
}  

//7)���ұ����Ƿ�������Ҫ���Ԫ��
//���ر��е�һ������Ҫ���Ԫ�ص��±�  
//�������ǰ�Ҫ�����Ϊһ������compare(int l_s,int e);   
//��������Ϊ����Ԫ������Ҫ���й�ϵ�ȽϵĲ���e  
//��������������ָ��,ָ������ָ��
int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))  
{  
    int i = 1;  
    ElemType *p = L.elem;  
    while(i < L.length && !compare(*p++,e))  
    i++;  
    if(i <= L.length) return i;  
    else return 0;  
}   

//8)����ĳ���ڵ��ֱ��ǰ��
//�ڶ����͵����������ֱ�Ϊ��ָ��������Ԫ�أ�before�����洢����ǰ����
Status PriorElem(SqList L,ElemType choose,ElemType *before){
	int i = 2;
	ElemType *p = L.elem + 1;
	while(i < L.length && *p != choose)
	{
		p++;
		i++;
	}
	if(i > L.length)return ERROR;
	else
	{
		before = *--p;
		return OK;
	}		
} 


//9.����ĳ���ڵ�ĺ�� 
//�ڶ�������������Ϊ:ѡ��������Ԫ�ص�ֵ,�洢��̵ı��� 
Status NextElem(SqList L,ElemType choose,ElemType *behind)
{
	int i = 0;
	ElemType *p = L.elem; 
	while(i < L.length && *p != choose)
	{
		p++;
		i++; 
	} 
	if(i == L.length)return ERROR;
	else{
		behind = * ++p;
		return OK;
	}
}

//10.�����е�i��λ�ò���Ԫ��
Status ListInsert(SqList *L,int i,ElemType e)
{
	ElemType *p,*q,*newbase;
	//�жϲ���λ���Ƿ�Ϸ�
	if(i < 1 || i > L -> length + 1)return ERROR;
	//��������˵Ļ������ӷ���Ŀռ� 
	if(L -> length == L -> listsize)
	{
		newbase = (ElemType *)realloc(L -> elem,(L -> listsize + INCREMENT)*sizeof(ElemType));
		if(!newbase)exit(ERROR);
		L ->elem = newbase;
		L ->listsize += INCREMENT;
	} 
	//����λ�� 
	q = L ->elem + i - 1;
	//�����ƣ����ƶ����һ��
	for(p = L ->elem + L->length - 1;p >= q;--p)
	{
		*(p + 1) = *p;	 
	} 
	*q= e;      //����Ԫ�� 
	++L->length;   //�� + 1  
	return OK;
}
 
 
//11.ɾ�����еĵ�i��λ�õ�Ԫ��
Status ListDelete(SqList *L,int i,ElemType *e)
{
	ElemType *p,*q;
	//�ж�ɾ����λ���Ƿ�Ϸ�
	if(i < 1 || i > L ->length)return ERROR;
	//Pָ��ָ��ɾ��λ�ã���Ҫɾ����Ԫ�ظ�ֵ��e
	p = L ->elem + i - 1;
	e = *p;
	//qָ��ָ�����һ��Ԫ�أ���ɾ��λ�ú��Ԫ�ؿ�ʼ����
	q = L ->elem + L ->length - 1;
	for(++p;p <= q;++p)
	{
		*(p - 1) = *p;		
	} 
	L ->length--; //��-1	
	return OK;	
} 

//12.�������е�����Ԫ��
void ListTraverse(SqList L,void(* visit)(ElemType))
{
 	int i;
 	ElemType *p = L.elem;
 	for(i = 1;i < L.length;i++)
 	{
 		visit(*p++);
 		printf("\n");
 	}
}

//��ӡ�������е�Ԫ��
void printList(SqList L){
	int i;
	ElemType *p = L.elem;
	for(i = 1;i< L.length;i++)
	{
		printf("���еĵ�%d��Ԫ�ص�ֵΪ��%d\n",i,*p++);
	}
} 



//Ӧ��Сʾ������������Ĳ���
void UnionList(SqList La,SqList Lb,SqList *Lc)
{
	//1.����ָ���A,B��ͷ����β��ָ��
	ElemType *la,*la_end,*lb,*lb_end,*lc;
	la = La.elem;
	lb = Lb.elem;
	la_end = La.elem + La.length - 1;
    lb_end = Lb.elem + Lb.length - 1;
    //2.Ϊ��C�����ڴ�ռ䣬��СΪ��A���� + ��B�ĳ���
	Lc ->listsize  = La.length + Lb.length;
	lc = Lc ->elem = (ElemType *)malloc(Lc ->listsize * sizeof(ElemType));
	if(!lc)exit(ERROR);
	//3.����A��B�е�Ԫ�ؽ��кϲ��� 
	while(la <= la_end && lb <= lb_end)
	{
		if(*la <= *lb)*lc++ = *la++;
		else *lc++ = *lb++;
	} 
	//4.������ʣ���Ԫ�أ�Ҫô�Ǳ�A,Ҫô�Ǳ�B��
	while(la < la_end)*lc++ = *la++;
	while(lb < lb_end)*lc++ = *lb++;
	//5.����Ҫ��C�����ظ���Ԫ��ɾ��������������öָ�� 
	ElemType *p,*q;
	p = Lc ->elem;
	q = p;
	//6.ѭ����������ָ��pû��ָ���β
	while(p != (Lc ->elem + Lc ->length - 1))
	{
		//qָ��p�ĺ��Ԫ�أ��Ƚ�������ֵ
		if(*p != *(++q))
		{
			p++;
			q = p;
		} 
		//��ȵĻ���ɾ��q��ָ���Ԫ��
		else
		{
			while(*p == *q);
		//	ListDelete(Lc,(p - Lc ->elem),e);
		} 
	} 
}