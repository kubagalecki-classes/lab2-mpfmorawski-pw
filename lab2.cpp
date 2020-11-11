#include <iostream>

struct Kokardka
{
    // Kokardka() { dlugosc = 42; }
    Kokardka(int d) { dlugosc = d; }

    int dlugosc;
};

struct Prezent
{
    Prezent(int dk)
    {
        std::cout << k.dlugosc << std::endl;
        k.dlugosc = dk;
        std::cout << k.dlugosc << std::endl;
    }

    Kokardka k;
};

int main()
{
    Prezent Prezent1{11};
}