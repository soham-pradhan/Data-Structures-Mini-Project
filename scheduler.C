#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

typedef struct node{
	char task[20];
	int data,data2;
	struct node *next, *prev;
}node;

typedef struct head{
	node *start;
}head;

void display1();
void displaytable();
void displaytable2();
void insertend( head *t, int ele, char name[],int time);
void deletebeg( head *t);
void deleteele( head *t, char ele[]);
void sortll(head *t);
void reverse(head *t);
void split(head *t1, head *t2, int aft);
void merge(head *t1, head *t2);
void display(head *t);
int clr_ip_buf();

void display1(){
	int gdriver = DETECT, gmode, errorcode;
	int left, top, right, bottom;
	int x,y,i,j=0;
	initgraph(&gdriver, &gmode, "../bgi");
	left=30;
	top=350;
	right=500;
	bottom=175;
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(left,top,right,bottom);
	floodfill(10,10,WHITE);
	for(i=0;i<20;i++){
		rectangle(left+j,top+j,right+j,bottom+j);
		j=j+3;
	}
	j=0;
	for(i=0;i<5;i++){
		outtextxy( 125+j, 240+25+j,"PROJECT ON HOMEWORK MANAGEMENT:");
		outtextxy(125+j, 260+25+j, "\n SOHAM PRADHAN-16102B0003");
		outtextxy(125+j, 280+25+j,"\n AAREM BARGE-16102B0006");
		outtextxy(125+j,300+25+j,"\n ANIRUDDHA INGLE-16102B0016");
		j+=0.5;
	}
	j=0;
	printf("\n\n\n\n\n");
	system("pause");
	while(!kbhit()){}
	system("cls");
}
void main(){
	head x,y;
	int gdriver = DETECT, gmode;
	int ch,ele,n,i,time;
	char name[20];
	x.start=NULL;
	y.start=NULL;
	initgraph(&gdriver, &gmode, "../bgi");
	display1();
	displaytable();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Enter No: of Initial Tasks:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter Date of Submission MMDD for Task %d :\n",i);
		scanf("%d",&ele);
		clr_ip_buf();
		printf("Enter Name of Task:\n");
		gets(name);
		printf("Enter the time duration for the task in hours:\n");
		scanf("%d",&time);
		insertend(&x,ele,name,time);
	}
	while(1){
		printf("\n1:InsertTask \n2:ScheduledTaskCompleted \n3:DeleteTask\n4:ScheduleTasks\n");
		printf("5:Reverse \n6:Split \n7:Merge \n8:Display \n9:Exit\n");
		printf("Enter choice:\t");
		scanf("%d",&ch);
		printf("\n");
		if(ch==9)
			break;
		switch(ch){
			case 1: displaytable2();
					printf("Enter Date of Submission MMDD for Task %d:\n",i);
					scanf("%d",&ele);
					clr_ip_buf();
					printf("Enter Name of Task:\n");
					gets(name);
					printf("Enter the Time Duration in Hours:\n");
					scanf("%d",&time);
					insertend(&x,ele,name,time);
					break;
			case 2:	if(x.start==NULL)
			   		printf("LL Empty\n");
				   	else{
						deletebeg(&x);
						display(&x);
			   		}
			   		break;
			case 3:	if(x.start==NULL)
				   		printf("LL Empty\n");
			   		else{
			   			clr_ip_buf();
						printf("Enter the task to be deleted:");
						gets(name);
						deleteele(&x,name);
						display(&x);
			    	}
			    	break;
			case 4: sortll(&x);
					display(&x);
					break;
			case 5:	reverse(&x);
					display(&x);
					break;
			case 6: printf("Enter the date MMDD you want to split after:");
					scanf("%d",&ele);
					split(&x,&y,ele);
					display(&x);
					display(&y);
					break;
			case 7: merge(&x,&y);
					display(&x);
					break;
			case 8: display(&x);
					break;
			default:printf("Invalid Operation \n");
		}
	}
	system("pause");
	getch();
	cleardevice();
	closegraph();
}

