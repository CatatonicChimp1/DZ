# include <iostream>
#include <cstdlib>
#include <ctime>
//int main()
//{
//Task1
   // /*1.1*/
   // const float a = 3.2;
   // const float* const fPtr = &a;

   // /*1.2*/
   // typedef long int *cake_ptr;

   // /*1.3*/
   // double c = 0;
   // double* cPtr = &c;

   // /*1.4*/
   // const short int d = 0;
   // const short int* dPtr = &d;

   // /*1.5*/
   // typedef const float * const opa_ptr;
   // const opa_ptr e = 0;

   // /*1.6*/
   // typedef const char *ura_ptr;
   // ura_ptr f = "f";

   ///*1.7*/
   // double h = 0.0;
   // double* const hPtr = &h;
   // 
   // /*1.8*/
   // typedef unsigned int * const hahahahah_ptr;

//Task2
//double* First(int size)
//{
//	double* array = new double[size];
//	return array;
//}
//void Second(int size, double *array)
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << "i = " << i+1 <<std::endl;
//		std::cin >> array[i];
//	}
//}
//void Third(double* array, int size)
//{
//	std::cout << "Array = ";
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << array[i]<<", ";
//	}
//	std::cout << std::endl;
//}
//void Four(double* array)
//{
//	delete[] array;
//}
//
//int main()
//{
//	double* array;
//	 int lenght;
//	 char new_massiv;
//	 do {
//		 std::cout << "Lenght array = ";
//		 std::cin >> lenght;
//		 array = First(lenght);
//		 Second(lenght, array);
//		 Third(array, lenght);
//		 Four(array);
//		 std::cout << "Do you want create new massiv?" << std::endl;
//		 std::cin >> new_massiv;
//	 }
//	 while (new_massiv == '1');
//Task3
//void swapEvenOdd(int* arr, int size)
//{
//    for (int i = 0; i < size - 1; i += 2) {
//        int temp = arr[i];
//        arr[i] = arr[i + 1];
//        arr[i + 1] = temp;
//    }
//}
//
//int main()
//{
//    const int size = 12;
//    int* array = new int[size]; // выделение памяти для массива из 12 элементов
//    // инициализация массива
//    for (int i = 0; i < size; i++) {
//        array[i] = i + 1; // значения от 1 до 12
//    }
//    std::cout << "First massiv:\n";
//    for (int i = 0; i < size; i++) {
//        std::cout << array[i] << " "; // печать исходного массива
//    }
//    swapEvenOdd(array, size); // вызов функции для замены значений четных и нечетных ячеек
//    std::cout << "\nSecond massiv:\n";
//    for (int i = 0; i < size; i++) {
//        std::cout << array[i] << " "; // печать массива после замены
//    }
//    delete[] array; // освобождение памяти
//	return 0;
//}
//Task4
// Функция для заполнения двумерного массива случайными числами от 10 до 50
//void fillArray(int** arr, int rows, int cols) {
//    srand(time(nullptr)); // инициализация генератора случайных чисел
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            arr[i][j] = rand() % 41 + 10; // генерация чисел от 10 до 50
//        }
//    }
//}
//// Функция для показа двумерного массива на экране
//void displayArray(int** arr, int rows, int cols) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            std::cout << arr[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//int main()
//{
//    int rows, cols;
//
//    std::cout << "Enter number of lines: ";
//    std::cin >> rows;
//    std::cout << "Enter the number of columns: ";
//    std::cin >> cols;
//
//    // Выделение памяти под двумерный массив
//    int** dynamicArray = new int* [rows];
//    for (int i = 0; i < rows; ++i) {
//        dynamicArray[i] = new int[cols];
//    }
//
//    fillArray(dynamicArray, rows, cols); // Заполнение массива случайными числами
//    displayArray(dynamicArray, rows, cols); // Вывод массива на экран
//
//    // Освобождение выделенной памяти
//    for (int i = 0; i < rows; ++i) {
//        delete[] dynamicArray[i];
//    }
//    delete[] dynamicArray;
//	return 0;
//}
//Task5
// Объявление типа указателя на функцию
typedef int (*Operation)(int, int);

// Функции для арифметических операций
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    else {
        std::cout << "Деление на ноль!" << std::endl;
        return 0;
    }
}

int main() {
    // Массив указателей на функции
    Operation operations[] = { &add, &subtract, &multiply, &divide };

    int num1, num2;
    char op;

    while (true) {
        std::cout << "Enter the first number (enter q to complete): ";
        if (!(std::cin >> num1)) {
            break;
        }

        std::cout << "Enter second number: ";
        if (!(std::cin >> num2)) {
            break;
        }

        std::cout << "Enter the operation (+, -, *, /): ";
        std::cin >> op;

        // Проверка на пробел для завершения программы
        if (op == 'q') {
            break;
        }

        Operation selectedOperation = nullptr;
        switch (op) {
        case '+':
            selectedOperation = &add;
            break;
        case '-':
            selectedOperation = &subtract;
            break;
        case '*':
            selectedOperation = &multiply;
            break;
        case '/':
            selectedOperation = &divide;
            break;
        default:
            std::cout << "Incorrect operation! Try again." << std::endl;
            continue; // Переход на новую итерацию цикла
        }

        // Вызов функции, используя выбранную операцию и вывод результата
        std::cout << "Result: " << selectedOperation(num1, num2) << std::endl;
    }

    return 0;
}