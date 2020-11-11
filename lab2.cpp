#include <iostream>

struct Liczba
{
    Liczba(int w) : wartosc{w} {}
    // Liczba(const Liczba& l) : wartosc{l.wartosc} { std::cout << "Konstruktor kopiujacy\n"; }

    int wartosc;
};

int main()
{
    Liczba a{1};
    Liczba b{a};  // W celu konstrukcji b wołamy konstruktor kopiujący z argumentem 'a'
    Liczba c = a; // Tutaj także wołamy konstruktor kopiujący, vide lab. 1
}
