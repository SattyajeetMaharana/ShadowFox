#include <iostream>
using namespace std;

int linearSearch(int *a, int target,int n) {
    for (size_t i = 0; i <n; ++i)
        if (a[i] == target) 
        return i; 
        return -1;
}

int main() {
    int A[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(A)/sizeof(A[0]);
    int target;
    cout<<"Enter the key:";
    cin >> target;

    int idx = linearSearch(A, target, n);
    if (idx >= 0)
        cout << "Found at index " << idx << '\n';
    else
        cout << "Not found\n";

    return 0;
}