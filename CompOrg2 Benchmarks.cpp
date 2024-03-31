#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// 32-bit Integer operation benchmark
void intOperationBenchmark() {
    const int numAdditions = 1010;
    const long long numMultiplications = 5e9;
    const long long numDivisions = 2e9;

    auto start = high_resolution_clock::now();

    // Perform additions
    int result = 0;
    for (int i = 0; i < numAdditions; ++i) {
        result += 1;
    }

    // Perform multiplications
    for (long long i = 0; i < numMultiplications; ++i) {
        result *= 2;
    }

    // Perform divisions
    for (long long i = 0; i < numDivisions; ++i) {
        result /= 2;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "32-bit Integer operation benchmark time: " << duration << " milliseconds" << endl;
}

// 64-bit Floating point operation benchmark
void floatOperationBenchmark() {
    const int numAdditions = 1010;
    const long long numMultiplications = 5e9;
    const long long numDivisions = 2e9;

    auto start = high_resolution_clock::now();

    // Perform additions
    double result = 0.0;
    for (int i = 0; i < numAdditions; ++i) {
        result += 1.0;
    }

    // Perform multiplications
    for (long long i = 0; i < numMultiplications; ++i) {
        result *= 2.0;
    }

    // Perform divisions
    for (long long i = 0; i < numDivisions; ++i) {
        result /= 2.0;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "64-bit Floating point operation benchmark time: " << duration << " milliseconds" << endl;
}

// Memory benchmark
void memoryBenchmark() {
    const long long numElements = 5e9;
    int* arr = new int[numElements];

    auto start = high_resolution_clock::now();

    // Read from array
    for (long long i = 0; i < numElements; ++i) {
        int val = arr[i];
    }

    // Write to array
    for (long long i = 0; i < numElements; ++i) {
        arr[i] = i;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Memory benchmark time: " << duration << " milliseconds" << endl;

    delete[] arr;
}

// Hard drive benchmark 1
void hardDriveBenchmark1() {
    const long long fileSize = 1e9;
    const int chunkSize = 100;

    char* buffer = new char[chunkSize];

    auto start = high_resolution_clock::now();

    // Read from file
    ifstream inFile("testfile.bin", ios::binary);
    for (long long i = 0; i < fileSize; i += chunkSize) {
        inFile.read(buffer, chunkSize);
    }
    inFile.close();

    // Write to file
    ofstream outFile("testfile.bin", ios::binary);
    for (long long i = 0; i < fileSize; i += chunkSize) {
        outFile.write(buffer, chunkSize);
    }
    outFile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Hard drive benchmark 1 time: " << duration << " milliseconds" << endl;

    delete[] buffer;
}

// Hard drive benchmark 2
void hardDriveBenchmark2() {
    const long long fileSize = 1e9;
    const int chunkSize = 10000;

    char* buffer = new char[chunkSize];

    auto start = high_resolution_clock::now();

    // Read from file
    ifstream inFile("testfile.bin", ios::binary);
    for (long long i = 0; i < fileSize; i += chunkSize) {
        inFile.read(buffer, chunkSize);
    }
    inFile.close();

    // Write to file
    ofstream outFile("testfile.bin", ios::binary);
    for (long long i = 0; i < fileSize; i += chunkSize) {
        outFile.write(buffer, chunkSize);
    }
    outFile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Hard drive benchmark 2 time: " << duration << " milliseconds" << endl;

    delete[] buffer;
}

int main() {
    intOperationBenchmark();
    floatOperationBenchmark();
    memoryBenchmark();
    hardDriveBenchmark1();
    hardDriveBenchmark2();

    return 0;
}
