#include<stdio.h>
int binarysearch(int array[],int n,int num){
    int l=0;
    int mid;
    int h=n-1;
    while(l<=h){
        mid=(l+h)/2;
        if(num==array[mid]){
            return mid;
        }
        else if(num<array[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
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
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    int num;
    printf("Enter the element to be searched:");
    scanf("%d",&num);
    int result = binarysearch(array, n, num);
    (result == -1) ? printf("Element not found") : printf("Element %d is found ",num);
    return 0;
}