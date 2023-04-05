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
