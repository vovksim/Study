// Poliz29.06.2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std; 

struct stack {
	char operation;
	stack* prev;
};

struct stackint {
	int num;
	stackint* prev;
};

void addstack(stack** head, char data) {
	stack* temp = new stack;
	temp->operation = data;
	if (!head) {
		temp->prev = NULL;
	}
	else {
		temp->prev = *head;
	}
	*head = temp;
}

void deletestack(stack** operations) {
	stack* temp = (*operations);
	(*operations) = (*operations)->prev;
	delete(temp);
}

void deletestackint(stackint** operations) {
	stackint* temp = (*operations);
	if((*operations)->prev)
	(*operations) = (*operations)->prev;
	else {
		(*operations) = NULL;
	}
	delete(temp);
}

void addstackint(stackint** head, char data) {
	stackint* temp = new stackint;
	temp->num = data;
	if (!head) {
		temp->prev = NULL;
	}
	else {
		temp->prev = *head;
	}
	*head = temp;
}

void showStack(stack* head) {
	while (head) {
		cout << head->operation << " ; ";
		head = head->prev;
	}
}

void showStackint(stackint* head) {
	while (head) {
		cout << head->num << " ; ";
		head = head->prev;
	}
}

void DoOperation(stackint** head, char symbol) {
	int result = 0;
	/*cout << "Stack in Operation func : ";
	showStackint(*head);
	cout << endl;*/
	if (symbol == '+') 
		result += (*head)->num + (*head)->prev->num;
	if (symbol == '*') 
		result += (*head)->num * (*head)->prev->num;
	if(symbol == '/')
		result += (*head)->prev->num / (*head)->num;
	if (symbol == '-')
		result += (*head)->prev->num - (*head)->num;
	deletestackint(head);
	if(*head)
	(*head)->num = result;
	else {
		addstackint(head, result);
	}
}

bool GetFromStack(stack* head, char symbol) {
	if (!head) {
		return false;
	}
	else if (head->operation == '(') {
		return false;
	}
	else if (symbol == '(') {
		return false;
	}
	else if ((symbol == '*' or symbol =='/') and (head->operation == '+' or head->operation=='-')) {
		return false;
	}
	else {
		return true;
	}
}


void CountPoliz(string expression, int length) {
	stackint* nums = NULL;
	for (int j = 0; j < length; j++) {
		if (expression[j] >= 48 and expression[j] <= 57) {
			addstackint(&nums, expression[j] - 48);
			//showStackint(nums);
		}
		else {
			//cout << expression[j] << endl;
			DoOperation(&nums, expression[j]);
		}
	}
	cout << nums->num;
}

void makePoliz(string input) {
	stack* operations = NULL;
	string output;
	output.resize(input.size() + 2);
	int l = input.length() , j=0;
	for (int i = 0; i < l; i++) {
		if (input[i] < 48 and input[i] != '!') {
			if (!GetFromStack(operations, input[i])) {
				addstack(&operations, input[i]);
				//cout << "Stack added symbol : " << input[i] << endl;
				if (input[i + 1] and input[i + 1] != '(')
					i++;
			}
			else if (input[i] == ')') {
				//cout << "Stack at the momemt : ";
				//showStack(operations);
				//cout << endl;
				while (operations->operation != '(') {
					output[j] = operations->operation;
					deletestack(&operations);
					j++;
				}
				deletestack(&operations);
				if (!operations)
					operations = NULL;
			}
			else {
				while (GetFromStack(operations, input[i])) {
					output[j] = operations->operation;
					deletestack(&operations);
					j++;
				}
				addstack(&operations, input[i]);
				if (input[i + 1] and input[i + 1] != '(')
					i++;
			}
		}
		if (input[i] >= 48 and input[i] <= 57) {
			output[j] = input[i];
			//cout << "output added : " << output[j] << endl;
			j++;
		}
	}
	while (operations) {
		output[j] = operations->operation;
		operations = operations->prev;
		j++;
	}
	cout << "Poliz : ";
	cout << output << endl;
	cout << "Counted POLIZ : ";
	CountPoliz(output, j);
	cout << endl;
	
	
}



int main()
{
	string input;
	cout << "Enter math expression : ";
	cin >> input;
	cout << endl;
	makePoliz(input);
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
