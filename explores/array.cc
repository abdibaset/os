#include <chrono>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 3};

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size(arr); i++) {
        cout << arr[i] << endl;
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;
    cout << "time taken :" << duration.count() << endl;
}