# Purpose
Implement a FFT algorithm that actually processes images. All images are expected to be square with their sizes powers of two so that the 
 algorithm may be applied properly. The 'data' folder stores all images, an image is selected based on it's name that was given through the 
 command line. No checks are done to see that the names are correct, that the dimensions are respected, all of this are just assumed by the 
 program and assured by the developer.
Inside the 'data' folder, images are divided by whether they are for input or output, and then further divided by their sizes.
Project is using ISO 1998 version of the C++ language.

The mistake that prevented the previous version from working was inside the call of 'comp_seqn' of the function 'fft_apply_rgb'. The step length
 for the two data sequences were not updated after shifting to elements that were 6 'doubles' wide (3 complex numbers, one for each color)
After multiplying the lengths with 3, the issue was resolved.
Below there is a link to a similar online program that you can use to check your work:
https://bigwww.epfl.ch/demo/ip/demos/FFT/
