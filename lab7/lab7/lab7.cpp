// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


/* 11. Функція переводить комплексне число z = x + iy з алгебраїчної форми в
тригонометричну z = radius(cos(angle) + i*sin(angle)). Комплексне число z
представлене структурою-парою. Перетворене число теж представляється
структурою-парою (radius, angle):
*/

#include <iostream>
#include <Windows.h>
using namespace std;

struct z
{
    int real, imag;
};

struct z_peretvorene
{
    double radius, angle;
};

double cos(int x, int y)
{
    if (x == 0 && y == 0)
        cout << ("ERROR(ділення на 0)") << endl;
    else
        if (x / sqrt(pow(x, 2) + pow(y, 2)) < -1 || x / sqrt(pow(x, 2) + pow(y, 2)) > 1)
            cout << "ERROR(Косинус лежить в межах (-1;1))" << endl;
        else
            return x / sqrt(pow(x, 2) + pow(y, 2));
}

double sin(int x, int y)
{
    if (x == 0 && y == 0)
        throw ("ERROR(ділення на 0)");
    return y / sqrt(pow(x, 2) + pow(y, 2));
}

double sin2(int x, int y)
{
    if (x == 0 && y == 0)
        throw exception("ERROR(ділення на 0)");
    else 
        if (y / sqrt(pow(x, 2) + pow(y, 2)) < -1 || y / sqrt(pow(x, 2) + pow(y, 2)) > 1)
            throw runtime_error("ERROR(Синус лежить в межах (-1;1))");
        else
            return y / sqrt(pow(x, 2) + pow(y, 2));
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    z number;
    z_peretvorene chuslo;
    cout << "Введіть дійсну частину\t";
    cin >> number.real;
    cout << "Введіть уявну частину\t";
    cin >> number.imag;
    chuslo.radius = sqrt(pow(number.real, 2) + pow(number.imag, 2));
    cout << "radius=\t" << chuslo.radius << endl;
    double cos_a = cos(number.real, number.imag);
    if (number.real != 0 && number.imag != 0 && (number.real / sqrt(pow(number.real, 2) + pow(number.imag, 2)) < -1 || number.real / sqrt(pow(number.real, 2) + pow(number.imag, 2)) > 1))
        cout << cos_a << endl;
    try
    {
        double sin_a = sin(number.real, number.imag);
        cout << sin_a<<endl;
    }
    catch (const char* message)
    {
        cout << message << endl;
    }

    try {
        double sin2_a = sin2(number.real, number.imag);
        cout << sin2_a << endl;
    }
    catch (const runtime_error error)
    {
        cout << "Runtime_error: " << error.what() << endl;
    }
    catch (const exception error)
    {
        cout << "Exception: " << error.what() << endl;
    }
    if (number.real != 0 && number.imag != 0 && (number.real / sqrt(pow(number.real, 2) + pow(number.imag, 2)) < -1 || number.real / sqrt(pow(number.real, 2) + pow(number.imag, 2)) > 1))
    {
        chuslo.angle = acos(cos_a);
        cout << "angle=\t" << chuslo.angle;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
