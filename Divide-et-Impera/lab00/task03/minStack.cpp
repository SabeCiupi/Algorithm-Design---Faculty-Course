#include <iostream>

using namespace std;

/* Min Stack
-> folosim 2 array uri s si minS pt a simula cele 2 stive
-> s retine elem efective ale stivei
-> minS retine min curent la fiecare pozitie din s
->topind va indica poz curenta a varfului */

class MinStack {
    private:
        static const int MAX_SIZE = 30000;
        int s[MAX_SIZE];
        int minS[MAX_SIZE];
        int topInd;

    public:
        MinStack() {
            topInd = -1;
        }

        void push(int val) {
            if (topInd < MAX_SIZE) {
                topInd++;
                s[topInd] = val;

                //adaugam min curent in minS[]
                minS[topInd] = (topInd == 0) ? val : min(val, minS[topInd - 1]);
            }
        }

        void pop() {
            if (topInd > 0) {
                topInd--;
            }
        }

        int top() {
            return (topInd >= 0) ? s[topInd] : -10000; 
        }

        int getMin() {
            return (topInd >= 0) ? minS[topInd] : -10000;
        }
};

int main() 
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;

    minStack.pop();
    cout<<minStack.top()<<endl;
    cout << minStack.getMin() << endl;
    return 0;
}