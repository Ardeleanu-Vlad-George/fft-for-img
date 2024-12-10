#ifndef _FFT_POST_COMP_H_
#define _FFT_POST_COMP_H_

/**
  *   \brief This file implements the operations that occur in image processing after the 
  *   FFT was computed
  *   They are needed to reorder the FFT according to "industry standards" (nyquist_arrange)
  *   after which the image needs to be normalized in such a way that it can be saved to 
  *   digital image file.
*/

//Scale the data by the provided value
void scale(double *data, int size, double valu);

//Arrange the data so that the biggest member (in module) is
//in the middle, all of the members are circulary shifted 
//such that such an arrangement is achieved
//In practice, the two halves get swapped
void nyquist_arrange(double *data, int size);

//Works properly only after the "nyquist_arrange" function was called
//on the input 'data'
void set_max_vals(double *data, int size, double *vals);

//Compute the constants from the given max values, the max values
//extracted by the previous function
void const_from_max(double target, double *vals);

//Save modulus to the real part, the imaginary one gets nullified in the process
//The mirror function is not needed
void modulus_in_real(double *data, int size); 

//Logarithmically normalize the real parts by the provided value 
//The mirror function is not needed
void log_norm_real(double *data, int size, double *vals);

#endif//_FFT_POST_COMP_H_
