#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int MaxSearch(int arr[], int n) {

    int max = arr[0];

    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int MinSearch(int arr[], int n) {

    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    return min;
}

int main() {

    srand(time(0));

    int sizes[50];
    sizes[0] = 100;
    for (int i = 1; i < 50; i++) {
        sizes[i] = sizes[i - 1] + 100;
    }
    cout << "Arr size\ttime (max)\tmax\t\ttime (min)\tmin\n";

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        const int size = sizes[i];
        int arr[10001];
        int result1, result;

        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000;
        }
        int min = arr[0];
        int max = arr[0];
        double MaxTime = 0;
        double MinTime1 = 0;
        for (int i = 0; i < 50; i++); {
            clock_t start = clock();
            for (int j = 0; j < 100000; j++) {
                result = MaxSearch(arr, size);
            }
            clock_t end = clock();
            MaxTime += double(end - start) / CLOCKS_PER_SEC;


            start = clock();
            for (int j = 0; j < 100000; j++) {
                result1 = MinSearch(arr, size);
            }
            end = clock();
            MinTime += double(end - start) / CLOCKS_PER_SEC;
        }
        cout << size << "\t\t" << MaxTime / 50 << " sec\t" << result << "\t\t" << MinTime / 50 << " sec\t" << result1 << "\n";
    }
    return 0;
}