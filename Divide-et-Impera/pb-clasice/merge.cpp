#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> v;

void merge (int left, int right)
{
    int mid = (left + right) / 2;
    vector<int> L, R;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // construim cei doi vectori
    for (int i = 0; i < n1; i++) {
        L.push_back(v[left + i]);
    }

    for (int j = 0; j < n2; j++) {
        R.push_back(v[mid + j + 1]);
    }

    // pentru parcurgerea
    int i, j = 0;
    i = 0;
    // pentru a adauga in vector
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < n1) {
        v[k++] = L[i++];
    }

    while (j < n2) {
        v[k++] = R[j++];
    }
}

void merge_sort(int left, int right)
{
    if (left >= right) return;
    int mid = (left + right )/ 2;

    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, right);
}

int main() {
    random_device rd;
	for (int i = 0; i < 10; i++) {
		v.push_back(rd() % 100);
	}
 
	cout << "Vectorul initial: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
 
	merge_sort(0, v.size() - 1);
 
	cout << "Vectorul sortat: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

    return 0;
}