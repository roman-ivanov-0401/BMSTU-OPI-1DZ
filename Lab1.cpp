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
void RenderMenu(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

//TASKS
void StartTaskA(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
int CountSumOfDigital(int number);
void StartTaskB(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void StartTaskC(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


// MENU
// Вывод меню в консоль и предоставление выбора
// пункта меню пользователю
void RenderMenu(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int numberOfChosenPoint{};

	do {
		cout << "LABORATORY WORK #1" << endl;
		cout << "[1] TASK #1" << endl;
		cout << "[2] TASK #2" << endl;
		cout << "[3] TASK #3" << endl;
		cout << "[4] SHOW MATRIX" << endl;
		cout << "[0] EXIT" << endl;
		cout << "Enter number of option: ";
		cin >> numberOfChosenPoint;

		switch (numberOfChosenPoint) {
		case 1:
			StartTaskA(matrix);
			break;
		case 2:
			StartTaskB(matrix);
			break;
		case 3:
			StartTaskC(matrix);
			break;
		case 4:
			ShowMatrix(matrix);
			break;
		}
		system("pause");
		system("cls");
	} while (numberOfChosenPoint >= 1 && numberOfChosenPoint <= 4);
}

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

// К каждому элементу  целочисленной матрицы прибавить сумму  цифр элемента,
// стоящего в этой же строке на побочной диагонали
void StartTaskA(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	ShowMatrix(matrix);
	int diagonalValue = 0;
	int i = 0;
	for (int j = MATRIX_SIZE - 1; j >= 0; j--)
	{
		diagonalValue = CountSumOfDigital(matrix[i][j]);
		for (int k = 0; k < MATRIX_SIZE; k++)
		{
			matrix[i][k] += diagonalValue;
		}
		i++;

	}
	cout << endl;
	cout << "Result: " << endl;
	ShowMatrix(matrix);
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

// Указать номер строки и столбца  первого нулевого элемента среди элементов матрицы,
// выделенных чёрным цветом (матрица квадратная).
void StartTaskC(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	ShowMatrix(matrix);
	bool nullElementIsfound = false;
	for (int i = 5; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			if (matrix[i][j] == 0)
			{
				cout << endl << "Number of stroke: " << i + 1 << endl
					<< "Number of column: " << j + 1 << endl;
				nullElementIsfound = true;
				break;
			}

		}
		if (nullElementIsfound) break;
	}
	if (!nullElementIsfound) cout << "Null element nto found" << endl;
}

