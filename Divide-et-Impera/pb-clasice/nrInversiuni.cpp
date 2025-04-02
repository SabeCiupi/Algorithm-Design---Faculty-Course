#include <iostream>

using namespace std;

int mergeCount(int v[], int p, int mij, int u) {
    int n1 = mij-p + 1;
    int n2 = u - mij;
    
    int St[n1], Dr[n2];

    for (int i = 0; i < n1; i++) St[i] = v[p + i];
    for (int i = 0; i < n2; i++) Dr[i] = v[mij + 1 + i];

    int i, j, k;
    i = j = 0;
    k = p;
    int count = 0;
    while (i < n1 && j < n2) {
        if(St[i] <= Dr[j]) {
            v[k++] = St[i++];
        } else {
            v[k++] = Dr[j++];
            count += n1-i; // n1-i pentru ca elementele de dupa primul mai mare sunt si ele mai mari=>inversiune
            //{2, 4, 6} {1,3} 2>1, dar si 4>1, 6>1;
        }
    }

    while (i < n1) {
        v[k++] = St[i++];
    }

    while (j < n2) {
        v[k++] = Dr[j++];
    }

    return count;
}

int countInversions(int v[], int p, int u) {
    int count = 0;
    if (p < u) {
        int mij = (p + u) / 2;
        count += countInversions(v, p, mij);
        count += countInversions(v, mij + 1, u);
        count += mergeCount(v, p, mij, u);
    }
    return count;
}

int main () {
    int v[] = {2, 4, 1, 3, 5}; // 3 inversiuni: (2,1), (4,1), (4,3)
    int n = sizeof(v) / sizeof(v[0]);

    int copie[1000];
    for (int i = 0; i < n; ++i) copie[i] = v[i];

    int nrInversiuni = countInversions(copie, 0, n - 1);

    cout << "Numarul de inversiuni: " << nrInversiuni << endl;
}