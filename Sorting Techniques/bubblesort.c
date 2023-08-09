#include<stdio.h>

void bubblesort(int arr[],int n){
    int temp,flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
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
    bubblesort(arr,n);
    printf("Sorted array is ...");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}

