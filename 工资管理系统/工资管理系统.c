#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node 
{
	char no[12];//Ա�����
	char name[40];//Ա������
	int month[12];//�·�
	float gz[12];//�¹���
	float total;//����ܹ���
	struct node *next;//ָ����һ�ڵ��ָ��
};

struct node *l=NULL;

void sum_total(struct node *p){//�����ܹ���
	int i;
	p->total=0;
	for(i=0;i<12;i++)
	{
		p->total+=p->gz[i];
	}
}

void input_information(){  //¼��Ա��ÿ���µĹ�����Ϣ
	int a,i,j;
	struct node *p=NULL;
	printf("������Ҫ¼���Ա������:");
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		p=(struct node*)malloc(sizeof(struct node));
		system("cls");
		printf("������Ա��%d����Ϣ:\n",i+1);
		printf("Ա�����:");
		scanf("%s",p->no);
		printf("Ա������:");
		scanf("%s",p->name);
		for(j=0;j<12;j++)
		{
		    printf("%d�¹���:",j+1);
		    scanf("%f",&p->gz[j]);
		}
		p->next=l;
		l=p;
		sum_total(p);
	}
	system("cls");
    printf("¼����ɣ��������������ҳ��");
	getchar();
	getchar();
	system("cls");
}

void all_information(){ //�鿴ĳ��Ա����ȫ����Ϣ
	int i=0,j;
	char name_1[40];
	struct node *p=l;
	printf("��������ҵ�Ա����������:");
	scanf("%s",name_1);
	while(p->next)
	{
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			printf("Ա�����:\t%s\n",p->no);
			printf("Ա������:\t%s\n",p->name);
			for(j=1;j<=12;j++)
			{
				printf("%d�¹���:\t%.2f\n",j,p->gz[j-1]);
			}
			printf("����ܹ���:     %.2f\n",p->total);
			getchar();
			getchar();
			system("cls");
            printf("������ɣ��������������ҳ��");
			i=1;
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("��Ա��������!");
		getchar();
	}
	getchar();
	system("cls");
}

void query_information(){  //����ĳ��Ա��ĳ���µĹ���
	int a,i=0;
	char name_1[40];
	struct node *p=l;
	printf("��������ҵ�Ա����������:");
	scanf("%s",name_1);
	while(p->next)
	{
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			i=1;
			printf("��������ҵ��·�:");
	        scanf("%d",&a);
			if(a>12)
			{
				printf("������·�����!");
				getchar();
				break;
			}
			printf("���¹���Ϊ:%.2f\n",p->gz[a-1]);
			getchar();
			getchar();
			system("cls");
            printf("������ɣ��������������ҳ��");
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("��Ա��������!");
		getchar();
	}
	getchar();
	system("cls");
}

void change_information(){  //�޸�ĳ��Ա��ĳ���µĹ���
	int a,i=0;
	float b;
	char name_1[40];
	struct node *p=l;
	printf("������Ҫ�޸ĵ�Ա����������:");
	scanf("%s",name_1);
	while(p->next){
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			i=1;
	        printf("������Ҫ�޸ĵĹ����·�:");
	        scanf("%d",&a);
			if(a>12)
			{
				printf("������·�����!");
				break;
			}
	        printf("������Ҫ�޸ĳɵĹ�������:");
	        scanf("%f",&b);
			p->gz[a-1]=b;
			system("cls");
            printf("�޸���ɣ��������������ҳ��");
			sum_total(p);
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("��Ա��������!");
	}
	getchar();
	getchar();
	system("cls");
}

