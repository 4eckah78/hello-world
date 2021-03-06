
#include "pch.h"
#include <iostream>
#include <vector>
#include "time.h"

bool b = false;
int sum = 0;
void rec(int n, int sum1, int sum2, int N, int* mas, int res) {
  if (n == N) std::cout << n << "  " << sum1 << "  " << sum2 << " \n";
  if (n == N) {
    if (sum1 - sum2 == 0) {
      sum = sum1;
      b = true;
    }
    return;
  }
  rec(n + 1, sum1 + mas[n], sum2, N, mas, res);
  rec(n + 1, sum1, sum2 + mas[n], N, mas, res);
}



int main() {
  setlocale(LC_ALL, "rus");

  /*
  int M = 0, N = 0;
  std::cout << "Введите M и N " << std::endl;
  std::cin >> M >> N;
  if (M > N) {
    std::cout << "Ошибка \n";
    return 0;
  }
  
  int maxCount = -1;

  std::vector<int> maxes;

  for (int i = M; i <= N; ++i) {
    int count = 0;
    for (int j = 1; j <= i; ++j) 
      if (i % j == 0)
        count++; 
    if (count > maxCount) {
      maxCount = count;
      maxes.clear();
      maxes.push_back(i);
    }
    else if (count == maxCount)
      maxes.push_back(i);
  }

  for (int k = 0; k < maxes.size(); ++k)
    std::cout << maxes[k] << std::endl;
  */

  //------------------------------------------------------

  /*
  srand(time(0));
  int randomNumber = rand() % 101;

  while (1) {
    std::cout << "Введите число \n";
    int userNumber = 0;
    std::cin >> userNumber;
    if (userNumber > randomNumber) {
      std::cout << "Ваше число больше \n";
    }
    else if (userNumber < randomNumber) {
      std::cout << "Ваше число меньше \n";
    }
    else {
      std::cout << "Вы угадали!!! =) \n";
      break;
    }
  }
  */

  //------------------------------------------------------

  /*
  int n = 0;
  std::cout << "Введите количество камней \n";
  std::cin >> n;
  if (n >= 10 || n < 1) {
    std::cout << "Неправильное число камней! \n";
    return 0;
  }  
  int* stones = new int[n];

  std::cout << "Введите массы камней \n";
  for (int i = 0; i < n; i++) {
    std::cin >> stones[i];
    if (stones[i] < 1 || stones[i] > 9999) {
      std::cout << "Неправильна! \n";
      return 0;
    }
  }

  if (n == 1) {
    std::cout << "No \n";
    return 0;
  }

  if (sum % 2 != 0) {
    std::cout << "No \n";
    return 0;
  }

  int res = 10000;

  rec(0, 0, 0, n, stones, res);

  if (b) {
    std::cout << "YES \n";
    std::cout << sum << "\n";
  }
  else
    std::cout << "NO \n";

  delete[] stones;

  */
  return 0;
}


/*
1) Найти в интервале [M, N] число, имеющее наибольшее количество
делителей.

2) «Отгадай число» Условия игры: Компьютер генерирует случайное
целое число, не превосходящее 100. Играющий пытается угадать это
число, делая несколько попыток, после каждой из которых компьютер
сообщает, какое из чисел больше.

3) Напишите программу, которая по весам камней определяет, можно ли их
разбить на две кучки равной массы.
Вход число камней n<10 и n натуральных чисел <10000 – массы этих
камней; Выход YES или NO.
*/