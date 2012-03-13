Homework 4
1. For the multigrid solver, I used the f3tensor data type from nrutil, and I changed most references from ** to ***.

2. The performance results as a function of problem size vs SOR time in seconds are shown in SOR.png. I was unable to get SOR results for n>15. FMA problem size time in seconds is shown in FMA.png. For both of these, the problem size is on the x-axis and the run time in seconds is on the y-axis.

3. Gauss Seidel overwrites the components of u_old as soon as u_new is computed. Gauss Seidel is faster than Jacobi. Red Black ordering updates every other value in parallel, since red valued are updated using black values and vice versa. For my code, Gauss Seidel performed significantly better than red-black ordering, so the parallel relaxation seems ineffective for this problem.