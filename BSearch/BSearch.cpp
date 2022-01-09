#include <iostream>
#include <vector>

using namespace std;

// testing only
// example for using and debugging thru recursion
int BSearch (vector<int>& v, int start, int stop, int key)
{
    cout << "BSearch called: start=" << start << ", stop=" << stop << endl;

    if (start > stop) {
        return -1;
    }

    int mid = (start + stop) / 2;
    if (v[mid] == key)
    {
        return mid;
    }
    else if (key < v[mid])
    {
        return BSearch(v, start, mid -1, key);
    }
    else if (key > v[mid])
    {
        return BSearch(v, mid +1, stop, key);
    }
    return -1;
}


int main()
{
    vector<int> v = { 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    int index = BSearch(v, 0, v.size() -1, 6);
    cout << index << endl;

    return 0;
}
