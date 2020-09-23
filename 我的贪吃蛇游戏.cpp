#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>


typedef struct Snakes//����ߵ������Ա�ṹ�� 
{
	int x;
	int y;
	struct Snakes *next;
}snake;//�������Ա�ṹ����� 

snake *head;
snake *tail;//β����û�д�Ŷ����Ŀսṹ��ָ�� 

int speed[5]={30,80,130,180,230};//�ٶȵȼ���ʼ�� 

char name[5][100]={"̩̹����","�۾�����","��Ƥ��  ","����    ","���    "};//�ȼ����� 

int grade;//�ȼ����� 

int score=0;//������¼ 

int *p_a1;//��¼���һ��������X��ַ

int *p_a2;//��¼���һ��������Y��ַ 

char sign;//�����ַ����ź� 

struct Food//ʳ����ֵ����� 
{
	int x;
	int y;
}food;//ʳ��ṹ����� 

void end();//�������� 

void change();//�����ɫ 

void begin();//��Ϸ���� 

void gamegrade();//��Ϸ�ȼ�ѡ�� 

int color(int c);//������ɫ�仯 

void gotoxy(int x,int y);//����ƶ�

void gotoprintf(int x,int y);//����ƶ���ӡ

void map();//��ӡ�߿򲢶����ߵĳ�ʼ���Ⱥ��߳��ֵ�λ�� 

void getfood();//��ӡʳ��

int over();//�жϽ������� 

void gotoclear(int x,int y);//���Ǵ�ӡ 

void bodychange(int a,int b);//�ı������λ�ã�Ϊ���ܵ��ź�ʱ�� 

void moving();//���ܵ������źź������λ�õĸı� 

void eat();//�Ե�ʳ��ʱ���������
 
int panduan();//�ж��Ƿ����
 
void HideCursor();//���ع��
 
