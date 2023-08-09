//TIME COMPLEXITY IS O(1)
#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    size=size-1;
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}