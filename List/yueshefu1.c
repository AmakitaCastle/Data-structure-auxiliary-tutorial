#include <stdio.h>
int main()
{
	//����: n(����),m(��m������),last(ʣ�������)
	int i,j,n,m,last;
	int tag[100];
	printf("����μӵ�����:\n");  
  	scanf("%d",&n);  
  	printf("����ÿ��������һ����:\n");  
  	scanf("%d",&m);
	printf("\n׼��������\n\n");     
  	//��ʼ������
	for(i = 0;i < n;i++)
	{
		tag[i] = 1;	
 	} 
 	 //��ʼ����
  	j = 1;
  	last = n;
  	for(i = 0;last > 1;i++)
  	{
		if(!tag[i%n])continue;
		if(j == m)
		{
			j = 1;
			tag[i%n] = 0;
			printf("��- %d -������ɱ�ˣ���ҿ���ƣ�žžž��\n",(i%n)+1);
			last--;
		}
		else j++;	
 	} 
 	for(i = 0;i < n;i++)if(tag[i])break;
 	printf("��- %d -���˻������ˣ�\n",i+1);
 	return 0;
}