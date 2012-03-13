void interp(float ***uf, float ***uc, int nf)
/*
  Coarse-to-fine prolongation by bilinear interpolation. nf is the fine-grid dimension. The coarsegrid
  solution is input as uc[1..nc][1..nc], where nc = nf/2 + 1. The fine-grid solution is
  returned in uf[1..nf][1..nf].
*/
{
  int ic,iif,jc,jf,kc,kf,nc;
  nc=nf/2+1;

  //float a0,a1,a2,a3,mu,mu2; //temp vars for cubic interpolation

  /* Do elements that are copies.*/
  for(kc=1,kf=1;kc<=nc;kc++,kf+=2)
    for (jc=1,jf=1;jc<=nc;jc++,jf+=2) 
      for (ic=1;ic<=nc;ic++) 
	uf[2*ic-1][jf][kf]=uc[ic][jc][kc];

  //trilinear
  for(kf=2;kf<=nf;kf+=2)
    for (jf=2;jf<=nf;jf+=2) 
      for (iif=2;iif<nf;iif+=2) 
	uf[iif][jf][kf]=0.125*(uf[iif+1][jf+1][kf+1]+uf[iif-1][jf+1][kf+1]+uf[iif-1][jf-1][kf+1]+uf[iif-1][jf-1][kf-1]+uf[iif+1][jf-1][kf-1]+uf[iif+1][jf-1][kf+1]+uf[iif+1][jf+1][kf-1]+uf[iif-1][jf+1][kf+1]);

  //cubic interpolation
  /*
  for(kf=2;kf<=nf;kf+=2)
    for(jf=2;jf<=nf;jf+=2)
      for(iif=2;iif<nf;iif+=2)
  */


}
