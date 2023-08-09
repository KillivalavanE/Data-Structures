#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array arr){
    printf("Array elements are...");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

int main(){
    struct Array arr;
    printf("Enter the size of the array:");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the array elements...");
    for(int i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;
    display(arr);
}