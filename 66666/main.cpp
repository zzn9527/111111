#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
	char stdName[100];
	int stdAge;
	int stdId;
	struct Student *next;
};
struct Student* headP=NULL;//ͷβ�ڵ�ָ���
struct Student* tailP = NULL;

void Addstdent()
{
	struct Student *node = (struct Student*)malloc(sizeof(struct Student));
	int i = 0;
	if (node == NULL) {
		exit(-1);
	}//�ж�malloc����ռ��Ƿ�ɹ�����������
	

	printf("������ѧ�������䣺");
	scanf_s("%d",&node->stdAge);
	printf("������ѧ����ѧ�ţ�");
	scanf_s("%d", &node->stdId);	
	printf("������ѧ�����֣�");
	scanf_s("%s",node->stdName,100);//100��ȡ��NULL��ָ������ã���������
	node->next = NULL;
	if (headP== NULL)
	{
		headP = node;
		tailP = node;
	}
	else
	{
		tailP->next = node;
		tailP = node;
	}
	printf("��ӳɹ�������\n");
}

void Findstdent()
{
	printf("��������Ҫ����ѧ����ѧ�ţ�");
	int id;
	scanf_s("%d",&id);
	struct Student* Id = headP;
	int flag = 0;
	while (Id != NULL)
	{
		if (Id->stdId == id)
		{
			printf("������%s  ����: %d ѧ�ţ�%d\n", Id->stdName, Id->stdAge, Id->stdId);
			flag = 1;
			break;
		}
		else
		{
			Id=Id->next;
		}
		if (flag == 0)
			printf("��Ǹû�ҵ���ѧ������Ϣ\n");
	}
}
void Delstdent()
{
	printf("��������Ҫɾ����ѧ����Ϣ��ѧ��:");
	int id;
	scanf_s("%d",&id);
	struct Student* Id = headP;
	if (Id->stdId == id)//Ŀ��id��ͷ�ڵ�ʱ
	{
		headP = headP->next;
		free(Id);//�ͷſռ�
		Id = NULL;
		printf("�ѳɹ�ɾ��������\n");
		return 0;
	}
	struct Student* anterId = Id;
	Id = Id->next;
	while (Id != NULL)//Ŀ��id����ͷ�ڵ�ʱ
	{
		if (Id->stdId == id)
		{
			struct Student* next = Id->next;
			anterId->next = next;
			free(Id);
			Id = NULL;
			printf("�ѳɹ�ɾ��������\n");
			return;
		}
		else
		{
			anterId = Id;
			Id = Id->next;
		}
	}
	printf("��ѧ�������ڣ��޷�ɾ��!");
}
void Printstdent(struct Student *curp )
{
	if (curp == NULL)
	{
		printf("�ף���ǰ��û��ѧ��Ŷ��");
	}
	else
	{
		while(curp!=NULL)
		{
		printf("������%s  ����: %d ѧ�ţ�%d\n",curp->stdName,curp->stdAge,curp->stdId);
		curp=curp->next;
		}
	}
	
}


main()
{
	struct Student* curp=headP;
	printf("------------��ӭʹ�ü���ѧ��ϵͳ------------\n");
	printf("------------����1���ѧ����Ϣ---------------\n");
	printf("------------����2����ѧ����Ϣ---------------\n");
	printf("------------����3ɾ��ѧ����Ϣ---------------\n");		
	printf("------------����4��ӡȫ��ѧ����Ϣ-----------\n");		
	printf("------------����5�˳�ϵͳ-------------------\n");
	
	while (1)
	{
		char dir=0;
		dir=getchar();
		switch (dir)
		{
		case '1': Addstdent(); break;
		case '2': Findstdent(); break;
		case '3': Delstdent(); break;
		case '4': Printstdent(headP); break;
		case '5':exit(0); break;
		default:break;
		}

	}
	return 0;
}
