#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h> 
#include<stdbool.h>

#define N 100 /*agent数*/
#define S_MAX 500
#define HEIGHT 10
#define WIDTH 10


typedef struct{
	int width;
	int height;
}field;

typedef struct {
	bool status;/*1:異常、0:正常*/
	bool strat;/*1:修復戦略、0:無視戦略*/
	double resource;
	int posx;
	int posy;
}agent;


void show_strat(agent*);
int show_status(agent*);
int set_error( agent*);
int set_strat(agent*,const int );
int mesure_res( agent* );


int main(int argc, const char **argv){
	int p= atoi(argv[1]);
	FILE *fp;
	FILE *rp;
	auto int  n,s,x,y;
	auto int  tag_pos,num_err,num_str;
	auto char *res_file="resource.txt";
	auto char *agent_file="agent.txt";

	agent computer[N];
	field size;

	size.width=WIDTH;
	size.height=HEIGHT;


/*乱数の初期化*/
printf("\n-start:Initialize\n");
srand((unsigned int) time(NULL));
/*--agent状態の定義--*/
/*agentの状態を確率的にerrorにする*/
num_err=set_error(computer);
/*戦略を与える*/
num_str=set_strat(computer,p);

 /*agentの位置を定義する*/
	for (y= 0; y <size.height; y++)
		for (x= 0; x <size.width ;x++){	
			computer[y*10+x].posx=x;
			computer[y*10+x].posy=y;
		}

	puts("-complite");

show_strat(computer);
printf("-the number of abnormal-status agents:%d/%d\n",num_err,N);
printf("-the number of repair-strategy agents:%d/%d\n",num_str,N);	
/*--ここまで--*/

getchar();


/*すべてのagentが戦略を実行*/
rp=fopen(res_file,"w+");
fp=fopen(agent_file,"w+");

for (s= 0; s < S_MAX; s++){
	system("cls");
for (n= 0; n < N; n++){
set_strat(computer,p);//戦略はステップの度に切り替わる
tag_pos=rand()%4+1;//相方を決める。
if(computer[n].strat==1){
	computer[n].resource=computer[n].resource-0.1;
	switch(tag_pos){
			case 1:/*tag->up*/
				if(n-10<0){
				computer[n+90].status=computer[n].status;
			if(computer[n+90].status==0)//修正されたコンピュータはリソースを回復する。
				computer[n+90].resource=1;				
				}else{	
				computer[n-10].status=computer[n].status;
			if(computer[n-10].status==0)//修正されたコンピュータはリソースを回復する。
				computer[n-10].resource=1;
				}
			//puts("upを修正");
			break;
			case 2:/*tag->down*/
				if(n+10>90){
				computer[n-90].status=computer[n].status;	
			if(computer[n-90].status==0)//修正されたコンピュータはリソースを回復する。
				computer[n-90].resource=1;
				}else{
				computer[n+10].status=computer[n].status;
			if(computer[n+10].status==0)//修正されたコンピュータはリソースを回復する。
				computer[n+10].resource=1;
			}
			//puts("downを修正");
			break;
			case 3:/*tag->left*/
				if(n-1<computer[n].posy*10){
				computer[n+9].status=computer[n].status;	
			if(computer[n+9].status==0)//修正されたコンピュータはリソースを回復する。
					computer[n+9].resource=1;	
				}else{	
				computer[n-1].status=computer[n].status;
			if(computer[n-1].status==0)//修正されたコンピュータはリソースを回復する。
					computer[n-1].resource=1;
			}
			//puts("leftを修正");
			break;
			case 4:/*tag->right*/
				if(n+1>computer[n].posy*10+x){
				computer[computer[n].posy*10].status=computer[n].status;		
			if(computer[n].status==0)//修正されたコンピュータはリソースを回復する。
					computer[n].resource=1;	
				}else{
				computer[n+1].status=computer[n].status;
			if(computer[n+1].status==0)//修正されたコンピュータはリソースを回復する。
					computer[n+1].resource=1;
			}
			//puts("rightを修正");		
			break;	
			default:
			break;
		}//swtch_end
	}//if end
}//for n end


//getchar();
printf("\n\n-now step:%d/%d\n\n",s,S_MAX);
fprintf(fp, "%d\t%d\n",s,show_status(computer));
fprintf(rp, "%d\t%d\n",s,mesure_res(computer));
}//for s end.


fclose(fp);
fclose(rp);
/*--戦略終了後--*/
printf("\n戦略終了\n");

	return 0;
}


void show_strat(agent* computer){
for (int i = 0; i < N; i++){
	if(i%10==0)
		printf("\n");
	else
	printf("agent[%02d]:%d\t",i,computer[i].strat);
}
printf("\n\n");
}


int show_status(agent* computer){
	int cnts,cnt_res;
for (int i = 0; i < N; i++){
	if(i%10==0)
		printf("\n");
	else
	printf("agent[%02d]:%d\t",i,computer[i].status);
	
	if(computer[i].status==1){
		cnts++;
	}
	cnt_res+=computer[i].resource;

}
	printf("\n異常エージェント発生数:%d\n",cnts);
	printf("\n全体リソース量:%d\n",cnt_res);
	return cnts;
}

int set_strat(agent* computer,int p){		
int cnt_dash=0;
for (int n= 0; n < N; n++){
	computer[n].resource=1;
	int temp=rand()%100;
if(computer[n].status==1)
	computer[n].resource=0.5;
	if(temp < p){
		computer[n].strat=1;
		cnt_dash++;
	}else{ 
		computer[n].strat=0;
	}
}
return cnt_dash;
}


int set_error(agent* computer){
	int cnt=0,s;
	for (int n= 0; n < N; n++){
	s=computer[n].status=rand()%2;
	if(s==1)
		cnt++;
}
return cnt;
}

int mesure_res(agent* computer){
	int res=0;
	for (int n= 0; n < N; n++)
		res+=computer[n].resource;
	return res;
}