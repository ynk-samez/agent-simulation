#include"agent.h"



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
	int cnts=0;
	double cnt_res=0;
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
	printf("\n全体リソース量:%f\n",cnt_res);
	return cnts;
}


int set_strat(agent* computer,int p){		
int cnt_dash=0;
for (int n= 0; n < N; n++){
	computer[n].resource=1;
	int temp=rand()%100;
if(computer[n].status==true)computer[n].resource=0.5;

if(temp < p){
	computer[n].strat=true;
	cnt_dash++;
}else{ 
	computer[n].strat=false;
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

double mesure_res(agent* computer){
	double res=0.0;
	for (int n= 0; n < N; n++)
		res+=computer[n].resource;
	return res;
}

void set_pos(agent* computer,field size){
	for (int y= 0; y <size.height; y++)
		for (int x= 0; x <size.width ;x++){	
			computer[y*10+x].posx=x;
			computer[y*10+x].posy=y;
		}
}

void resource_calc(agent computer){
		if(computer.status==true)computer.resource==(double)1.0;
		else computer.resource-=0.25;
}