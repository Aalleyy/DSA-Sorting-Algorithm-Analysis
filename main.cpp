#include <iostream>
#include <vector>
using namespace std;

BubbleSort(){
    for (i=0; i<n-1; i++) { 
        for (j=0; j<n-1-i; j++) { 
            if (a[j+1] < a[j]) { // compare the two neighbors 
                tmp = a[j]; // swap a[j] and a[j+1]
                a[j] = a[j+1]; 
                a[j+1] = tmp; 
            } 
        } 
    }
}

InsertionSort(){
    for(int p=1; p<a.size();p++){
        Comparable tmp = a [p];
        for (j=p;j >0 && tmp < a [j-1]; j--)
            a [j]= a[j-1];
            a[j]=tmp;
    }
}

MergeSort(vector<int>&A, int left,int right){
     if (left<right){
        int center = (left + right)/2;
        MergeSort(A,left,center);
        MergeSort(A,center+1,right);
        merge(A,left,center+1,right);
     }
}
