#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool recSum(int v1[], int n1, int v2[], int n2, int x) {
    int i = 0, j = n2 - 1;

    while (i < n1 && j >= 0) {
        int s = v1[i] + v2[j];
        if (s == x) return true;
        else if (s < x) i++;
        else j--;
    }

    return false;
}

bool sumExists(vector <int> &v, int x) {
    if (v.size() < 2) return false; //daca vectorul mai are un element, nu am gasit

    sort(v.begin(), v.end());

    //functie recursiva interna
    function<bool(int, int)> divide = [&](int st, int dr) -> bool {
        if (dr - st + 1 <= 1) return false; //daca avem mai putine elemente => nu am gasit
        if (dr-st + 1 == 2) return v[st] +v[dr] == x; // daca avem 2 elemente, verificam daca am gasim suma a+b=x

        int mij = (st + dr) / 2;

        int n1 = mij - st + 1;
        int n2 = dr - mij;

        int St[n1], Dr[n2];

        for (int i = 0; i < n1; i++) {
            St[i] = v[st+i];
        }

        for (int i = 0; i < n2; i++) {
            Dr[i] = v[mij + 1 + i];
        }

        if (recSum(St, n1, Dr, n2, x)) return true;

        return divide(st, mij) || divide(mij+1, dr);
        
    };
    return divide(0, v.size() - 1);
}

int main() {
    vector<int> M = {2, 4, 3, 5, 9};
    int x = 8;

    if (sumExists(M, x))
        cout << "Exista doua elemente a + b = " << x << endl;
    else
        cout << "NU exista doua elemente a + b = " << x << endl;
}
