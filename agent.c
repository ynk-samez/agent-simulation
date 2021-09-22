#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"agent.h"


int main(int argc, const char **argv){
	int p= atoi(argv[1]);
	FILE *fp;
	FILE *rp;
	auto int  n,s;
	auto int  tag_pos,num_err,num_str;
	auto char *res_file="resource.txt";
	auto char *agent_file="agent.txt";

	agent computer[N];
	field size;

	size.width=WIDTH;
	size.height=HEIGHT;


printf("\n-start:Initialize\n");
srand((unsigned int) time(NULL));

num_err=set_error(computer);
num_str=set_strat(computer,p);
set_pos(computer,size);


puts("-complite");

show_strat(computer);
printf("-the number of abnormal-status agents:%d/%d\n",num_err,N);
printf("-the number of repair-strategy agents:%d/%d\n",num_str,N);	


getchar();


rp=fopen(res_file,"w+");
fp=fopen(agent_file,"w+");

for (s= 0; s < S_MAX; s++){
system("cls");
for (n= 0; n < N; n++){
set_strat(computer,p);
tag_pos=rand()%4+1;
if(computer[n].strat==1){
	computer[n].resource=computer[n].resource-0.1;
	switch(tag_pos){
			case 1:/*tag->up*/
				if(n-10<0){
				computer[n+90].status=computer[n].status;
			if(computer[n+90].status==0)
				computer[n+90].resource=1;				
				}else{	
				computer[n-10].status=computer[n].status;
			if(computer[n-10].status==0)
				computer[n-10].resource=1;
				}
			break;
			case 2:/*tag->down*/
				if(n+10>90){
				computer[n-90].status=computer[n].status;	
			if(computer[n-90].status==0)
				computer[n-90].resource=1;
				}else{
				computer[n+10].status=computer[n].status;
			if(computer[n+10].status==0)
				computer[n+10].resource=1;
			}
			break;
			case 3:/*tag->left*/
				if(n-1<computer[n].posy*10){
				computer[n+9].status=computer[n].status;	
			if(computer[n+9].status==0)
					computer[n+9].resource=1;	
				}else{	
				computer[n-1].status=computer[n].status;
			if(computer[n-1].status==0)
					computer[n-1].resource=1;
			}
			break;
			case 4:/*tag->right*/
				if(n+1>computer[n].posy*10){
				computer[computer[n].posy*10].status=computer[n].status;		
			if(computer[n].status==0)
					computer[n].resource=1;	
				}else{
				computer[n+1].status=computer[n].status;
			if(computer[n+1].status==0)
					computer[n+1].resource=1;
			}	
			break;	
			default:
			break;
		}
	}
}


printf("\n\n-now step:%d/%d\n\n",s,S_MAX);
fprintf(fp, "%d\t%d\n",s,show_status(computer));
fprintf(rp, "%d\t%f\n",s,mesure_res(computer));
}


fclose(fp);
fclose(rp);
printf("\n戦略終了\n");

	return 0;
}



