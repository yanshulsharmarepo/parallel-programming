#include<omp.h>
#include<stdio.h>
#include<time.h>
//author yanshul sharma(iiit guwahati)
 
int main()
{
	int a[10];
        int i;
        for(i=0;i<10;i++)
              a[i]=0;
        a[2]=2;
        a[3]=2;
        a[8]=2;
        a[7]=3;
        a[6]=3;
        a[5]=8;
        a[4]=6;
        a[9]=4;
        a[1]=7;
        a[0]=4;
       int root=2;

     /*
                  /2\
               |       |
               3       8
           |      |       |
           7      6        5
           |      |       
           1      4        
                |   |
                9   0
             */
printf("\n");

for(i=0; i<10 ;i++)
{
      printf("%d ",i);
}
printf("\n");
for(i=0; i<10; i++)
{
      printf("%d ",a[i]);
}
int j,l;
int hight=4;
clock_t start, end;
double cpu_time_used;

start = clock();
… /* Do the work. */
for(i=0; i<hight; i++)
{
  #pragma omp parallel num_threads(2)
{
  int id = omp_get_thread_num();
  for(j=id; j<10; j=j+2){
   if(a[j]!=root)
   {
      a[j]=a[a[j]];
   }
  }
}
  printf("\n");
 for(l=0; l<10 ;l++)
{
      printf("%d ",l);
}
printf("\n");
for(l=0; l<10; l++)
{
      printf("%d ",a[l]);
}

}
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n%lf time used \n",cpu_time_used);
 printf("\n");
 for(i=0; i<10 ;i++)
{
      printf("%d ",i);
}
printf("\n");
for(i=0; i<10; i++)
{
      printf("%d ",a[i]);
}


}
