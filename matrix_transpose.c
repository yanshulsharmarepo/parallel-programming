#include<omp.h>
#include<stdio.h>
#include<time.h>
//author yanshul sharma(iiit guwahati)
int main()
{
	int a[10][10];
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
            }
//int sum1=0,sum2=0;;
printf("\n");
clock_t start, end;
double cpu_time_used;

start = clock();
… /* Do the work. */
#pragma omp parallel num_threads(2)
{
	int id = omp_get_thread_num();
                 if(id==0){
                  int temp=0;
		for (i=0;i<10;i=i+2)
		{
		   for(j=i;j<10;j++)
                     {
                      temp=a[i][j];
                      a[i][j]=a[j][i];
                      a[j][i]=temp;
                      }
		}
                         }
               else
                 {
                    int temp1=0;
		for (i=1;i<10;i=i+2)
		{
		   for(j=i;j<10;j++)
                     {
                      temp1=a[i][j];
                      a[i][j]=a[j][i];
                      a[j][i]=temp1;
                      }
		}
                       }
		
}
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n%lf time used ",cpu_time_used);
   for(i=0;i<10; i++)
            {
               for(j=0; j<10; j++) 
                   {
                    printf("%d ",a[i][j]);
                   }
              printf("\n");
            }

}
