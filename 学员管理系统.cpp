#include<stdio.h>
#include<string.h>
struct Student{
	char name[20];
	char sex[20];
	int num;
	int age;
};

struct Student  stu[20];

/*ѧ����Ϣ���*/
void add(int i){

	printf("������ѧ��������\n");
	getchar();
	scanf("%s",&stu[i].name);
	printf("������ѧ�����Ա�\n");
	getchar();
	scanf("%s",&stu[i].sex);
	printf("������ѧ��������\n");
	scanf("%d",&stu[i].age);
	printf("�ѳɹ���Ӹó�Ա\n");
	printf("num\tname\tsex\tage\n");
	printf("%d\t%s\t%s\t%d\n",i,stu[i].name,stu[i].sex,stu[i].age);

}

/*ѧ����Ϣɾ��*/
void delet(int i){
	int j;
	stu[i].num=0;
	stu[i].age=0;
	for(j=0;j<20;j++){
		stu[i].name[j]='\0';
		stu[i].sex[j]='\0';
	}

}

/*ѧ����Ϣ�޸�*/
void xiugai(int i){

	printf("������ѧ��������\n");
	getchar();
	scanf("%s",&stu[i].name);
	printf("������ѧ�����Ա�\n");
	getchar();
	scanf("%s",&stu[i].sex);
	printf("������ѧ��������\n");
	scanf("%d",&stu[i].age);
	printf("�����޸ĳɹ�\n");

}

 
/*ѧ����Ϣ��ѯ*/
void inquire(int i){//��ѯ��Ա��Ϣ
	printf("%d\t%s\t%s\t%d\n",i,stu[i].name,stu[i].sex,stu[i].age);
}


/*��ʾ���г�Ա��Ϣ*/
void all(int i){
	int j=0;
	for(j=0;j<i;j++){
		printf("%d\t%s\t%s\t%d\n",j,stu[j].name,stu[j].sex,stu[j].age);
	}
}

int main()
{
	printf("----------------------------------------\n");
	printf("--------------ѧԱ����ϵͳ--------------\n");
	printf("----------------------------------------\n");
	printf("a.��ӳ�Ա\nb.ɾ����Ա\nc.�޸ĳ�Ա��Ϣ\nd.��ѯ��Ա��Ϣ\ne.��ʾ����ѧԱ��Ϣ\nf.exit\n");
	int i=1;
	while(1){
		char faction;
		scanf("%c",&faction);
		if(faction=='a'){
			add(i);
			i++;
			continue;
		}

		else if(faction=='b'){
			int num;
			printf("��������Ҫɾ��ѧԱ��ѧ��");
			scanf("%d",&num);
			delet(num);
			continue;
		}

		else if(faction=='c'){
			int num;
			printf("��������Ҫ�޸�ѧԱ��ѧ��");
			scanf("%d",&num);
			xiugai(num);
			continue;
		}

		else if(faction=='d'){
			int num;
			printf("��������Ҫ��ѯѧԱ��ѧ��");
			scanf("%d",&num);
			inquire(num);
			continue;
		}

		else if(faction=='e'){
			printf("Ŀǰ��%dλѧ������Ϣ\n",i);
			if(i>0&&i<20){
				add(i);
			}
			continue;
		}

		if(faction=='f'){
			break;
		}
	}
	return 0;
}
