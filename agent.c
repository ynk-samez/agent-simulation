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
	computer[n].resource-=0.5;
	switch(tag_pos){
			case 1:/*tag->right*/
				if(computer[n+1].posx!=size.width){//相手が右端でない
				computer[n+1].status=computer[n].status;
				resource_calc(computer[n+1]);
				}else{	
				computer[n-size.width].status=computer[n].status;
				resource_calc(computer[n-size.width]);
				}
			break;
			case 2:/*tag->left*/
				if(computer[n-1].posx!=0){
				computer[n-1].status=computer[n].status;	
				resource_calc(computer[n-1]);
				}else{
				computer[n+size.width].status=computer[n].status;
				resource_calc(computer[n+size.width]);
			}
			break;
			case 3:/*tag->up*/
				if(computer[n].posy>=0){
				computer[n-size.height].status=computer[n].status;	
				resource_calc(computer[n-size.height]);
				}else{	
				computer[n+size.width*size.height-size.width].status=computer[n].status;
				resource_calc(computer[n+size.width*size.height-size.width]);
			}
			break;
			case 4:/*tag->down*/
				if(computer[n].posy+size.height<size.width*size.height){
				computer[n+size.height].status=computer[n].status;
				resource_calc(computer[n+size.height]);		
				}else{
				computer[n-size.width*size.height-size.height].status=computer[n].status;
				resource_calc(computer[n-size.width*size.height-size.height]);
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



