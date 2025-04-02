#include <iostream>

using namespace std;

void Hanoi(int n, char S, char D, char aux)
{
    if (n >= 1) {
        Hanoi (n-1, S, aux, D);

        cout <<"Mut disc " << n << " de pe tija "<< S << " pe tija "<< D << endl;

        Hanoi(n-1, aux, D, S);
    }
}

int main()
{
    int n;
    cout << "Introdu nuamrul de discuri: ";
    cin >> n;

    cout<< "Pasii de rezolvare a problemei Hanoi cu " << n << "discuri:\n";
    Hanoi (n, 'A', 'B', 'C');

    return 0;
}