void displaytable()
{
	int gdriver = DETECT, gmode, errorcode;
	int left, top, right, bottom;
	int x,y,i,j=0,k=50;
	initgraph(&gdriver, &gmode, "../bgi");
	left = 50;
	top = 50;
	right = 100;
	bottom = 100;
	setcolor(YELLOW);

	setfillstyle(SOLID_FILL,BLACK);
	rectangle(left,top,right+60,bottom);
	floodfill(51,51,YELLOW);
	for(i=0;i<3;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left,top+k,right+60,bottom+k);
		floodfill(51,51,YELLOW);
		k=k+50;
	}
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top+50,right+50+60+j,bottom+50);
		floodfill(111+50,101,YELLOW);
		j=j+50;
	}
	j=0;
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168,125,"ECCF");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218,125,"DLDA");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268,125,"DSTR");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318,125,"DIM");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368,125,"AM 3");
	floodfill(51,51,YELLOW);
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top+100,right+50+60+j,bottom+100);
		floodfill(111+50,101,YELLOW);
		j=j+50;
	}
	j=0;
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168,175,"AM 3");
	floodfill(51,51,YELLOW);	
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218,175,"DIM");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268,175,"ECCF");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318,175,"DSTR");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368,175,"DLDA");
	floodfill(51,51,YELLOW);
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top+150,right+50+60+j,bottom+150);
		floodfill(111+50,101,YELLOW);
		j=j+50;
	}
	j=0;
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168,225,"ECCF");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218,225,"DSTR");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268,225,"DIM");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318,225,"DLDA");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368,225,"AM 3");
	floodfill(51,51,YELLOW);

	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65,75,"9.00-11.00");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65,125,"11.15-1.15");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65,175,"1.45-3.45");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65,225,"3.45-5.45");
	floodfill(51,51,YELLOW);
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top,right+50+60+j,bottom);
		floodfill(51+50,51,YELLOW);
		j=j+50;
	}
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168,75,"DSTR");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218,75,"ECCF");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268,75,"AM 3");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318,75,"DIM");
	floodfill(51,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368,75,"DLDA");
	floodfill(51,51,YELLOW);
}

void insertend( head *t, int ele, char name[],int time){
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=ele;
	p->data2=time;
	strcpy(p->task,name);
	p->next=NULL;
	if(t->start==NULL){
		t->start=p;
		return;
	}
	q=t->start;
	while(q->next!=NULL)
		q=q->next;
	q->next=p;
}

void deletebeg( head *t){
	node *p;
	if(t->start==NULL){
		printf("LL Empty\n");
	}
	p=t->start;
	t->start=t->start->next;
	printf("Completed Task: %s \n",p->task);
}

void deleteele( head *t, char ele[]){
	node *p,*q;
	if(strcmp(t->start->task,ele)==0){
		p=t->start;
	t->start=t->start->next;
	}
	else{
		q=t->start;
		while(q->next!=NULL){
			if(strcmp(q->next->task,ele)==0)
				break;
			q=q->next;
		}
		if(q==NULL)
			printf("Task Does Not Exist!!\n");
		else{
			p=q->next;
			q->next=p->next;
		}
	}
}


void sortll(head *t){
	node *i,*j;
	int t1,t2,str[20];
	for(i=t->start;i->next!=NULL;i=i->next){
		for(j=t->start;j->next!=NULL;j=j->next){
			if((j->data)>(j->next->data)){
				t1=j->data;
				t2=j->data2;
				strcpy(str,j->task);
				j->data=j->next->data;
				j->data2=j->next->data2;
				strcpy(j->task,j->next->task);
				j->next->data=t1;
				j->next->data2=t2;
				strcpy(j->next->task,str);
			}
		}
	}
	for(i=t->start;i->next!=NULL;i=i->next){
		for(j=t->start;j->next!=NULL;j=j->next){
			if((j->next->data==j->data)&&(j->next->data2 > j->data2)){
				t1=j->data;
				t2=j->data2;
				strcpy(str,j->task);
				j->data=j->next->data;
				j->data2=j->next->data2;
				strcpy(j->task,j->next->task);
				j->next->data=t1;
				j->next->data2=t2;
				strcpy(j->next->task,str);
			}
		}
	}
}

