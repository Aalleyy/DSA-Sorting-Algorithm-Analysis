#include <iostream>
#include <chrono>

using namespace std;
using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::milliseconds;


//Bubble Sort

void bubbleSort(int a[], int size) {
    int i, j, tmp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (a[j + 1] < a[j]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

//Insertion Sort

void insertionSort(int a[], int size) {
    for (int p = 1; p < size; p++) {
        int tmp = a[p];
        int j;
        for (j = p; j > 0 && tmp < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

// Merging the Arrays

void merge(int a[], int left, int center, int right) {
    int i, j, k;
    int c[right + 1];
    i = left;
    k = left;
    j = center + 1;
    while (i <= center && j <= right) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= center) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= right) {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++) {
        a[i] = c[i];
    }
}

// Merge Sort

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, left, center);
        mergeSort(a, center + 1, right);
        merge(a, left, center, right);
    }
}

//Finding the Pivot

int partition(int a[], int left, int right) {
    int pivot = a[right], i = (left - 1), temp;
    for (int j = left; j <= right - 1; j++) {
        if (a[j] < pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;
    return (i + 1);
}

//Quick Sort

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
}


int main() {
    cout << "Sorting Algorithms Running-Time Analysis" << endl;

    int n[10] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

        for (int test = 0; test < 10; test++)
        {
            int data[n[test]],data2[n[test]],data3[n[test]],data4[n[test]];

            // Random Number Generator
            srand(time(0));
            for (int i = 0; i <= n[test]; i++)
            {
                data[i] = rand();
                data2[i] = data[i];
                data3[i] = data[i];
                data4[i] = data[i];
            }



            //Bubble Sort

            auto t1 = high_resolution_clock::now();
            bubbleSort(data, n[test]);
            auto t2 = high_resolution_clock::now();

            duration<double, milli> bubble = t2 - t1;

            //Insertion Sort

            auto t3 = high_resolution_clock::now();
            insertionSort(data2, n[test]);
            auto t4 = high_resolution_clock::now();

            duration<double, milli> insertion = t4 - t3;

            // Merge Sort

            auto t5 = high_resolution_clock::now();
            mergeSort(data3, 0, n[test] - 1);
            auto t6 = high_resolution_clock::now();

            duration<double, milli> mergeS = t6 - t5;

            //Quick Sort

            auto t7 = high_resolution_clock::now();
            quickSort(data4, 0, n[test] - 1);
            auto t8 = high_resolution_clock::now();

            duration<double, milli> quick = t8 - t7;

            // Running-Time of Sorting Algorithms

            cout << endl << "Time Taken for N = " << n[test] << endl << endl;
            cout << "Bubble Sort:\t\t" << bubble.count() << " ms" << endl;
            cout << "Insertion Sort:\t\t" << insertion.count() << " ms" << endl;
            cout << "Merge Sort:\t\t" << mergeS.count() << " ms" << endl;
            cout << "Quick Sort:\t\t" << quick.count() << " ms" << endl;
    }
    return 0;

}
