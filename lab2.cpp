#include <iostream>

struct Kokardka
{
    Kokardka(int d) : dlugosc{d} {}

    int dlugosc;
};

struct Prezent
{
    Prezent(int dk) : k{dk} { std::cout << k.dlugosc << std::endl; }

    Kokardka k;
};

int main()
{
    Prezent Prezent1{11};
}