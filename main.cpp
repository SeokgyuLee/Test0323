#include <iostream>
#define  max 10

using namespace std;

//conguer - 서열정리
void merge(int a[], int low, int mid, int high)
{
    int temp[1000];
    int i=low;
    int j=mid+1;
    int k=0;

    // fight
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k]= a[j];
            j++;
            k++;
        }
    }
    //왼쪽이 끝나지 않았다면
    while(i<=mid){
        temp[k] = a[i];
        k++;
        i++;
    }
    //오쪽이 끝나지 않았다면
    while(j<=high){
        temp[k]=a[j];
        j++;
        k++;
    }
    k--;
    while(k>=0){
        a[low+k]= temp[k];
        k--;

    }



    return;
}
//divide - 대진표 작성
void mergesort(int a[], int low, int high)
{

    //exit condition
        if(low<high)
        {
            int m = (low + high)/2;
            //left
            mergesort(a, low, m);
            //right
            mergesort(a,m+1,high);
            //fight
            merge(a,low,m,high);
        } else{
            return ;
        }
}
int main() {

    int a[max] = {20, 10,2000, 70, 80, 40, 90, 100, 25, 40};
    int i =0;
    cout<<"before merge"<<endl;
    for(i=0;i<max;i++){
        cout<<a[i]<<" ";
    }
    mergesort(a,0,max-1);
    cout<<endl<<"after merge"<<endl;
    for(i=0;i<max;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}