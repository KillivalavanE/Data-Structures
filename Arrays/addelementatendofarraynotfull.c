//ARRAY IS NOT FULL
//TIME COMPLEXITY IS O(1)
#include<stdio.h>
int add_at_end(int a[],int freepos,int data){
    a[freepos]=data;
    freepos++;
    return freepos;
}
int main(){
    int a[10];
    int n,freepos;
    printf("Enter the no.of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    freepos=n;
    freepos=add_at_end(a,freepos,69);
    for(int i=0;i<freepos;i++){
        printf("%d ",a[i]);
    }
}

