#include "io.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>

double* read(char *src, int *L, char **name){
  double *data;
  int src_lenf = strlen(src), iter;
  for(iter=src_lenf-1; src[iter]!='/'; iter--);
  *name=src+iter+1;

  return NULL;
  // FILE *in;
  // int it;
  // in = fopen(src, "r");
  // fscanf(in, "%d", L);
  // data = (double**) calloc(*L, sizeof(double*));
  // *data = (double*) calloc(*L**L, 2*sizeof(double));
  // for(it=0; it < *L**L; it++){
  //   fscanf(in, "%lf", *data+2*it);
  //   data[0][2*it+1]=0;
  // }
  // fclose(in);
  // for(it=1; it < *L; it++)
  //   data[it]=data[it-1]+*L*2*sizeof(double);
  // return data;
}

void write(const char *addon, char *name, int L, double *dft){
  // FILE* out;
  // int it;
  // out = fopen(dst, "w");
  // fprintf(out, "%d\n", L);
  // for(it=0; it < 2*L*L; it+=2)
  //   fprintf(out, "(%6.2lf, %6.2lf)%c", it[*dft], (it+1)[*dft], it/2%L==L-1 ? '\n' : ' ');
  // fclose(out);
}
