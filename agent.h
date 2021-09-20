#pragma once

#define N 100 /*agent数*/
#define S_MAX 500
#define HEIGHT 10
#define WIDTH 10
#include<stdbool.h>


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