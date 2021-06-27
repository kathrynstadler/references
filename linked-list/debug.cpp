// This program reads five numbers from the keyboard, and prints out the average and the maximum value

#include <iostream>
using namespace std;

// Global Constants
const int MAX = 5;

// Function Prototypes
double GetAverage( int nIn[], int nMax);
int GetMax( int nIn[], int nMax );


int main() {

    int nValues[MAX];
    int nCount;

    cout << "Enter five numbers: " << endl;

    for ( nCount = 0; nCount < MAX; nCount++ ) {
        cout << "Enter the next number : ";
        cin >> nValues[nCount];
    }

    for ( nCount = 0; nCount < MAX; nCount++) {
        cout << "Value [ " << nCount+1 << "] is : " << nValues[nCount] << endl;
    }

    cout << "The average is " << GetAverage(nValues, MAX ) << endl;

    cout << "The max is " << GetMax(nValues, MAX ) << endl;

    return 0;

} // End of main


double GetAverage(int nIn[], int nMax) {

    double temp = 0.0;
    for ( int i = 0; i < nMax; i++)
        temp += nIn[i];
    temp /= nMax;

    return temp;
} // End of GetAverage()


int GetMax( int nIn[], int nMax) {
    int nBiggest = nIn[0];
    for ( int i = 1; i < nMax; i++)
        if (nBiggest < nIn[i])
            nBiggest = nIn[i];
    return nBiggest;
} // End of GetMax()
