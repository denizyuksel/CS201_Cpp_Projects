#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int linearSearch( int*A, int N, int value)
{
    for (int i = 0; i < N; i++)
        if (A[i] == value)
        {
            return i;
        }
   return -1;

}

int binarySearch( int* A, int N, int value)
{
    int low = 0, high = N;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] < value)
            low = mid + 1;
        else if (A[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    cout << " Hello World " << endl;
    const int SIZE = 100000000;
    int* arr = new int[SIZE];

   for( int i = 0; i < SIZE; i ++)
   {
      arr[i] = i;
   }

    int key = 0;
    int valid = SIZE;
    cout << " Enter key: " << endl;
    cin >> key;
    //cout << " Enter valid no of elements: " << endl;
    //cin >> valid;
    for( int i = 0; i < valid; i++)
    {
        arr[i] = i;
    }
    const int LOOPFACTOR1 = 10;
    const int LOOPFACTOR2 = 10000000;
    //const int LOOPFACTOR1 = 1000;
    //const int LOOPFACTOR2 = 10000;
    double duration2;
    clock_t startTime2 = clock();

    //cout << linearSearch( arr, valid, key) << endl;
    //cout << binarySearch( arr, valid, key) << endl;

    for( int i = 0; i < LOOPFACTOR1; i++)
        linearSearch( arr, valid, key);

    duration2 =  (1000 * double(( clock() - startTime2 )) / CLOCKS_PER_SEC) / LOOPFACTOR1;
    cout << " For linear search, execution took " << duration2 << " milliseconds." << endl;

    double duration;
    startTime2 = clock();

    for( int i = 0; i < LOOPFACTOR2; i++)
        binarySearch( arr, valid, key);

    duration =  (1000 * double(( clock() - startTime2 )) / CLOCKS_PER_SEC) / LOOPFACTOR2;
    cout << " For binary search, execution took " << duration << " milliseconds." << endl;


    return -1;
}
