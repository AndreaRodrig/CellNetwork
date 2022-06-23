#include <stdio.h>
#include <stdlib.h>
#include "gtools.h"

void main(int arc, char *argv[])
{
int i,g,r,s;
int *mut;
sscanf(argv[1],"%d",&r);	//Range
sscanf(argv[2],"%d",&s);	//Step
g=0;

mut=loadMut();
for(i=1010;g<r;i++)
	{
	g=i*s;	
	exportGraph(g,mut);
	}
}
