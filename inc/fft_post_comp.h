#ifndef _FFT_POST_COMP_H_
#define _FFT_POST_COMP_H_

/**
  *   \brief This file simulates the operations that would occur in image processing after the 
  *   FFT was computed
  *
*/

//Scale the data by the provided value
void scale(double *data, int lenf, double valu);

//Arrange the data so that the biggest member (in module) is
//in the middle, all of the members are circulary shifted 
//such that such an arrangement is achieved
//In practice, the two halves get swapped
void nyquist_arrange(double *data, int lenf);

//Save modulus to the real part, the imaginary one gets nullified in the process
//The mirror function is not needed
void modulus_in_real(double *data, int lenf); 

//Logarithmically normalize the real parts by the provided value 
//The mirror function is not needed
void log_norm_real(double *data, int lenf, double valu);

#endif//_FFT_POST_COMP_H_
