#include <iostream>

class Wektor
{

public:
    double* vector;

    Wektor() : dlugosc{0}
    {
        std::cout << "Konstruktor domyslny wektora.\n";
        vector = new double[0];
    }

    Wektor(int vec_n) : dlugosc{vec_n}
    {
        std::cout << "Konstruktor parametryczny wektora o dlugosci " << dlugosc << ".\n";
        vector = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++)
            vector[i] = 0;
    }

    int getDlugosc() { return dlugosc; }

    ~Wektor()
    {
        std::cout << "Destruktor wektora.\n";
        delete[] vector;
    }

private:
    int dlugosc;
};

int main()
{
    Wektor Vector1{2};
    Wektor Vector2{};
    std::cout << Vector1.getDlugosc() << std::endl;
    std::cout << Vector2.getDlugosc() << std::endl;
    std::cout << "Ostatnia linia kodu w main.\n";
}
