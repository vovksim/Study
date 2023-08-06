// Yellow_1Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <string>
#include <exception>

using namespace std;


class Matrix {
    vector<vector<int>> field;
    int RowQuantity;
    int ColumnQuantity;
public :
    Matrix() { vector<vector<int>>  field(0, vector<int>(0)); RowQuantity = 0; ColumnQuantity = 0; }
    Matrix(int num_rows, int num_cols) {
        if (num_rows < 0 or num_cols < 0) {
            throw std::out_of_range("out_of_range");
        }
        vector<vector<int>> field (num_rows,vector<int>(num_cols));
        RowQuantity = num_rows;
        ColumnQuantity = num_cols;
    }
    void Reset(int newRow, int newColumn) {
        if (newRow < 0 or newColumn < 0) {
            throw std::out_of_range("out_of_range");
        }
        field.resize(newRow, vector<int>(newColumn));
        for (int i = 0; i < newRow; i++) {
            fill(field[i].begin(), field[i].end(), 0);
        }
        RowQuantity = newRow;
        ColumnQuantity = newColumn;
    }
    int At(int Row, int Column) const {
        if (Row > field.size() or Column > field[0].size()) {
            throw std::out_of_range("out_of_range");
        }
        return field[Row][Column];
    }
    int& At(int Row, int Column) {
        return field[Row][Column];
    }
    int GetNumColumns() {
        return ColumnQuantity;
    }
    int GetNumRows() {
        return RowQuantity;
    }
    friend istream& operator >> (istream& in, Matrix& field) {
        in >> field.RowQuantity;
        in >> field.ColumnQuantity;
        field.Reset(field.RowQuantity, field.ColumnQuantity);
        for (int i = 0; i < field.RowQuantity; i++) {
            for (int j = 0; j < field.ColumnQuantity; j++) {
                in >> field.field[i][j];
            }
        }
        cout << endl;
        return in;
    }

    friend ostream& operator << (ostream& out, Matrix field) {
        out << field.RowQuantity << " " << field.ColumnQuantity << "\n";
        for (int i = 0; i < field.RowQuantity; i++) {
            for (int j = 0; j < field.ColumnQuantity; j++) {
                out << field.field[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }

    bool operator == (Matrix field2) {
        if (this->RowQuantity == field2.RowQuantity and this->ColumnQuantity == field2.ColumnQuantity) {
            for (int i = 0; i < field2.RowQuantity; i++) {
                for (int j = 0; j < field2.ColumnQuantity; j++) {
                    if (field2.field[i][j] != this->field[i][j])
                        return false;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }

    Matrix operator + (Matrix field2) {
        Matrix result;
        if (this->RowQuantity == field2.RowQuantity and this->ColumnQuantity == field2.ColumnQuantity) {
            result.RowQuantity = this->RowQuantity;
            result.ColumnQuantity = this->ColumnQuantity;
            result.Reset(this->RowQuantity, this->ColumnQuantity);
            for (int i = 0; i < field2.RowQuantity; i++) {
                for (int j = 0; j < field2.ColumnQuantity; j++) {
                    result.field[i][j] = this->field[i][j] + field2.field[i][j];
                }
            }
            return result;
        }
        else {
            throw std::invalid_argument("Invalid argument!");
        }
    }

};




int main()
{
    try {
        Matrix x1, x2;
        cin >> x1;
        cin >> x2;
        cout << x1 << endl << x2 << endl;
        cout << x1 + x2 << endl;

    }
    catch (std::out_of_range& e) {
        cout << "Exception : " << e.what() << endl;
    }
    catch (std::invalid_argument& e) {
        cout << "Exception : " << e.what() << endl;
    }


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
