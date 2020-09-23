#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>


typedef struct Snakes//组成蛇的身体成员结构体 
{
	int x;
	int y;
	struct Snakes *next;
}snake;//蛇身体成员结构体变量 

snake *head;
snake *tail;//尾巴是没有存放东西的空结构体指针 

int speed[5]={30,80,130,180,230};//速度等级初始化 

char name[5][100]={"泰坦巨蟒","眼镜王蛇","赖皮蛇  ","黄鳝    ","蚯蚓    "};//等级数组 

int grade;//等级输入 

int score=0;//分数记录 

int *p_a1;//记录最后一个身体块的X地址

int *p_a2;//记录最后一个身体块的Y地址 

char sign;//接受字符的信号 

struct Food//食物出现的坐标 
{
	int x;
	int y;
}food;//食物结构体变量 

void end();//结束界面 

void change();//蛇身变色 

void begin();//游戏界面 

void gamegrade();//游戏等级选择 

int color(int c);//字体颜色变化 

void gotoxy(int x,int y);//光标移动

void gotoprintf(int x,int y);//光标移动打印

void map();//打印边框并定义蛇的初始长度和蛇出现的位置 

void getfood();//打印食物

int over();//判断结束条件 

void gotoclear(int x,int y);//覆盖打印 

void bodychange(int a,int b);//改变蛇身的位置（为接受到信号时） 

void moving();//接受到键盘信号后的蛇身位置的改变 

void eat();//吃到食物时蛇身的增长
 
int panduan();//判断是否结束
 
void HideCursor();//隐藏光标
 
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
	printf("■"); 
}

void gotoclear(int x,int y)
{
	gotoxy(x,y);
	printf("  ");//覆盖两个字符 
}

void map()
{
	int x,y;//边框打印（x=0,x=56）;（y=0,y=26） 
	for(x=0;x<57;x=x+2) 
	{
		gotoprintf(x,0);
		gotoprintf(x,26);
	}
	for(y=0;y<26;y++)
	{
		gotoprintf(0,y);
		gotoprintf(56,y);
	}//x两格为一个前进坐标单位，y一格为一个前进单位 
	snake *p;
	head=(snake*)malloc(sizeof(snake));
	p=(snake*)malloc(sizeof(snake));
	snake *q;
	q=(snake*)malloc(sizeof(snake));
	tail=(snake*)malloc(sizeof(snake));//申请空间为结构体指针成员赋值
	head->x=26;
	head->y=11;
	p->x=26;
	p->y=12;
	q->x=26;
	q->y=13;//对蛇身块进行赋值 
	head->next=p;
	p->next=q;
	q->next=tail;//将蛇身用链表连在一起 
	tail->next=NULL;//初始蛇的位置和长度，并空出一个tail的指针空间为后面链表插入准备 

}

void getfood()
{
	srand((int)time(NULL));//随机种子 
again:
	food.x=rand()%54+1;//随机食物的x轴 
	food.y=rand()%25+1;//随机食物的y轴 
	if(food.x%2!=0){
		food.x=food.x+1;
	}//x轴是两个字符为一个前进坐标，所以x只会出现在x为偶数的坐标轴上 
	snake *panduan=head;//申请结构体指针，取蛇头的地址 
	while(1){
		if(panduan->next==NULL){
			break;
		}
		if(panduan->x==food.x&&panduan->y==food.y){
			goto again;
		}
		panduan=panduan->next;
	}//遍历蛇的身体，使食物不会出现在蛇身体上 
	gotoxy(food.x,food.y);//得到正确的食物坐标 
	printf("★");//打印食物 
}

void bodychange(int a,int b)
{
	snake *p=head->next;
	int a1,a2,b1,b2;//存储蛇身坐标 
	a1=p->x;
	a2=p->y;
	while(1){
		if(p->next->next==NULL){
			break;
		}
		b1=p->next->x;
		b2=p->next->y;//将P的下一个身体块的XY储存起来 
		p->next->x=a1;
		p->next->y=a2;//将P的XY赋值给P的下一个身体块
		a1=b1;
		a2=b2;
		p=p->next;//改变P的指向，指向P的下个身体块，对其赋上一个新P的下个身体块的值 
	}
	p_a1=&a1;
	p_a2=&a2;//取最后一个身体块的XY的值 
	p=head->next;//P初始化 
	p->x=a;
	p->y=b;//head->next是没有被填充的，所以补上原来的蛇头坐标即可 
}

