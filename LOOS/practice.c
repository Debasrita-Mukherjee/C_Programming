// #include <stdio.h>
// #define MAX 100
// void merge(int arr[], int low, int mid, int high)
// {
// int i = low;
// int j = mid + 1;
// int k = low;
// int temp[100];
// while(i <= mid && j <= high)
// {
// if(arr[i] <= arr[j])
// temp[k++] = arr[i++];
// else
// temp[k++] = arr[j++];
// }
// while(i <= mid)
// temp[k++] = arr[i++];
// while(j <= high)
// temp[k++] = arr[j++];
// for(i = low; i <= high; i++)
// arr[i] = temp[i];
// }
// void mergeSort(int arr[], int low, int high)
// {
// if(low < high)
// {
// int mid = (low + high) / 2;
// mergeSort(arr, low, mid);
// mergeSort(arr, mid + 1, high);
// merge(arr, low, mid, high);
// }
// }
// int main()
// {
// int n, i;
// printf("Enter number of elements: ");
// scanf("%d", &n);
// int arr[MAX];
// printf("Enter elements:\n");
// for(i = 0; i < n; i++)
// scanf("%d", &arr[i]);
// mergeSort(arr, 0, n - 1);
// printf("Sorted array:\n");
// for(i = 0; i < n; i++)
// printf("%d ", arr[i]);
// return 0;
// }/
#include <stdio.h>
#define MAX 100
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
int partition(int arr[], int low, int high)
{
int pivot = arr[high];
int i = low - 1;
for(int j = low; j < high; j++)
{
if(arr[j] < pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return i + 1;
}
void quickSort(int arr[], int low, int high)
{
if(low < high)
{
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main()
{
int n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
int arr[MAX];
printf("Enter elements:\n");
for(i = 0; i < n; i++)
scanf("%d", &arr[i]);
quickSort(arr, 0, n - 1);
printf("Sorted array:\n");
for(i = 0; i < n; i++)
printf("%d ", arr[i]);
return 0;
}

