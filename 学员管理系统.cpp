#include<stdio.h>
#include<string.h>
struct Student{
	char name[20];
	char sex[20];
	int num;
	int age;
};

struct Student  stu[20];

/*学生信息添加*/
void add(int i){

	printf("请输入学生的姓名\n");
	getchar();
	scanf("%s",&stu[i].name);
	printf("请输入学生的性别\n");
	getchar();
	scanf("%s",&stu[i].sex);
	printf("请输入学生的年龄\n");
	scanf("%d",&stu[i].age);
	printf("已成功添加该成员\n");
	printf("num\tname\tsex\tage\n");
	printf("%d\t%s\t%s\t%d\n",i,stu[i].name,stu[i].sex,stu[i].age);

}

/*学生信息删除*/
void delet(int i){
	int j;
	stu[i].num=0;
	stu[i].age=0;
	for(j=0;j<20;j++){
		stu[i].name[j]='\0';
		stu[i].sex[j]='\0';
	}

}

/*学生信息修改*/
void xiugai(int i){

	printf("请输入学生的姓名\n");
	getchar();
	scanf("%s",&stu[i].name);
	printf("请输入学生的性别\n");
	getchar();
	scanf("%s",&stu[i].sex);
	printf("请输入学生的年龄\n");
	scanf("%d",&stu[i].age);
	printf("您已修改成功\n");

}

 
/*学生信息查询*/
void inquire(int i){//查询成员信息
	printf("%d\t%s\t%s\t%d\n",i,stu[i].name,stu[i].sex,stu[i].age);
}


/*显示所有成员信息*/
void all(int i){
	int j=0;
	for(j=0;j<i;j++){
		printf("%d\t%s\t%s\t%d\n",j,stu[j].name,stu[j].sex,stu[j].age);
	}
}

int main()
{
	printf("----------------------------------------\n");
	printf("--------------学员管理系统--------------\n");
	printf("----------------------------------------\n");
	printf("a.添加成员\nb.删除成员\nc.修改成员信息\nd.查询成员信息\ne.显示所有学员信息\nf.exit\n");
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
			printf("请输入你要删除学员的学号");
			scanf("%d",&num);
			delet(num);
			continue;
		}

		else if(faction=='c'){
			int num;
			printf("请输入你要修改学员的学号");
			scanf("%d",&num);
			xiugai(num);
			continue;
		}

		else if(faction=='d'){
			int num;
			printf("请输入你要查询学员的学号");
			scanf("%d",&num);
			inquire(num);
			continue;
		}

		else if(faction=='e'){
			printf("目前有%d位学生的信息\n",i);
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
