
#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    
    vector<int> temp(end-start+1);
    int left=start,right=mid+1;
    int index=0;

    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index]=arr[left];
            left++;
            index++;
        }else{
            temp[index]=arr[right];
            right++;
            index++;
        }
        //index++;
    }

    while(left<=mid){
       temp[index]=arr[left];
        left++;
        index++;
    }

    while(right<=end){
        temp[index]=arr[right];
        right++;
        index++;
    }

    //int n=end-start+1;
    for(int i=0; i<temp.size(); i++){
        arr[start+i]=temp[i];
    }
}
void mergesort(int arr[],int start,int end){
    
    if(start>=end){
        return;
    }
    
    int mid=start+(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
    
}

int main() {
    
    int arr[9]={9,3,7,4,6,2,8,1};
    mergesort(arr,0,8);

    for(int i=0; i<9; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
