#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int left, int right, int x)
{
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (x == v[mid]) {
        return mid;
    } else if (x > v[mid]) {
        return binary_search(v, mid + 1, right, x);
    } else {
        return binary_search(v, left, mid - 1, x);
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 15};
    int x;
    cout << "Introduceți un număr de căutat: ";
    cin >> x;

    int index = binary_search(v, 0, v.size() - 1, x);

    if (index != -1) {
        cout << "Elementul " << x << " a fost găsit la indexul " << index << ".\n";
    } else {
        cout << "Elementul " << x << " nu a fost găsit.\n";
    }

    return 0;
}