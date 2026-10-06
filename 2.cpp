
void resize(float *in, float *out, int h, int w, int c, float scale) {
    int new_h = h * scale, new_w = w * scale;
    for(int y=0;y<new_h;y++){
        for(int x = 0;x<new_w;x++){
            for(int k=0;k<c;k++){
            float  src_x = (float)x/scale;
            float src_y = (float)y/scale;
          int x1 = static_cast<int>(src_x);
          int y1 = static_cast<int>(src_y);
          int x0 = x1-1,y0 = y1 -1;
          if(x0<0) x0 = 0;
          if(y0<0) y0 = 0;
          if(x1>=w) x1 = w -1;
          if(y1>=h)  y1 = h -1;
           float p1 = in[(x0 + y0*w)*c + k];
           float p2 = in[(x1 + y0*w)*c + k];
           float p3 = in[(x0 + y1*w)*c + k];
           float p4 = in[(x1 + y1*w)*c + k];
           float dx = src_x - x0;
           float dy = src_y - y0;
           float Q = p1 * (1 - dx)*(1 - dy) + p2 * dx*(1 - dy)+ p3 * (1 - dx)*dy + p4 * dx*dy;
           out[(x + y*new_w)*c + k] = Q;
            }
        }
    }
}