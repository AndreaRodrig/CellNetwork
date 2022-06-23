//This program computes the percentage of chemical species that changed their concentration by more than 10^-6

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main (int arcgc, char *argv[])
{
	int i, g;
	double x2, x4, dif, c, species;
	c=0;
	FILE *Xm2;
	FILE *Xm4;

	Xm2 = fopen(argv[1], "r");
	Xm4 = fopen(argv[2], "r");
	
	
	for(i=0; i<species; i++)
	{
		sscanf(argv[3], "%d", &g);	
		sscanf(argv[4], "%lf", &species);	
		fscanf(Xm2, "%lf", &x2);
		fscanf(Xm4, "%lf", &x4);
		if (feof(Xm2))
			{
			printf("%d %lf \n", g, (c*100)/species);
			exit(0);
			}
		
		dif=x2-x4;
		
		if (dif<0)
			dif=-dif;
		
		if (dif>0.000001)
			c++;
	}
	printf("%d %lf \n", g, (c*100)/species);	
	
	fclose(Xm2);
	fclose(Xm4);

}
