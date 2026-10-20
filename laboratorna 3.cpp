
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// Перевіримо введення дійсного числа
double readDouble(const string& message)
{
    double value;

    while (true)
    {
        cout << message;

        if (cin >> value && isfinite(value))
        {
            return value;
        }

        cout << "Помилка: Введіть коректне дійсне число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Перевіримо введення цілого числа
int readInt(const string& message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            return value;
        }

        cout << "Помилка: Введіть ціле число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Завдання 1: Обчислення функцій If34 та If35
void task1()
{
    cout << "\n Завдання 1: Обчислення значення функцій If 34 та If 35 \n";

    double x = readDouble("Введіть дійсне число x: ");

    // Обчислення значення функції v(x) за умовою If34
    long double v;

    if (x < 1)
    {
        v = static_cast<long double>(x) * x - 2.0L * x;
    }
    else if (x <= 3)
    {
        v = 2.0L * x + 1.0L;
    }
    else
    {
        v = 7;
    }

    // Обчислення значення функції u(x) за умовою If35
    long double u;

    if (x <= 0)
    {
        u = -static_cast<long double>(x) * x;
    }
    else if (x <= 3)
    {
        u = x;
    }
    else
    {
        u = 9.0L - x;
    }

    // Перевірка можливості збереження результатів у типі int
    const long double minInt = numeric_limits<int>::min();
    const long double maxInt = numeric_limits<int>::max();

    if (!isfinite(v) || !isfinite(u) ||
        v < minInt || v > maxInt ||
        u < minInt || u > maxInt)
    {
        cout << "Помилка: Результат не вміщується в тип int\n";
        return;
    }

    // Перетворення до int відкидає дробову частину
    int resultV = static_cast<int>(v);
    int resultU = static_cast<int>(u);

    cout << "v(x) = " << resultV << endl;
    cout << "u(x) = " << resultU << endl;
}

// Завдання 2: перевірка належності точки коричневій області
void task2()
{
    cout << "\n Завдання 2: варіант 15 \n";

    double r;

    // Перевіримо, чи додатній радіус
    do
    {
        r = readDouble("Введіть радіус r (> 0): ");

        if (r <= 0)
        {
            cout << "Помилка: Радіус повинен бути більшим за 0\n";
        }
    } while (r <= 0);

    double x = readDouble("Введіть координату x: ");
    double y = readDouble("Введіть координату y: ");

    // Межі верхньої правої чверті круга
    bool insideRectangle =
        (x >= r && x <= 2 * r &&
         y >= r && y <= 2 * r);

    // Перевірка відстані від центра (r, r) до точки
    long double dx = static_cast<long double>(x) - r;
    long double dy = static_cast<long double>(y) - r;
    long double radius = r;

    bool insideCircle =
        dx * dx + dy * dy <= radius * radius;

    // Точка належить коричневій області,
    // якщо виконується кожна з двох перевірок
    if (insideRectangle && insideCircle)
    {
        cout << "Точка належить коричневій області\n";
    }
    else
    {
        cout << "Точка НЕ належить коричневій області\n";
    }
}

// Завдання 3: Меню вибору номера завдання за допомогою switch
void task3()
{
    int choice;

    do
    {
        cout << "\n ГОЛОВНЕ МЕНЮ \n";
        cout << "1. Завдання 1: Обчислення значення функцій If 34 та If 35\n";
        cout << "2. Завдання 2: перевірка належності точки до коричневої області (варіант 15)\n";
        cout << "3. Завершення роботи програми\n";

        choice = readInt("Оберіть один із пунктів меню (1-3): ");

        // Вибір дії відповідно до введеного пункту
        switch (choice)
        {
            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            case 3:
                cout << "Програму завершено\n";
                break;

            default:
                cout << "Помилка: Оберіть пункт меню від 1 до 3\n";
        }

    } while (choice != 3);
}

int main()
{cout << "Laboratorna robota №3 Zastavskogo Nazara (319 a)" << endl;
    // Запуск програми через головне меню
    task3();

    return 0;
}
