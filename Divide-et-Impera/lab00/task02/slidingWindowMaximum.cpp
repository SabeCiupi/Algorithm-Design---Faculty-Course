#include <iostream>
#include <deque>

using namespace std;

/*Sliding Window Maximum
-> folosim un deque(double-ended queue) pt ca ne permite sa adaugam si sa
eliminam elem eficient.
-> eliminam elem care nu mai fac parte din fereastra curenta si cele mai mici
-> va fi pastram mereu elem in ordine descrescatoare, primul elem este intotdeauna
maximul
adaugam maximul fiecarei ferestre in rezultat*/

void maxSlidingWindow (int v[], int n, int k, int res[])
{
    deque<int> dq;
    int ind = 0;

    for (int i = 0; i < n; i++) {
        // elim elementele care ies din fereastra curenta
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // elim din coada elem mai mici decat v[i]
        while (!dq.empty() && v[dq.back()] <= v[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1) {
            res[ind++] = v[dq.front()];
        }
    }
}

int main()
{
    int v[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = sizeof(v)/sizeof(v[0]);

    int resSize = n - k + 1;
    int res[resSize];

    maxSlidingWindow(v, n, k, res);

    cout << "[ ";
    for (int i = 0; i < resSize; i++) {
        cout << res[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}