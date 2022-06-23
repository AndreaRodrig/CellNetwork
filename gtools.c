#include <stdio.h>
#include <stdlib.h>
#include "gtools.h"

int *createVector(int dim)
{
int *pf;
	if((pf=(int *)malloc(dim*sizeof(int)))==NULL)
	{printf("Error allocating memory \n");
	exit(1);
	}

return pf;
}

int **createVectorList(int n, int m)
{
int **array;
int i;
if((array=(int **)malloc(n*sizeof(int*)))==NULL)
	{printf("Error allocating memory \n");
	exit(1);
	}
	for(i=0;i<n;i++)
	array[i]=createVector(m);
	return array;
}

int *loadMut(void)
{
int i,l;
int *mut;
FILE *input;

//load graph
if((input=fopen("trail.dat","r"))==NULL)
	{
	printf("Cannot open file trail.dat file\n");
	exit(1);
	}

fscanf(input,"%d",&l);
mut=createVector(l);
for(i=0;i<l;i++)
fscanf(input,"%d ",&mut[i]);

return mut;
}

void exportGraph(int g, int *mut)
{
char fileName[28];
int i,j,l,n,m;
int **initialGraph,**mutList;
FILE *input;

if((input=fopen("graph.dat","r"))==NULL)
	{
	printf("Cannot open file graph.dat.\n");
	exit(1);
	}

fscanf(input,"%d %*d %*d",&n);
initialGraph=createVectorList(n,2);
for(i=0;i<n;i++)
fscanf(input,"%d %d %*d",&initialGraph[i][0],&initialGraph[i][1]);
fclose(input);

if((input=fopen("mutations.dat","r"))==NULL)
	{
	printf("Cannot open file mutations.dat.\n");
	exit(1);
	}

fscanf(input,"%d",&m);
mutList=createVectorList(m,2);
for(i=0;i<m;i++)
fscanf(input,"%d %d %*d",&mutList[i][0],&mutList[i][1]);
fclose(input);

sprintf(fileName,"graph_g%d.edgelist",g);
if((input=fopen(fileName,"w"))==NULL)
	{
	printf("Cannot open file %s\n",fileName);
	exit(1);
	}

for(i=0;i<n;i++)
fprintf(input,"%d %d\n",initialGraph[i][0],initialGraph[i][1]);

for(i=0;i<g;i++)
fprintf(input,"%d %d\n",mutList[mut[i]][0],mutList[mut[i]][1]);

}
