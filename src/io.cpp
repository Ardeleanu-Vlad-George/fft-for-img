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
}

void write(const char *addon, char *name, int L, double *norm_dft){
  sf::Image to_save;
  to_save.create(L,L);
  sf::Uint8 *data = (sf::Uint8*)to_save.getPixelsPtr();
  int iter;
  for(iter=0; iter<L*L; iter++){
    data[4*iter]    = norm_dft[6*iter];
    data[4*iter+1]  = norm_dft[6*iter+2];
    data[4*iter+2]  = norm_dft[6*iter+4];
    data[4*iter+3]  = '\xff';
  }

  char destination[251];
  sprintf(destination, "data/out/%d/%s%s", L, addon, name);
  to_save.saveToFile(destination);
}