void reverse(head *t){
	node *p=t->start,*q=NULL,*r;
	while(p!=NULL){
		r=p->next;
		p->next=q;
		q=p;
		p=r;
	}
	t->start=q;
}

void split(head *t1, head *t2, int aft){
	node *q=t1->start;
	while(q->data!=aft)
		q=q->next;
	t2->start=q->next;
	q->next=NULL;
}

void merge(head *t1, head *t2){
	node *q=t1->start;
	while(q->next!=NULL)
		q=q->next;
	q->next=t2->start;
	t2->start=NULL;
}

void display(head *t){
	int i=1;
	node *q;
	if(t->start==NULL){
		printf("LL Empty\n");
		return;
	}
	printf("\nStart of Task List\n");
	q=t->start;
	while(q!=NULL){
		printf("%d) %s to be submitted on %d (MMDD) will take %dhours\n",i++,q->task,q->data,q->data2);
		q=q->next;
	}
	printf("End of Task List\n\n");
}

int clr_ip_buf(){
	int ch;
	while (((ch = getchar()) != EOF) && (ch != '\n'));
		return ch;
}

void displaytable2(){
	int gdriver = DETECT, gmode, errorcode;
	int left, top, right, bottom;
	int x,y,i,j=0,k=50;
	initgraph(&gdriver, &gmode, "../bgi");
	left = 250;
	top = 50;
	right = 300;
	bottom = 100;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(left,top,right+60,bottom);
	floodfill(251,51,YELLOW);
	for(i=0;i<3;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left,top+k,right+60,bottom+k);
		floodfill(251,51,YELLOW);
		k=k+50;
	}
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top+50,right+50+60+j,bottom+50);
		floodfill(111+50+200,101,YELLOW);
		j=j+50;
	}
	j=0;
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168+200,125,"ECCF");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218+200,125,"DLDA");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268+200,125,"DSTR");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318+200,125,"DIM");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368+200,125,"AM 3");
	floodfill(251,51,YELLOW);
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
 		rectangle(left+110+j,top+100,right+50+60+j,bottom+100);
		floodfill(111+50+200,101,YELLOW);
		j=j+50;
	}
	j=0;
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168+200,175,"AM 3");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218+200,175,"DIM");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268+200,175,"ECCF");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);	
	outtextxy(318+200,175,"DSTR");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368+200,175,"DLDA");
	floodfill(251,51,YELLOW);
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top+150,right+50+60+j,bottom+150);
		floodfill(111+50+200,101,YELLOW);
		j=j+50;
	}
	j=0;
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168+200,225,"ECCF");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218+200,225,"DSTR");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268+200,225,"DIM");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318+200,225,"DLDA");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368+200,225,"AM 3");
	floodfill(251,51,YELLOW);

	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65+200,75,"9.00-11.00");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65+200,125,"11.15-1.15");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65+200,175,"1.45-3.45");
	floodfill(251,51,YELLOW);

	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(65+200,225,"3.45-5.45");
	floodfill(251,51,YELLOW);
	for(i=0;i<5;i++){
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(left+110+j,top,right+50+60+j,bottom);
		floodfill(51+50+200,51,YELLOW);
		j=j+50;
	}
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(168+200,75,"DSTR");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(218+200,75,"ECCF");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(268+200,75,"AM 3");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(318+200,75,"DIM");
	floodfill(251,51,YELLOW);
	setfillstyle(SOLID_FILL,BLACK);
	outtextxy(368+200,75,"DLDA");
	floodfill(251,51,YELLOW);
}