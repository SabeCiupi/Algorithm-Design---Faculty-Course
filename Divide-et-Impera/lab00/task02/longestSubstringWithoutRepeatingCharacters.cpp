#include <iostream>
#include <cstring>

using namespace std;

/*Longest Substring Without Repeating Characters
-> folosim un Sliding Window care se extinde pana gasim un caracter duplicat
-> dc apare un caracter duplicat, mutam left inainte, astfel incat sa elim dup
-> pastram un array pt a tine ultima poz a ultimului caracter
-> actualizam lungimea max a substringului fara duplicate
O(n)*/

int lengthOfLongestSubstring(string s) {
    int charInd[256];
    memset(charInd, -1, sizeof(charInd));

    int l = 0, max = 0;

    for (int r = 0; r < s.length(); r++) {
        //daca caracterul a fost vazut inainte, mutam left
        if (charInd[s[r]] != -1) {
            l = (l < charInd[s[r]] + 1) ? charInd[s[r]] + 1 : l;
        }

        // salvam pozitia caracterului curent
        charInd[s[r]] = r;

        // calculam lungimea substringului valid
        max = (max < r - l + 1) ? r-l+1 : max;
    }

    return max;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s)<< endl;
    return 0;
}