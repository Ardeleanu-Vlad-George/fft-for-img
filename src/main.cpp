#include <cstdio>
#include <cstdlib>
#include "io.h"
#include "defs.h"
#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"
#include "fft_post_comp.h"


int main(int argc, char* argv[]){
  double *data;
  double log_const[3];
  double *ruts;
  int size, powr;
  char *name; //this one will point to the name of the file
  data = read(argv[1], &size, &name);
  ruts = every_rou(size);
  powr = getexp(size);
  fft_order(size, powr, data);
  fft_apply(size, powr, data, ruts);
  modulus_in_real(data, size);
  set_max_vals(data, size, log_const);
  const_from_max(TARGET_VALUE, log_const);
  nyquist_arrange(data, size);
  log_norm_real(data, size, log_const);

  write("FFT_of_", name, size, data);

  free(ruts);
  free(data);
  return 0;
}
