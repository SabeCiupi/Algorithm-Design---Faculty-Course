#include <iostream>

using namespace std;
/*SOLUTIA 1 - aflarea al k-lea cel mai mare numar din vector
-> sortam vectorul crescator
-> si intoarcem al k-lea numar
O(nlogn)*/

void merge(int v[], int p, int u, int mid)
{
    //facem vectorul stanga si dreapta
    int n1 = mid - p + 1;
    int n2 = u - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0;
    int k = p;
    // interclasam
    while (i < n1 && j < n2) {
        if (L[i] < R[j])
            v[k++] = L[i++];
        else 
            v[k++] = R[j++];
    }

    // restul elementelor din L
    while (i < n1)
        v[k++] = L[i++];

    // restul elementelor din R
    while (j < n2)
        v[k++] = R[j++];
}

void merge_sort(int v[], int p, int u)
{
    // conditia de oprire
    if (p >= u)
        return;

    int k = (p + u)/2;
    merge_sort(v, p, k);
    merge_sort(v, k+1, u);
    merge(v, p, u, k);
}

int main()
{
    int v[] = {12, 2, 43, 5, 65, 23};
    int k = 3;
    int n = 6;

    merge_sort(v, 0, n);

    cout << v[n-k] << "\n";
}