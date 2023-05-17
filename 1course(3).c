#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lodepng.h"

char* loadPng(const char* filename, int* width, int* height) {
  unsigned char* image = NULL;
  int error = lodepng_decode32_file(&image, width, height, filename);
  if(error){
    printf("error %u: %s\n", error, lodepng_error_text(error));
  }
  return (image);
}

void writePng(const char* filename, const unsigned char* image, unsigned width, unsigned height) {
  unsigned char* png;
  long unsigned int pngsize;

  int error = lodepng_encode32(&png, &pngsize, image, width, height);
  if(!error) {
    lodepng_save_file(png, pngsize, filename);
  }
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));
  free(png);
}

void relative_brightness_of_color(int w, int h,unsigned char *picture,unsigned char *picture1){
    for(int i=0;i<w*h;i++){
         picture1[i]=0.250*picture[4*i]+0.600*picture[4*i+1]+0.100*picture[4*i+2];
    }
    return;
}

void black_or_white(int w,int h,unsigned char *picture1){
    for(int i=2;i<h-1;i++){
        for(int j=2;j<w-1;j++){
            if(picture1[w*i+j]<75){
                picture1[w*i+j]=0;
            }
            if(picture1[w*i+j]>150){
                picture1[w*i+j]=255;
            }
        }
    }
    return;
}

void gauss_smoothing(int w,int h,unsigned char *picture1, unsigned char *picture2){
     for(int i=2;i<h-1;i++){
        for(int j=2;j<w-1;j++){
           picture2[w*i+j]=0.09*picture1[w*(i+1)+(j-1)]+0.12*picture1[w*(i+1)+j]+0.09*picture1[w*(i+1)+(j+1)]+0.12*picture1[w*i+(j-1)]+0.15*picture1[w*i+j]+0.12*picture1[w*i+(j+1)]+0.09*picture1[w*(i-1)+(j-1)]+0.12*picture1[w*(i-1)+j]+0.09*picture1[w*(i-1)+(j+1)];
        }
     }
   return;
}

void color_pattern(int w, int h,unsigned char *picture2,unsigned char *picture4){
    for(int i=0;i<w*h;i++) {
        picture4[i*4]=170+picture2[i];
        picture4[i*4+1]=205+2*picture2[i];
        picture4[i*4+2]=picture2[i];
        picture4[i*4+3]=200;
    }
    return;
}

int main() {
    char * filename = "skull.png";
    int w,h;
    char * picture = loadPng(filename, &w, &h);
    if (picture == NULL){
        printf("I can not read the picture from the file %s. Error.\n", filename);
        return -1;
    }
    unsigned char *picture1=(unsigned char*)malloc(h*w*sizeof(unsigned char));
    unsigned char *picture2=(unsigned char*)malloc(h*w*sizeof(unsigned char));
    unsigned char *picture4=(unsigned char*)malloc(h*w*4*sizeof(unsigned char));
    relative_brightness_of_color(w,h,picture,picture1);
    black_or_white(w,h,picture1);
    gauss_smoothing(w,h,picture1,picture2);
    color_pattern(w,h,picture2,picture4);
    char * new_image="skull-modified.png";
    writePng(new_image,picture4,w,h);
    return 0;
}
