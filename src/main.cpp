#include <cstdio>
#include <cstdlib>
#include "io.h"
#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"


int main(int argc, char* argv[]){
  double *data;
  double *ruts;
  int size, powr;
  char *name; //this one will point to the name of the file
  data = read(argv[1], &size, &name);
  // ruts = every_rou(size);
  // powr = getexp(size);
  // fft_order(size, powr, data);
  // fft_apply(size, powr, data, ruts);
  write("FFT_of_", name, size, data);
  //
  // free(ruts);
  // free(data);
  return 0;
}
