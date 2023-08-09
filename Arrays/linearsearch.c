#include <stdio.h>
int search(int array[], int n, int num){
  for(int i=0;i<n;i++){
    if(array[i]==num)
      return i;
  }
  return -1;
}

int main(){
  int n;
  printf("Enter array size:");
  scanf("%d",&n);
  int array[n];
  printf("Enter the array elements...");
  for(int i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  int num;
  printf("Enter the element to be searched:");
  scanf("%d",&num);
  int result = search(array, n, num);
  (result == -1) ? printf("Element not found") : printf("Element %d is found at index: %d",num, result);
}