//TIME COMPLEXITY IS O(1)
#include<stdio.h>
int main(){
    int arr[]={45,98,3};
    int n;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Number of elements in the array is %d",n);
    return 0;
}