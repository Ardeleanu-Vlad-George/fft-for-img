#include "fft_comp.h"
#include "fft_prep_bit.h"
#include "fft_prep_cpx.h"
#include "cpx_op.h"
#include "btr_fly.h"

void fft_order_one(int type, int nr, int pwr, double *vct){
  //type: 0 means line, 1 means column
  int iter;
  double buff[2*nr];

  for(iter=0; iter < nr; iter++)
    asn(buff+2*iter, vct+6*iter*(type?nr:1));

  for(iter=0; iter < nr; iter++)
    asn(vct+6*iter*(type?nr:1), buff+2*revidx(iter, pwr));
}

void fft_order_rgb(int comp, int nr, int pwr, double *vct){
  int iter;

  // vct+=2*comp;

  for(iter=0; iter < nr; iter++)
    fft_order_one(0, nr, pwr, vct+6*iter*nr);

  for(iter=0; iter < nr; iter++)
    fft_order_one(1, nr, pwr, vct+6*iter);
}

void fft_order(int nr, int pwr, double *vct){
  fft_order_rgb(0, nr, pwr, vct);
  fft_order_rgb(1, nr, pwr, vct);
  fft_order_rgb(2, nr, pwr, vct);
}

void fft_apply_one(int type, int nr, int pwr, double *vct, double *rts){
  //0 - means line, 1 - means column
  double *seqn_pair, *vect_stop;
  vect_stop = vct+6*nr*(type?nr:1);
  int seqn_lenf, layer_cnt, powr_step; 

  for(
    layer_cnt=0, seqn_lenf=1, powr_step=nr/2;
    layer_cnt < pwr;
    layer_cnt++, seqn_lenf*=2, powr_step/=2
  )for(seqn_pair=vct; seqn_pair < vect_stop; seqn_pair+=12*seqn_lenf*(type?nr:1))
    comp_seqn(
      seqn_lenf,
      seqn_pair,                          type?nr:1,
      seqn_pair+6*seqn_lenf*(type?nr:1),  type?nr:1,
      rts,                                powr_step,
      rts+2*seqn_lenf*powr_step,          powr_step
    );
}

void fft_apply_rgb(int comp, int nr, int pwr, double *vct, double *rts){
  int iter;

  vct+=2*comp;

  for(iter=0; iter < nr; iter++)
    fft_apply_one(0, nr, pwr, vct+6*iter*nr, rts);

  for(iter=0; iter < nr; iter++)
    fft_apply_one(1, nr, pwr, vct+6*iter, rts);
}

void fft_apply(int nr, int pwr, double *vct, double *rts){
  fft_apply_rgb(0, nr, pwr, vct, rts);
  fft_apply_rgb(1, nr, pwr, vct, rts);
  fft_apply_rgb(2, nr, pwr, vct, rts);
}
