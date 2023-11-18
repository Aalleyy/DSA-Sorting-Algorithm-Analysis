#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::microseconds;
using chrono::milliseconds;



void bubbleSort(const vector<int> &a){
    for (i=0; i<a.size()-1; i++) { 
        for (j=0; j<a.size()-1-i; j++) { 
            if (a[j+1] < a[j]) { // compare the two neighbors 
                tmp = a[j]; // swap a[j] and a[j+1]
                a[j] = a[j+1]; 
                a[j+1] = tmp; 
            } 
        } 
    }
}


void insertionSort(const vector<int> &a){
    for(int p=1; p<a.size();p++){
        int tmp =a[p];
        int j;
        for (j=p;j >0 && tmp < a [j-1]; j--)
            a [j]= a[j-1];
            a[j]=tmp;
    }
}
void merge(){
    
}

void mergeSort(vector<int>&A, int left,int right){
     if (left<right){
        int center = (left + right)/2;
        MergeSort(A,left,center);
        MergeSort(A,center+1,right);
        merge(A,left,center+1,right);
     }
}

int partition (){
    
}

void quickSort(){
    
}


void printArray(){
    
}








int main()
{
    
}
