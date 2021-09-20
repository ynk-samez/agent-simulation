#include"agent.h"
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