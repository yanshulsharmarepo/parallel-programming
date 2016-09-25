#include<omp.h>
#include<stdio.h>
//author yanshul sharma(iiit guwahati)
int main()
{
	int a[100];
        int i=0;
             a[0]=2;
         for(i=1;i<100; i++)
            {
              a[i]=(a[i-1]*2)-3;
                           }
int sum1=0,sum2=0;
clock_t start, end;
double cpu_time_used;

start = clock();
… /* Do the work. */
#pragma omp parallel num_threads(2)
{
	int id = omp_get_thread_num();
                 if(id==0){
		for (i=0;i<100;i=i+2)
		{
			sum1=sum1+a[i];
		}}
               else
                 {
                  for (i=1;i<100;i=i+2)
		{
			sum1=sum1+a[i];
		}
                       }
		
}
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n%lf time used \n",cpu_time_used);
printf("sum = %d\n",sum1+sum2);
}
