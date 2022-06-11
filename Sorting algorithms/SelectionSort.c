
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
//Function to print an array
void printArray(int arr[], int size)

{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{

  for(int i=0;i<10;i++)
{
    int n=0;
    /*printf("Enter no of elements you want in your array: ");
    scanf("%d\n",&n);
    int arr[n];
    for (int i=0;i<n;i++)
    {
scanf("%d",&arr[i]);
    }
*/
    clock_t begin, end;
    double total_t;
    begin = clock();
    FILE * fp;
    fp = fopen("1-10000.txt","r");
    fscanf(fp, "%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i=0; i < n; i++)
    {
fscanf(fp, "%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array: \n");
//printf("%d\n",n);
    printArray(arr, n);
    end= clock();
    total_t = (double)(end - begin );
    //printf("Total Numbers :  %d\n",n);
    printf("Initial time taken by CPU: %d \n", begin  );
    printf("End time taken by CPU: %d \n", end  );
    printf("Total time taken by CPU: %f seconds\n", total_t  );
    free(arr);
    
    FILE *fpl;
    fpl=fopen("Selectionsort.txt","a+");
    fprintf(fpl,"%f,",total_t);
    
    fclose(fpl);
}
    return 0;
}

	
	
	

