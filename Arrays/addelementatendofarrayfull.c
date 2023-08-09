//ARRAY IS FULL
//TIME COMPLEXITY IS O(n)
#include<stdio.h>
int add_at_end(int a[],int b[],int freepos,int size,int data){
    for(int i=0;i<size;i++){
        b[i]=a[i];
    }
    b[freepos]=data;
    freepos++;
    return freepos;
}
int main(){
    int a[3];
    int n,freepos;
    printf("Enter the no.of elements of the array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int size=sizeof(a)/sizeof(a[0]);
    freepos=n;
    if(size==n){
        int b[size+1];
        freepos=add_at_end(a,b,freepos,size,69);
        for(int i=0;i<freepos;i++){
            printf("%d ",b[i]);
        }
    }
    return 0;
}
