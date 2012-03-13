void resid(float ***res, float ***u, float ***rhs, int n)
/*
Returns minus the residual for the model problem. Input quantities are u[1..n][1..n] and
rhs[1..n][1..n], while res[1..n][1..n] is returned.
*/
{
  int i,j,k;
  float h,h2i;
  h=1.0/(n-1);
  h2i=1.0/(h*h);
  /* Interior points.*/
  for(k=2;k<n;k++)
    for (j=2;j<n;j++) 
      for (i=2;i<n;i++)
	res[i][j][k] = -h2i*(u[i+1][j][k]+u[i-1][j][k]+u[i][j+1][k]+u[i][j-1][k]+u[i][j][k-1]+u[i][j][k+1]-6.0*u[i][j][k])+rhs[i][j][k];
  /* Boundary points.*/
  for (i=1;i<=n;i++) 
    res[i][1][k]=res[i][n][k]=res[1][i][k]=res[n][i][k]=res[i][i][1]=res[i][i][n]=0.0;
}