void moving()
{
	int a=head->x;
	int b=head->y;//保存改变前的蛇头坐标，将坐标给bodychange()函数 
	snake *p=head;
	while(1){
		if(p->next==NULL){
			break;
		}
		gotoclear(p->x,p->y);
		p=p->next;
	}//清空蛇身 
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
	printf("你的分数为：%d",score);
	gotoxy(60,14);
	printf("你的等级为：%s",name[grade]);
	change(); //改蛇的速度和颜色 
	p=head;//蛇身改变后的head 
	while (1)
	{
		if (p->next==NULL) break;
		gotoprintf(p->x,p->y);
		p=p->next;
	}//重新打印蛇头改变后的身体 
	Sleep(speed[grade]);
}

void eat()
{
	if(food.x==head->x&&food.y==head->y){
		score=score+10;
		getfood();
		snake *_p=(snake*)malloc(sizeof(snake));//新生成的蛇身块
		_p->x=(*p_a1);
		_p->y=(*p_a2);//给新生成的蛇身块赋上前一个蛇的最后一个蛇身块 
		snake *p;
		p=head;
		while(1){
			if(p->next->next==NULL){
				 break;
			}
			p=p->next;
		}//遍历蛇身得到最后一个蛇身块结构的地址 
		p->next=_p;//对新的蛇身的最后一个蛇身块赋值 
		_p->next=tail; //重新开出一个tail空间给后面增加蛇身块 
	}
}

int over()
{
	if(head->x==0||head->x==56||head->y==0||head->y==26){
		return 0;
	}//如果蛇头碰到墙就结束游戏 
	snake *p=head->next;
	while(1){
		if(p->next==NULL){
			break;
		}
		if(head->x==p->x&&head->y==p->y){
			return 0;
		}
		p=p->next;
	}//遍历蛇身，判断蛇头是否与蛇身重合，如果重合就结束游戏 
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
		}//接受到键盘输入的字符，将其赋给sign，到moving函数里对其进行判断 
		moving();
		eat();
	}
	return 1;
}

void begin()
{
	char a;
	color(3);
	printf("\n\n                                                  游戏开始                                            \n\n");
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
	printf ("                                             按回车键开始游戏                                         ");
	scanf("%c",&a);
	system("cls");
}

void gamegrade()
{
	int a;
	color(2);
	gotoxy(30,2);
	printf("                       游戏说明                      "); 
	color(3);
	gotoxy(30,5);
	printf("        请在英文输入法中输入wsad控制蛇的移动方向      "); 
	color(1);
	gotoxy(30,8);
	printf("            蛇头撞墙或者反向移动则结束游戏            "); 
	gotoxy(30,10);
	color(5); 
	printf("                       游戏等级                       ");
	gotoxy(30,12);
	color(5);
	printf("=====================================================");
	color(3);
	gotoxy(30,14);
	printf("游戏等级:蚯蚓 -> 黄鳝 -> 赖皮蛇 -> 眼镜王蛇 -> 泰坦巨蟒");
	gotoxy(30,16);
	color(5);
	printf("=====================================================");
	gotoxy(30,18);
	color(7);
	printf("           等级越高，蛇的速度越快，加油吧！           "); 
	color(9);
	gotoxy(30,20);
	printf("                按回车键进入游戏界面                 "); 
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
 	printf("        你的最终成绩为：%d",score);
 	gotoxy(30,13);
 	printf("        你的最终等级为：%s",name[grade]);
 	color(2);
	gotoxy(30,15);
	if(grade==0){
		printf("   难道你就是传说中的驱蛇大师吗！！！"); 
	}
	else if(grade==1){
		printf("   你已经成为驱蛇专家，下次继续加油哦!");
	}else if(grade==2){
		printf("     你已经成为驱蛇人，继续努力吧！");
	}else if(grade==3){
		printf("   你的技术不行啊，小老弟继续加油咯！"); 
	}else{
		printf("   你是在用脚玩游戏吗？不忍直视。。。");
	}
	gotoxy(30,18);
	printf("=============欢迎下次再来哦~==============");
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;    //光标.可见=否
	cursor.dwSize = sizeof(cursor);    //光标.尺寸=大小(光标)
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    //获取一个标准的句柄。。大概？
	SetConsoleCursorInfo(handle, &cursor);
}



