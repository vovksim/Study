// YellowBelt_2Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>

using namespace std;


void InputTemperature (vector<int>& temperature, int length, int& sum) {
    int temp = 0;
    for (int i = 0; i < length; ++i) {
        cin >> temp;
        sum += temp;
        temperature.push_back(temp);
    }
}

void IndexesOfHigherTemperature(int sum, vector<int> temperature, int length) {
    float average = sum / length;
    int quantity = 0;
    vector<int> indexes;
    for (int i = 0; i < length; ++i) {
        if (temperature[i] > average) {
            ++quantity;
            indexes.push_back(i);
        }
    }
    cout << quantity << "\n";
    vector<int> ::iterator a;
    for (a = indexes.begin(); a != indexes.end(); ++a) {
        cout << *a << " ";
    }
    
}


int main()
{
    vector<int> temperature;
    int length = 0, sum = 0;
    cout << "Enter number of days : ";
    cin >> length;
    InputTemperature(temperature, length, sum);
    IndexesOfHigherTemperature(sum, temperature, length);
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
