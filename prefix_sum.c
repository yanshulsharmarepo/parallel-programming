#include<omp.h>
#include<stdio.h>
#include <math.h>
#include<time.h>
//author yanshul sharma(iiit guwahati)
int main()
{
	int a[8];
        int c[8];
        int i=0,j=0,h=0;;
            // a[0][0]=2;
         for(i=0;i<8; i++)
            {
              a[i]=1;
              c[i]=0;
            }
         int k=ceil(log(8));
             k=k+1;
        int b[k][8];
    for(i=0; i<k; i++)
      {
     for(j=0; j<8; j++)
         {   
            b[i][j]=0;
             }
       }

      for(i=0; i<8; i++)
           {
            b[0][i]=a[i];
              }

           //up sweapclock_t start, end;
double cpu_time_used;

start = clock();
… /* Do the work. */

       #pragma omp parallel num_threads(2)
      {
          int id = omp_get_thread_num();
        for(h=id; h<=k; h=h+2)
          {
                 for(j=pow(2,h);j<=8;j=j+pow(2,h))
                   {
                    b[h][j-1]=b[h-1][(j/2)-1]+b[h-1][j-(int)pow(2,h-1)-1];
                   } 
                 
           }
        }
       /*  for(h=0; h<=3; h++)
          {
                 for(j=0;j<8;j++)
                   {
                    printf("%d ",b[h][j]);
                   } 
                 printf("\n");
           }        
       */

        int l=0;
        //down sweap
        #pragma omp parallel num_threads(2)
      { 
           int id = omp_get_thread_num();
       for(h=k-1-id; h>=0; h=h-2)
          {
             for(k=pow(2,h); k<8; k=l+pow(2,h))
              {
               for(l=k; l<(k+pow(2,h)); l++)
                 {
                    c[l]=b[h][k-1]+c[l];
                 }
              }
          }
        }
		end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n%lf time used \n",cpu_time_used);
        for(l=0; l<8; l++)
                 {
                            c[l]=c[l]+a[l];
                    printf("%d ",c[l]);
                 }

}
