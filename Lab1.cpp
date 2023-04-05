#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <cmath>

using namespace std;
const int MATRIX_SIZE = 17;

// PREPARING
void GenerateMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
int GenerateRandomNumberInRange(int range);
void ShowMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int CountSumOfDigital(int number);
void StartTaskB(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main() {
	srand(time(NULL));

	int matrix[MATRIX_SIZE][MATRIX_SIZE]{};
	GenerateMatrix(matrix);
	RenderMenu(matrix);
}

// Сгенерировать матрицу 17х17, состоящую из случайных чисел в 
// диапазоне [-12, 12]
void GenerateMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			matrix[i][j] = GenerateRandomNumberInRange(12);
		}
	}
}

// Сгенерировать случайное число в диапазоне [-12; 12]
int GenerateRandomNumberInRange(int range) {
	return rand() % (range + 1) * 2 - range;

	if (!nullElementIsfound) cout << "Null element nto found" << endl;
}


// Вывод матрицы в консоль
void ShowMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
		cout << endl;
	}
}

// Подсчитать сумму цифр цисла number
int CountSumOfDigital(int number) {
	int count = 0;
	while (number != 0) {
		count += number % 10;
		number /= 10;
	}
	return (int)fabs(count);
}

// Проверить, содержит строка, номер которой введен с клавиатуры,
// знакочередующиеся элементы.
void StartTaskB(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	ShowMatrix(matrix);
	cout << "TASK B" << endl;
	cout << "Enter number of the stroke(1 - " << MATRIX_SIZE << "): ";
	int numberOfTheStroke{};
	cin >> numberOfTheStroke;

	bool signOfPrevious{};
	bool signOfCurrent{};
	bool flagOfCondition = true;
	for (int i = 1; i < 17; i++) {
		signOfPrevious = matrix[numberOfTheStroke - 1][i - 1] >= 0;
		signOfCurrent = matrix[numberOfTheStroke - 1][i] >= 0;
		if (signOfCurrent == signOfPrevious) {
			cout << "FALSE" << endl;
			flagOfCondition = false;
			break;
		}
	}
	if (flagOfCondition) cout << "TRUE" << endl;
}
