#include <iostream>
#include <queue>

using namespace std;

/*SOLUTIA 2 - aflarea al k-lea cel mai mare numar din vector
-> se adauga initial primele k elemente in heap
-> pt fiecare din elem urmatoare, daca acesta este mai mare decat min din heap,
se sterge min si se adauga elem curent. Mereu in heap avem k elem la final de
pas in aceasta etapa
-> raspunsul este min din heap la finalul parcurgerii.
O(nlogk) -- solutie mai optima */

int findKthLargest(int v[], int k, int n)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // adaugam primele k elem in heap
    for (int i = 0; i < k; i++) {
        minHeap.push(v[i]);
    }

    // parcurgem restul elementelor
    for (int i = k; i < n; i++) {
        if (v[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(v[i]);
        }
    }

    // returnam minimul din heap
    return minHeap.top();
}

int main()
{
    int v[] = {12, 2, 43, 5, 65, 23};
    int n = sizeof(v)/sizeof(v[0]);
    int k = 3;
    cout<<findKthLargest(v, k, n) << endl;

    return 0;
}