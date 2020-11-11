#include <iostream>

// Przeciążenie nr 1, zwykła referencja
void print_int(const int& i)
{
    std::cout << "Ref: " << i << '\n';
}

// Przeciążenie nr 2, RVR
/*
void print_int(int&& i)
{
    std::cout << "RVR: " << i << '\n';
}
*/

int getInt()
{
    return 42;
}

int main()
{
    int liczba = 314159; // liczba to lvalue

    print_int(liczba);   // przeciążenie 1
    print_int(getInt()); // przeciążenie 2
    print_int(13);       // przeciążenie 2, bo '13' to rvalue
}