#include<stdio.h>

void insertionsort(int arr[],int n){
    int j,x;
    for(int i=1;i<n;i++){
        j=i-1;
        x=arr[i];
        while(j>-1 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
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
    insertionsort(arr,n);
    printf("Sorted array is ...");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
