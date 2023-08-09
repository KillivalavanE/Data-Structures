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
    /*int diff;
    diff=arr[0]-0;
    printf("Missing elements are...");
    for(int i=0;i<n;i++){
        if((arr[i]-i)!=diff){
            while(diff<arr[i]-i){
                printf("%d ",diff+i);
                diff++;
            }
        }
    }*/
    bubblesort(arr,n);
    int l=arr[0];
    int h=arr[n-1];
    int H[h+1];
    for(int i=0;i<h+1;i++){
        H[i]=0;
    }
    for(int i=0;i<n;i++){
        H[arr[i]]++;
    }
    printf("Missing elements are...");
    for(int i=l;i<=h;i++){
        if(H[i]==0){
            printf("%d ",i);
        }
    }
    return 0;
}