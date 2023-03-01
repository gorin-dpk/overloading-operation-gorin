#include <iostream>

using namespace std;

enum Car
{
    GAZ_21 = 1,
    RAF_10,
    GAZ_69,
    ZAZ_965,
    GAZ_13,
    ZIL_111,
    ZIL_118,
    RAF_118
};

Car operator+(const Car& a, const int& b)
{
    Car c = Car(b + a);

    return (c = Car(c%8));
}
Car operator+(const int& b, const Car& a)
{
    return a + b;
}

Car operator++(Car& a)
{
    return (a = Car(a + 1));
}
Car operator++(Car& a, int)
{
    Car c = a; a = Car(a + 1);
    return c;
}

void print(const Car& m)
{
    string Cars[8] =
    {
        "ГАЗ-21", "РАФ-10", "ГАЗ-69", "ЗАЗ-965",
        "ГАЗ-13", "ЗИЛ-111", "ЗИЛ-118", "РАФ-118"
    };
    cout << Cars[m] << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Car c = GAZ_21;
    print(c + 1);
    print(1 + c);
    print(operator+(c, 1));
    print(operator+(2, c));
    c++;
    print(c);
    print(++c);
    print(operator++(c));
    print(operator++(c, 0));
    print(c);

    system("pause");
}
