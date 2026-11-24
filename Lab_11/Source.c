#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h> 

#define N 10
#define N2 100

void NumberOne();
void truncate_fraction(float arr[]);

void NumberTwo();
double calc_function(double x);

void HomeWork();


int main() {
    // Устанавливаем кодовую страницу для ввода и вывода в UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    setlocale(LC_ALL, "Russian");

    //NumberOne();
    //NumberTwo();
    HomeWork();

    return 0;
}

void NumberOne()
{
    float A[N];
    float original_A[N];
    float temp;

    printf("Введите %d вещественных чисел:\n", N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &temp);
        A[i] = temp;
        original_A[i] = temp;
    }

    truncate_fraction(A);

    printf("\n| индекс | исходное значение | новое значение |\n");
    printf("|--------|-------------------|----------------|\n");
    for (int i = 0; i < N; i++) {
        printf("| %-6d | %-17.4f | %-14.4f |\n", i + 1, original_A[i], A[i]);
    }

    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    float average = sum / N;
    printf("\nСреднее арифметическое элементов (после преобразования): %.4f\n", average);
}


void truncate_fraction(float arr[]) {
    for (int i = 0; i < N; i++) arr[i] = (int)arr[i]; 
}


void NumberTwo()
{
    double arr[N2];
    double x_start = 1.0;
    double x_end = 3.0;
    double step = (x_end - x_start) / (N2 - 1);

    for (int i = 0; i < N2; i++) {
        double x = x_start + i * step;
        arr[i] = calc_function(x);
    }

    double sum_pos = 0.0;
    double sum_neg = 0.0;
    int count_pos = 0;
    int count_neg = 0;

    for (int i = 0; i < N2; i++) {
        if (arr[i] > 0) {
            sum_pos += arr[i];
            count_pos++;
        }
        else if (arr[i] < 0) {
            sum_neg += arr[i];
            count_neg++;
        }
    }

    double avg_pos = 0.0;
    if (count_pos > 0) {
        avg_pos = sum_pos / count_pos;
    }

    printf("=== РЕЗУЛЬТАТЫ ===\n");
    printf("Имя массива: arr\n");
    printf("Накопленное значение (положительные): %.4lf\n", sum_pos);
    printf("Накопленное значение (отрицательные): %.4lf\n", sum_neg);
    printf("Число положительных элементов: %d\n", count_pos);
    printf("Число отрицательных элементов: %d\n", count_neg);
    printf("Среднее значение положительных: %.4lf\n", avg_pos);

    printf("\nПервые 5 элементов массива:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %.4lf\n", i, arr[i]);
    }
}

double calc_function(double x) {
    return fabs(exp(x) - 2.0) - (x * x);
}

void HomeWork() 
{
    int n;

    printf("Введите количество элементов массива (n): ");
    scanf_s("%d", &n);

    if (n < 2) {
        printf("Для поиска пары соседних элементов нужно минимум 2 элемента.\n");
        return 1;
    }

    // Динамическое выделение памяти
    int* arr = (int*)malloc(n * sizeof(int));

    printf("Введите %d целых чисел (через пробел или Enter):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Элемент [%d]: ", i);
        scanf_s("%d", &arr[i]);
    }

    int found_index = -1; 

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            found_index = i; 
            break;
        }
    }

    if (found_index != -1) {
        printf("\nНайдены соседние одинаковые значения: %d и %d\n", arr[found_index], arr[found_index + 1]);
        printf("Индекс первого из них: %d\n", found_index);

    }
    else printf("\nСоседних одинаковых значений не найдено.\n");
}