#include "mg.h"
#include "nrutil.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv){
  int i,j;
  FILE *outfile;
  float ***f;
  int n,counter;
  int ncycle=2;
  time_t start, end;
  for(counter=32;counter<1025;counter*=2)
    {
      n=counter+1;
  f = f3tensor(1,n,1,n,1,n);
  f[1][1][1]=1.0;

  time(&start);
  mglin(f,n,ncycle);
  time(&end);
  printf("%d: %f\n", n, difftime(end,start));
    }
  outfile = fopen("soln.dat", "w");
  fwrite(&f[1][1],sizeof(float),n*n,outfile);
  fclose(outfile);
}