void delete_information(){  //ɾ��ĳ��Ա���Ĺ��ʵ������Ϣ
    int i=0;
	char name_1[40];
	struct node *p=l,*q=NULL;
	printf("������Ҫɾ����Ա����������:");
	scanf("%s",name_1);
	while(p->next)
	{
		q=p->next;
	    if(strcmp(q->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
		    p->next=q->next;
		    free(q);
		    system("cls");
		    printf("ɾ���ɹ�!�������������ҳ��");
		    i=1;
		    break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("��Ա��������!");
	}
	getchar();
	getchar();
	system("cls");
}

void statistics(){  //ͳ��ĳ��ְ������ܹ���
    int i=0;
	char name_1[40];
	struct node *p=l;
	printf("������Ҫͳ�Ƶ�Ա����������:");
	scanf("%s",name_1);
	while(p->next)
	{
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			printf("Ա�����:%s\n����:%s\n�ܹ���:%.2f",p->no,p->name,p->total);
			getchar();
			getchar();
		    system("cls");
            printf("���ҽ������������������ҳ��");
			i=1;
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("��Ա��������!");
		getchar();
	}
	getchar();
	system("cls");
}

int position(){  //��Ա�����¹��ʻ�����ܹ��ʽ�������
	int a,b;
	struct node *p,*q,*i,sth;
	p=l;
	if(p->next==0||p->next->next==0)
	{
		printf("��ǰС������Ա�����޷���������");
		getchar();
		getchar();
		system("cls");
		return 0;
	}
	printf("1:���¹��ʽ�������\n2:������ܹ��ʽ�������\n");
	printf("�������������:");
	scanf("%d",&a);
	switch(a){
	case 1:
		printf("������Ҫ����������·�:");
		scanf("%d",&b);
		if(b>12)
		{
			printf("����������!\n");
			break;
		}
		while(p->next->next)
		{
			q=p->next;
			while(q->next)
			{
				if(p->gz[b-1]<q->gz[b-1])
				{
					sth=*p;
					*p=*q;
					*q=sth;
					i=p->next;
					p->next=q->next;
					q->next=i;
				}
				q=q->next;
			}
			p=p->next;
		}
		p=l;
	    printf("Ա�����\tԱ������\t��%d�¹���\n",b);
	    while(p->next)
		{
		    printf("%-15s\t\t%-15s\t\t%.2f\n",p->no,p->name,p->gz[b-1]);
		    p=p->next;
		}
        break;
	case 2:
		while(p->next->next)
		{
			q=p->next;
			while(q->next)
			{
				if(p->total<q->total)
				{
					sth=*p;
					*p=*q;
					*q=sth;
					i=p->next;
					p->next=q->next;
					q->next=i;
				}
				q=q->next;
			}
			p=p->next;
		}
		p=l;
	    printf("Ա�����\t\tԱ������\t\t����ܹ���\n");
	    while(p->next)
		{
		    printf("%-15s\t\t%-15s\t\t%.2f\n",p->no,p->name,p->total);
		    p=p->next;
		}
		break;
	default:
		printf("����������!\n");
		break;
	}
	getchar();
	getchar();
	system("cls");
	return 0;
}

void main(){
	int a;
	l=(struct node*)malloc(sizeof(struct node));
	l->next=0;
	while(1){
        printf("\t���ǹ��ʹ���ϵͳ��������Ҫ���еĲ���\n");
        printf("\t\t1:¼��Ա��ÿ���µĹ�����Ϣ\n");
	    printf("\t\t2:�鿴ĳ��Ա����ȫ����Ϣ\n");
        printf("\t\t3:����ĳ��Ա��ĳ���µĹ���\n");
	    printf("\t\t4:�޸�ĳ��Ա��ĳ���µĹ���\n");
	    printf("\t\t5:ɾ��ĳ��Ա���Ĺ��ʵ������Ϣ\n");
	    printf("\t\t6:ͳ��ĳ��ְ������ܹ���\n");
	    printf("\t\t7:��Ա�����¹��ʻ�����ܹ��ʽ�������\n");
	    printf("\n\n����������:\n");
	    scanf("%d",&a);
	    system("cls");
	    switch(a){
	    case 1:
		    input_information();
		    break;
	    case 2:
		    all_information();
			break;
	    case 3:
		    query_information();
		    break;
	    case 4:
		    change_information();
		    break;
	    case 5:
		    delete_information();
		    break;
	    case 6:
		    statistics();
		    break;
        case 7:
		    position();
		    break;
	    default:
		    printf("����������!\n");
		    break;
		}
	}
}

