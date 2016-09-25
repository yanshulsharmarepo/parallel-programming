#include<omp.h>
#include<stdio.h>
//author yanshul sharma(iiit guwahati)
int main()
{
	int a[10][10];
        int b[10];
        int c[10];
        int i=0,j=0;
            // a[0][0]=2;
         for(i=0;i<10; i++)
            {
               for(j=0; j<10; j++) 
                   {
                    a[i][j]=i+1;
                  printf("%d ",a[i][j]);
                   }
                 printf("\n");
                   b[i]=i*2;
            }
      for(i=0; i<10; i++)
         {
           printf("%d ",b[i]);
         }
          printf("\n");

printf("\n");
clock_t start, end;
double cpu_time_used;

start = clock();
… /* Do the work. */
#pragma omp parallel num_threads(2)
{
	int id = omp_get_thread_num();
                 int l,m,sum=0;
		for(l=id;l<10;l=l+2)
                  {
                     sum=0;
                    #pragma omp #pragma omp parallel num_thread(2)
                    {
                         for(m=0;m<10;m++)
                        {
                          printf("%d ",omp_get_thread_num());
                         sum=a[l][m]*b[m]+sum;
                        }
                     }
                      c[l]=sum;
                   }
}
  end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n%lf time used \n",cpu_time_used);
for(i=0;i<10;i++)
{
 printf("%d ",c[i]);
}
}
