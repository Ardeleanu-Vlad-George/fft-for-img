#include "io.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>

double* read(char *path, int *L, char **name){
  double *data;
  int path_lenf = strlen(path), iter;
  sf::Image source;
  for(iter=path_lenf-1; path[iter]!='/'; iter--);
  *name=path+iter+1;
  iter--;
  for(;path[iter]!='/'; iter--);
  *L=atoi(path+iter+1);
  data = (double*) calloc(*L**L, 6*sizeof(double));
  source.loadFromFile(path);
  const sf::Uint8 *img_data = source.getPixelsPtr();
  for(iter=0; iter<*L**L; iter++){
    //RED
    data[6*iter]    = img_data[4*iter];
    data[6*iter+1]  = 0.;
    //GREEN
    data[6*iter+2]  = img_data[4*iter+1];
    data[6*iter+3]  = 0.;
    //BLUE
    data[6*iter+4]  = img_data[4*iter+2];
    data[6*iter+5]  = 0.;
  }

  return data;
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
