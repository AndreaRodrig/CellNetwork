#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main (int arcgc, char *argv[])
{
	int outn, inn, edge, species, i;
	double x;
	FILE *nedges;
	FILE *X;

	X = fopen(argv[1], "r");
	nedges = fopen(argv[2], "r");
	sscanf(argv[3], "%d", &species);
	
	for (i=0; i<species; i++)
	//while(!feof(X))
	{	
		fscanf(X, "%lf", &x);	
		
		if (x<4e-05)	
			printf("%d\n", i); //list of nodes
			
			
		/*if (x<4e-05)
		{
			//printf("If %d \n",i);
			
			do
			{
				fscanf(nedges, "%d %d %d", &outn, &inn, &edge);
				//printf("While %d \n",i);
				//printf("Edge %d \n\n",edge);
				if(i==edge)
					printf("%d\n%d\n", outn, inn);
			}
			while(!feof(nedges));
			rewind(nedges); 	
		}	
		else 
		{
			//printf("Else %d \n",i);
			continue;
		}*/
	}
	fclose(nedges);
	fclose(X);	
}


