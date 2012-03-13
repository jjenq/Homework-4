void relax(float ***u, float ***u_old, float ***rhs, int n)
/*
  Red-black Gauss-Seidel relaxation for model problem. Updates the current value of the solution
  u[1..n][1..n], using the right-hand side function rhs[1..n][1..n].
*/
{

  int i,ipass,isw,j,jsw=1,k,ksw;
  float h,h2;
  h=1.0/(n-1);
  h2=h*h;
  /* Red and black sweeps.*/
  /* jsw and isw toggle between 1 and 2 and
     determine starting row in each column
     for given pass 
  */

  for (ipass=1;ipass<=2;ipass++,jsw=3-jsw) { 
    isw=jsw;
    ksw=jsw;
    for (j=2;j<n;j++,isw=3-isw)
      for(k=3;k<n;k++,ksw=3-ksw)
    	for (i=isw+1;i<n;i+=2) 
	  u[i][j][k]=1/6*(u[i+1][j][k]+u[i-1][j][k]+u[i][j+1][k]+u[i][j-1][k]+u[i][j][k-1]+u[i][j][k+1]-h2*rhs[i][j][k]);
  }

  /*
  //regular Gauss Seidel
  for(i=2;i<n;i++)
    {
      for(j=2;j<n;j++)
	{
	  for(k=2;k<n;k++)
	    {
	      u[i][j][k]=1/6*(u[i+1][j][k]+u[i-1][j][k]+u[i][j+1][k]+u[i][j-1][k]+u[i][j][k+1]+u[i][j][k-1]-h2*rhs[i][j][k]);
	    }
	}
    }
  */
  /*
  //Jacobi
  //same as regular Gauss Seidel except uses u_old
for(i=2;i<n;i++)
  {
    for(j=2;j<n;j++)
      {
	for(k=2;k<n;k++)
	  {
              u[i][j][k]=1/6*(u_old[i+1][j][k]+u_old[i-1][j][k]+u_old[i][j+1][k]+u_old[i][j-1][k]+u_old[i][j][k+1]+u_old[i][j][k-1]-h2*rhs[i][j][k]);
	  }
      }
  }
  */
}