int main(){
	HideCursor();
	begin();
	gamegrade(); 
	color(7);
	map();
	getfood();
	if(panduan()==0){
		gotoxy(0,28);
		system("cls");
		end();
	 	gotoxy(30,20);
		return 0;
	}
	system("cls");
	end();
 	gotoxy(30,20);
	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void gotoprintf(int x,int y)
{
	gotoxy(x,y);
	printf("��"); 
}

void gotoclear(int x,int y)
{
	gotoxy(x,y);
	printf("  ");//���������ַ� 
}

void map()
{
	int x,y;//�߿��ӡ��x=0,x=56��;��y=0,y=26�� 
	for(x=0;x<57;x=x+2) 
	{
		gotoprintf(x,0);
		gotoprintf(x,26);
	}
	for(y=0;y<26;y++)
	{
		gotoprintf(0,y);
		gotoprintf(56,y);
	}//x����Ϊһ��ǰ�����굥λ��yһ��Ϊһ��ǰ����λ 
	snake *p;
	head=(snake*)malloc(sizeof(snake));
	p=(snake*)malloc(sizeof(snake));
	snake *q;
	q=(snake*)malloc(sizeof(snake));
	tail=(snake*)malloc(sizeof(snake));//����ռ�Ϊ�ṹ��ָ���Ա��ֵ
	head->x=26;
	head->y=11;
	p->x=26;
	p->y=12;
	q->x=26;
	q->y=13;//���������и�ֵ 
	head->next=p;
	p->next=q;
	q->next=tail;//����������������һ�� 
	tail->next=NULL;//��ʼ�ߵ�λ�úͳ��ȣ����ճ�һ��tail��ָ��ռ�Ϊ�����������׼�� 

}

void getfood()
{
	srand((int)time(NULL));//������� 
again:
	food.x=rand()%54+1;//���ʳ���x�� 
	food.y=rand()%25+1;//���ʳ���y�� 
	if(food.x%2!=0){
		food.x=food.x+1;
	}//x���������ַ�Ϊһ��ǰ�����꣬����xֻ�������xΪż������������ 
	snake *panduan=head;//����ṹ��ָ�룬ȡ��ͷ�ĵ�ַ 
	while(1){
		if(panduan->next==NULL){
			break;
		}
		if(panduan->x==food.x&&panduan->y==food.y){
			goto again;
		}
		panduan=panduan->next;
	}//�����ߵ����壬ʹʳ�ﲻ��������������� 
	gotoxy(food.x,food.y);//�õ���ȷ��ʳ������ 
	printf("��");//��ӡʳ�� 
}

void bodychange(int a,int b)
{
	snake *p=head->next;
	int a1,a2,b1,b2;//�洢�������� 
	a1=p->x;
	a2=p->y;
	while(1){
		if(p->next->next==NULL){
			break;
		}
		b1=p->next->x;
		b2=p->next->y;//��P����һ��������XY�������� 
		p->next->x=a1;
		p->next->y=a2;//��P��XY��ֵ��P����һ�������
		a1=b1;
		a2=b2;
		p=p->next;//�ı�P��ָ��ָ��P���¸�����飬���丳��һ����P���¸�������ֵ 
	}
	p_a1=&a1;
	p_a2=&a2;//ȡ���һ��������XY��ֵ 
	p=head->next;//P��ʼ�� 
	p->x=a;
	p->y=b;//head->next��û�б����ģ����Բ���ԭ������ͷ���꼴�� 
}

void moving()
{
	int a=head->x;
	int b=head->y;//����ı�ǰ����ͷ���꣬�������bodychange()���� 
	snake *p=head;
	while(1){
		if(p->next==NULL){
			break;
		}
		gotoclear(p->x,p->y);
		p=p->next;
	}//������� 
	if(sign=='w'){
		head->y-=1;
		bodychange(a,b);
	}
	else if(sign=='a'){
		head->x-=2;
		bodychange(a,b);
	}
	else if(sign=='s'){
		head->y+=1;
		bodychange(a,b);
	}
	else if(sign=='d'){
		head->x+=2;
		bodychange(a,b);
	}
	color(2);
	gotoxy(60,12);
	printf("��ķ���Ϊ��%d",score);
	gotoxy(60,14);
	printf("��ĵȼ�Ϊ��%s",name[grade]);
	change(); //���ߵ��ٶȺ���ɫ 
	p=head;//����ı���head 
	while (1)
	{
		if (p->next==NULL) break;
		gotoprintf(p->x,p->y);
		p=p->next;
	}//���´�ӡ��ͷ�ı������� 
	Sleep(speed[grade]);
}

void eat()
{
	if(food.x==head->x&&food.y==head->y){
		score=score+10;
		getfood();
		snake *_p=(snake*)malloc(sizeof(snake));//�����ɵ������
		_p->x=(*p_a1);
		_p->y=(*p_a2);//�������ɵ�����鸳��ǰһ���ߵ����һ������� 
		snake *p;
		p=head;
		while(1){
			if(p->next->next==NULL){
				 break;
			}
			p=p->next;
		}//��������õ����һ�������ṹ�ĵ�ַ 
		p->next=_p;//���µ���������һ������鸳ֵ 
		_p->next=tail; //���¿���һ��tail�ռ��������������� 
	}
}

int over()
{
	if(head->x==0||head->x==56||head->y==0||head->y==26){
		return 0;
	}//�����ͷ����ǽ�ͽ�����Ϸ 
	snake *p=head->next;
	while(1){
		if(p->next==NULL){
			break;
		}
		if(head->x==p->x&&head->y==p->y){
			return 0;
		}
		p=p->next;
	}//���������ж���ͷ�Ƿ��������غϣ�����غϾͽ�����Ϸ 
	return 1;
}

int panduan()
{
	while(1){
		if(over()==0){
			return 0;
		}
		if(kbhit()){
			sign=getch();
		}//���ܵ�����������ַ������丳��sign����moving�������������ж� 
		moving();
		eat();
	}
	return 1;
}

void begin()
{
	char a;
	color(3);
	printf("\n\n                                                  ��Ϸ��ʼ                                            \n\n");
	color(6);
	printf("                       __________       ___                                              \n");
	printf("                      /          \\     / \\ \\    |____      __\\__                     \n");
	printf("                     /  ________  \\   / ___ \\  _/ __     | |   /                       \n");
	printf("                     |  |      |__|     _/_   |_|  /    [|] |/                           \n");
	printf("                     |  |              | | |      /     _|_ \\__/                        \n");
	printf("                     \\  \\_______        / \\      |___/        ____                    \n");
	printf("                      \\         \\    ____ ____      ____   __ |  |  ___   ______       \n");
	printf("                       \\_______  \\   |  |/    \\    /    \\_/ / |  | /  /  /      \\   \n");
	printf("                               \\  \\  |    ___  \\  / ____   /  |  |/  /  /  ____  \\   \n");
	printf("                     __        |  |  |   /   \\  \\ | |  |  /   |     /  |  /____\\  |   \n");
	printf("                    \\  \\_______|  |  |  |    |  | | |__|  |   |     \\  |  ________/   \n");
	printf("                     \\            /  |  |    |  |  \\       \\  |  |\\  \\  \\  \\____  \n");
	printf("                      \\__________/   |__|    |__|   \\___/\\__\\ |__| \\__\\  \\______/ \n\n");	
	color(2);
	printf ("                                             ���س�����ʼ��Ϸ                                         ");
	scanf("%c",&a);
	system("cls");
}

void gamegrade()
{
	int a;
	color(2);
	gotoxy(30,2);
	printf("                       ��Ϸ˵��                      "); 
	color(3);
	gotoxy(30,5);
	printf("        ����Ӣ�����뷨������wsad�����ߵ��ƶ�����      "); 
	color(1);
	gotoxy(30,8);
	printf("            ��ͷײǽ���߷����ƶ��������Ϸ            "); 
	gotoxy(30,10);
	color(5); 
	printf("                       ��Ϸ�ȼ�                       ");
	gotoxy(30,12);
	color(5);
	printf("=====================================================");
	color(3);
	gotoxy(30,14);
	printf("��Ϸ�ȼ�:��� -> ���� -> ��Ƥ�� -> �۾����� -> ̩̹����");
	gotoxy(30,16);
	color(5);
	printf("=====================================================");
	gotoxy(30,18);
	color(7);
	printf("           �ȼ�Խ�ߣ��ߵ��ٶ�Խ�죬���Ͱɣ�           "); 
	color(9);
	gotoxy(30,20);
	printf("                ���س���������Ϸ����                 "); 
	scanf("%c",&a);
	grade=0;
	system("cls");
}

int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

void change()
{
	if(score>=0&&score<=80){
		color(1);
		grade=4;
	}
	else if(score>80&&score<=160){

		color(2);
		grade=3;
	}
	else if(score>160&&score<=240){
		color(3);
		grade=2;
	}
	else if(score>240&&score<=320){
		color(4);
		grade=1;
	}
	else{	
		color(5);
		grade=0;
	}
}

void end()
{
	gotoxy(30,8);
	printf("                game over                ");
	color(2);
 	gotoxy(30,10);
 	printf("=========================================");
 	color(4);
 	gotoxy(30,12);
 	printf("        ������ճɼ�Ϊ��%d",score);
 	gotoxy(30,13);
 	printf("        ������յȼ�Ϊ��%s",name[grade]);
 	color(2);
	gotoxy(30,15);
	if(grade==0){
		printf("   �ѵ�����Ǵ�˵�е����ߴ�ʦ�𣡣���"); 
	}
	else if(grade==1){
		printf("   ���Ѿ���Ϊ����ר�ң��´μ�������Ŷ!");
	}else if(grade==2){
		printf("     ���Ѿ���Ϊ�����ˣ�����Ŭ���ɣ�");
	}else if(grade==3){
		printf("   ��ļ������а���С�ϵܼ������Ϳ���"); 
	}else{
		printf("   �������ý�����Ϸ�𣿲���ֱ�ӡ�����");
	}
	gotoxy(30,18);
	printf("=============��ӭ�´�����Ŷ~==============");
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;    //���.�ɼ�=��
	cursor.dwSize = sizeof(cursor);    //���.�ߴ�=��С(���)
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    //��ȡһ����׼�ľ��������ţ�
	SetConsoleCursorInfo(handle, &cursor);
}



