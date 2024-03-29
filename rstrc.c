void rstrct(float ***uc, float ***uf, int nc)
/* 
   Half-weighting restriction. nc is the coarse-grid dimension. The fine-grid solution is input in
   uf[1..2*nc-1][1..2*nc-1], the coarse-grid solution is returned in uc[1..nc][1..nc].
*/
{
  int ic,iif,jc,jf,kc, kf, ncc=2*nc-1;
  /* Interior points.*/
  for(kf=3,kc=2;kc<nc;kc++,kf+=2)
    {
      for (jf=3,jc=2;jc<nc;jc++,jf+=2) 
	{ 
	for (iif=3,ic=2;ic<nc;ic++,iif+=2) 
	  {
	    uc[ic][jc][kc]=0.5*uf[iif][jf][kf]+0.5/6*(uf[iif+1][jf][kf]+uf[iif-1][jf][kf]+uf[iif][jf+1][kf]+uf[iif][jf-1][kf]+uf[iif][jf][kf+1]+uf[iif][jf][kf-1]);
	  }
	}
    }

  /* Boundary points. */
  for (kc=1,jc=1,ic=1;ic<=nc;ic++,jc+=2,kc+=2) { 
    uc[ic][1][kc]=uf[jc][1][kc];
    uc[ic][nc][kc]=uf[jc][ncc][kc];
  }
  for (kc=1,jc=1,ic=1;ic<=nc;ic++,jc+=2,kc+=2) {
    uc[1][ic][kc]=uf[1][jc][kc];
    uc[nc][ic][kc]=uf[ncc][jc][kc];
  }
  for(kc=1,jc=1,ic=1;ic<=nc;ic++,jc+=2,kc+=2) {
    uc[ic][ic][1]=uf[jc][jc][1];
    uc[ic][ic][nc]=uf[jc][jc][ncc];
  }
}
