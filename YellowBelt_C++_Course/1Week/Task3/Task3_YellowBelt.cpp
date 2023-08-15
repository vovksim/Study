// Task3_YellowBelt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int dencity = 0;

class Block {
    int a;
    int b;
    int c;
    public: 
        Block() {
            a = 0;
            b = 0;
            c = 0;
        }
        void setParametrs(int aIn, int bIn, int cIn) {
            a = aIn;
            b = bIn;
            c = cIn;
        }
        int calculateVolume() {
            return static_cast<long long int>(a * b * c * dencity);
        }

};

int main()
{
    int quantity = 0;
    cin >> quantity;
    cin >> dencity;
    long long int result = 0;
    for (int i = 0; i < quantity; ++i) {
        Block temp;
        int atemp, btemp, ctemp;
        cin >> atemp >> btemp >> ctemp;
        temp.setParametrs(atemp, btemp, ctemp);
        result += temp.calculateVolume();
    }
    cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
