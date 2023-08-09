#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionsort(int arr[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        swap(&arr[i],&arr[k]);
    }
}

int main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements...");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selectionsort(arr,n);
    printf("Sorted array is ...");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
