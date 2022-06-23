# include <stdio.h>
# include <stdlib.h>

double *Ri(double *x, int N, int g, int m, int **mut);
double *createVector(int dim);
int *createIntVector(int dim);
int **createVectorList(int n, int m);
void loadVector(int dim,double *array,char *fileName);
int **loadMut(int g, int index, int M);
void exportVector(double *array, char *fileName);
double sumR(double *x,int gen, int m, int **mut);
double ris(double *x,int gen, int m, int **mut);
double *xdot(double sumR, double *x,int gen, int m, int **mut);
void rk4(double sumR, double *x, double h, int gen, int m, int **mut);
double simpsonInt(double *f, int s, double h);
double addVol(double *f,double *x,int s,double h, int g, int i, int **mut);
