#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node 
{
	char no[12];//员工编号
	char name[40];//员工名字
	int month[12];//月份
	float gz[12];//月工资
	float total;//年度总工资
	struct node *next;//指向下一节点的指针
};

struct node *l=NULL;

void sum_total(struct node *p){//计算总工资
	int i;
	p->total=0;
	for(i=0;i<12;i++)
	{
		p->total+=p->gz[i];
	}
}

void input_information(){  //录入员工每个月的工资信息
	int a,i,j;
	struct node *p=NULL;
	printf("请输入要录入的员工数量:");
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		p=(struct node*)malloc(sizeof(struct node));
		system("cls");
		printf("请输入员工%d的信息:\n",i+1);
		printf("员工编号:");
		scanf("%s",p->no);
		printf("员工姓名:");
		scanf("%s",p->name);
		for(j=0;j<12;j++)
		{
		    printf("%d月工资:",j+1);
		    scanf("%f",&p->gz[j]);
		}
		p->next=l;
		l=p;
		sum_total(p);
	}
	system("cls");
    printf("录入完成，按任意键返回主页面");
	getchar();
	getchar();
	system("cls");
}

void all_information(){ //查看某个员工的全部信息
	int i=0,j;
	char name_1[40];
	struct node *p=l;
	printf("请输入查找的员工姓名或编号:");
	scanf("%s",name_1);
	while(p->next)
	{
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			printf("员工编号:\t%s\n",p->no);
			printf("员工姓名:\t%s\n",p->name);
			for(j=1;j<=12;j++)
			{
				printf("%d月工资:\t%.2f\n",j,p->gz[j-1]);
			}
			printf("年度总工资:     %.2f\n",p->total);
			getchar();
			getchar();
			system("cls");
            printf("查找完成，按任意键返回主页面");
			i=1;
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("该员工不存在!");
		getchar();
	}
	getchar();
	system("cls");
}

void query_information(){  //查找某个员工某个月的工资
	int a,i=0;
	char name_1[40];
	struct node *p=l;
	printf("请输入查找的员工姓名或编号:");
	scanf("%s",name_1);
	while(p->next)
	{
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			i=1;
			printf("请输入查找的月份:");
	        scanf("%d",&a);
			if(a>12)
			{
				printf("输入的月份有误!");
				getchar();
				break;
			}
			printf("该月工资为:%.2f\n",p->gz[a-1]);
			getchar();
			getchar();
			system("cls");
            printf("查找完成，按任意键返回主页面");
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("该员工不存在!");
		getchar();
	}
	getchar();
	system("cls");
}

void change_information(){  //修改某个员工某个月的工资
	int a,i=0;
	float b;
	char name_1[40];
	struct node *p=l;
	printf("请输入要修改的员工姓名或编号:");
	scanf("%s",name_1);
	while(p->next){
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			i=1;
	        printf("请输入要修改的工资月份:");
	        scanf("%d",&a);
			if(a>12)
			{
				printf("输入的月份有误!");
				break;
			}
	        printf("请输入要修改成的工资数额:");
	        scanf("%f",&b);
			p->gz[a-1]=b;
			system("cls");
            printf("修改完成，按任意键返回主页面");
			sum_total(p);
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("该员工不存在!");
	}
	getchar();
	getchar();
	system("cls");
}

void delete_information(){  //删除某个员工的工资的相关信息
    int i=0;
	char name_1[40];
	struct node *p=l,*q=NULL;
	printf("请输入要删除的员工姓名或编号:");
	scanf("%s",name_1);
	while(p->next)
	{
		q=p->next;
	    if(strcmp(q->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
		    p->next=q->next;
		    free(q);
		    system("cls");
		    printf("删除成功!按任意键返回主页面");
		    i=1;
		    break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("该员工不存在!");
	}
	getchar();
	getchar();
	system("cls");
}

void statistics(){  //统计某个职工年度总工资
    int i=0;
	char name_1[40];
	struct node *p=l;
	printf("请输入要统计的员工姓名或编号:");
	scanf("%s",name_1);
	while(p->next)
	{
		if(strcmp(p->name,name_1)==0||strcmp(p->no,name_1)==0)
		{
			printf("员工编号:%s\n姓名:%s\n总工资:%.2f",p->no,p->name,p->total);
			getchar();
			getchar();
		    system("cls");
            printf("查找结束，按任意键返回主页面");
			i=1;
			break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("该员工不存在!");
		getchar();
	}
	getchar();
	system("cls");
}

int position(){  //按员工的月工资或年度总工资进行排名
	int a,b;
	struct node *p,*q,*i,sth;
	p=l;
	if(p->next==0||p->next->next==0)
	{
		printf("当前小于两个员工，无法进行排序");
		getchar();
		getchar();
		system("cls");
		return 0;
	}
	printf("1:按月工资进行排名\n2:按年度总工资进行排名\n");
	printf("请输入你的命令:");
	scanf("%d",&a);
	switch(a){
	case 1:
		printf("请输入要进行排序的月份:");
		scanf("%d",&b);
		if(b>12)
		{
			printf("输入的命令不对!\n");
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
	    printf("员工编号\t员工姓名\t第%d月工资\n",b);
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
	    printf("员工编号\t\t员工姓名\t\t年度总工资\n");
	    while(p->next)
		{
		    printf("%-15s\t\t%-15s\t\t%.2f\n",p->no,p->name,p->total);
		    p=p->next;
		}
		break;
	default:
		printf("输入的命令不对!\n");
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
        printf("\t这是工资管理系统，输入您要进行的操作\n");
        printf("\t\t1:录入员工每个月的工资信息\n");
	    printf("\t\t2:查看某个员工的全部信息\n");
        printf("\t\t3:查找某个员工某个月的工资\n");
	    printf("\t\t4:修改某个员工某个月的工资\n");
	    printf("\t\t5:删除某个员工的工资的相关信息\n");
	    printf("\t\t6:统计某个职工年度总工资\n");
	    printf("\t\t7:按员工的月工资或年度总工资进行排名\n");
	    printf("\n\n请输入命令:\n");
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
		    printf("输入的命令不对!\n");
		    break;
		}
	}
}

