#include <stdio.h>
#include <stdlib.h>
#include <math.h> 	
#include <string.h>
#include "stools.h"

#define N 1000	//# de nodos
#define MUT 2000 //# de mutaciones


int **loadMut_asym(int g, int index, int M)
{
char fileName[28];
int i,j;
int **mut;
FILE *input;

mut=createVectorList(g+M,3);

sprintf(fileName,"mut_g%d.dat",index);
if((input=fopen(fileName,"r"))==NULL)
	{
	printf("Cannot open file %s\n",fileName);
	exit(1);
	}

for(j=0;j<g+M;j++)
	for(i=0;i<3;i++)
	if(fscanf(input,"%d",&mut[j][i]) !=1)
	printf("Error in mut file.\n");

return mut;
}


void main(int argc, char *argv[])
{
char fileName[28];
int i,j,n,s,a,g,index,c,mode;
int **mut;
double v,h,e,tol,t,limit;
double *x,*xo,*f,*xd;
v=0;	// V/Vo
h=1;	//Step
e=0;	//Error
tol=pow(10,-5);	//Tolerance
s=9;	//Simpson integral points
t=0;	//Tiempo
a=0;
c=0;
x=createVector(N);
xo=createVector(N);
f=createVector(s);

sscanf(argv[1],"%d",&g);
sscanf(argv[2],"%d",&index);
sscanf(argv[3],"%d",&i);
sscanf(argv[4],"%lf",&limit);
sscanf(argv[5],"%d",&mode);

sprintf(fileName,"x0_%d.dat",index);
loadVector(N,x,fileName);

mut=loadMut_asym(g,index,MUT);

while(v<99999&&c<99999&&t<limit)
	{
	memcpy(xo,x,N*sizeof(double));	
	v+=addVol(f,x,s,h,g,i,mut);
	t+=(s-1)*h;
	c++;
	printf("%lf\n",sumR(x,g,i,mut));
	//ris(x,g,i,mut);
	}


char format[] = "x0_moretime_xm04_g%d.dat";
char filename[25];
sprintf(filename,format,g);

FILE *fp;

fp=fopen(filename,"w");

for(int k=0;k<N;k++) 
	{
	fprintf(fp,"%0.15lf\n",x[k]);
	}

fclose(fp);


if(t>=limit){
	printf("9999.99 0\n");
	exit(1);}
if(c==399){
	printf("9999.98 0\n");
	exit(1);}

v-=simpsonInt(f,s,h);
t-=(s-1)*h;
e=log(2)-v;

c=0;

while(e>tol&&s>3&&c<199)
	{
		s=(s-1)/2+1;	//Half of the interval
		v+=simpsonInt(f,s,h);
		if(v>log(2))
			v-=simpsonInt(f,s,h);
		else
			{
			for(j=0;j<s;j++)
			f[j]=f[j+(s-1)];
			t+=(s-1)*h;
			a+=(s-1);
			e=log(2)-v;
			}	
	c++;		
	}

if(t>limit){
	printf("9999.97 0\n");
	exit(1);}
if(c==199){
	printf("9999.96 0\n");
	exit(1);}

c=0;

memcpy(x,xo,N*sizeof(double));	
for(j=0;j<a;j++)
rk4(sumR(x,g,i,mut),x,h,g,i,mut);

while(e>tol&&c<199)
	{
	h=h/2;
	for(j=1;j<3;j++)
		{
		rk4(f[j-1],x,h,g,i,mut);
		f[j]=sumR(x,g,i,mut);
		}
	v+=simpsonInt(f,s,h);
	if(v<log(2))
		{
		f[0]=f[2];
		t+=(s-1)*h;
		e=log(2)-v;
		}
	else
		v-=simpsonInt(f,s,h);
	c++;
	}

if(t>limit){
printf("9999.95 0\n");
exit(1);}
if(c==199){
	printf("9999.94 0\n");
	exit(1);}

if(mode==0) //0:Normal 1:Export
	printf("%lf %lf\n",t,e);
else if(mode==1)
	exportVector(x,fileName);
else
	printf("ERROR: Mode %d not defined",mode);
}
