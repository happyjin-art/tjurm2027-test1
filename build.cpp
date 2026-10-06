#include<iostream>
#include<string>
#include<cmath>
using namespace std;
 void hist_eq(float *in, int h, int w) {
  long long N = h*w;
  int arr[300] = {0};
  for(int i = 0;i<N;i++)  {
    int a = round(in[i]);
    if(a > 255) a = 255;
    arr[a]++;
  }
  int cdf[300] = {0};
  cdf[0] = arr[0];
   for(int i = 1;i<=255;i++){
    cdf[i] = arr[i] + cdf[i-1];
    }
   
   int cdf_min = 0;
  for(int i = 0;i<=255;i++){
    if(cdf[i] != 0)  {
      cdf_min = cdf[i];
      break;
    }
  }

    for(int i = 0;i<N;i++){
      int r = round(in[i]);
      if(r >255) r = 255;
      int s = round( (float)(cdf[r] - cdf_min) / (N - cdf_min) * 255 );
      if(s<0)  s=0;
      else if(s>255)  s=255;
      in[i] = s;
    
  }
  

 }