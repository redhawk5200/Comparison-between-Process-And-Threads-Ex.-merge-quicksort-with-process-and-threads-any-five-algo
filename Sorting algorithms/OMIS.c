#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
int main()
{	
    for(int i=0;i<10;i++){
    int n;
    clock_t begin, end;
    double total_t;
    begin = clock();
        /*printf("Enter no of elements you want in your array: ");
    scanf("%d\n",&n);
    int arr[n];*/
    FILE * fp;
    fp = fopen("1-10000.txt","r");
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int key, j,i;
    for ( i=0;i<n;i++)
    {
	fscanf(fp, "%d", &arr[i]);
    }

 #pragma omp parallel num_threads(3)
{
    #pragma omp parallel for private(i,j,key)
   for ( i = 0; i < n; i++)
   {
        key = arr[i];
	
	for( j=i ; j>0 && arr[j-1] > key ; j-- )
        #pragma omp critical 
	arr[j]=arr[j-1];
	arr[j]=key;
   }

}
    #pragma omp for
   for ( i=0; i < n; i++)
   {
       printf("%d ", arr[i]);
   }
      printf("\n");
    end= clock();
    total_t = (double)(end - begin );
    //printf("Total Numbers :  %d\n",n);	
    printf("Initial time taken by CPU: %d \n", begin  );
    printf("End time taken by CPU: %d \n", end  );
    printf("Total time taken by CPU: %f seconds\n", total_t  );
    free(arr);
    
    FILE *fpl;
	fpl=fopen("OMIS.txt","a+");
	fprintf(fpl,"%f,",total_t);
    
    	fclose(fpl);	

	}
  return 0;
}
