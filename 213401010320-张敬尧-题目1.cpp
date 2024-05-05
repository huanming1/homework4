#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

// ���������
int generateRandomNumber(int maxNum) {
    return rand() % maxNum + 1;
}

// ���������
char generateOperator(vector<char> operators) {
    int index = rand() % operators.size();
    return operators[index];
}

// ���ɱ��ʽ
string generateExpression(int maxNum, vector<char> operators, bool allowDecimal) {
    string expression;
    int num1 = generateRandomNumber(maxNum);
    char op1 = generateOperator(operators);
    int num2 = generateRandomNumber(maxNum);

    expression += to_string(num1) + " " + op1 + " " + to_string(num2);

    if (allowDecimal) {
        expression += "." + to_string(rand() % 100); // ���С������
    }

    return expression;
}

// ������Ŀ
void generateExercises(int numExercises, int maxNum, vector<char> operators, bool allowDecimal) {
    ofstream outputFile("exercises.txt"); // ������ļ�

    if (!outputFile.is_open()) {
        cout << "Failed to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < numExercises; ++i) {
        string expression = generateExpression(maxNum, operators, allowDecimal);
        outputFile << "Exercise " << i + 1 << ": " << expression << " =" << endl;
    }

    outputFile.close();
    cout << "Exercises generated successfully. Check 'exercises.txt' file." << endl;
}

int main() {
    srand(time(0));

    int numExercises;
    int maxNum;
    bool allowDecimal;
    vector<char> operators;

    // ��ȡ�û�����
    cout << "Enter the number of exercises: ";
    cin >> numExercises;
    cout << "Enter the maximum number: ";
    cin >> maxNum;
    cout << "Allow decimals? (1 for yes, 0 for no): ";
    cin >> allowDecimal;

    char opChoice;
    cout << "Choose operators (+, -, *, /): ";
    cin >> opChoice;

    if (opChoice == '+') {
        operators.push_back('+');
    } else if (opChoice == '-') {
        operators.push_back('-');
    } else if (opChoice == '*') {
        operators.push_back('*');
    } else if (opChoice == '/') {
        operators.push_back('/');
    } else {
        cout << "Invalid operator choice. Using default: +" << endl;
        operators.push_back('+');
    }

    generateExercises(numExercises, maxNum, operators, allowDecimal);

    return 0;
}
