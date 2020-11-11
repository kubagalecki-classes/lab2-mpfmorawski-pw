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

    void print();

private:
    int dlugosc;
};

void Wektor::print()
{
    std::cout << "[";
    for (int i = 0; i < (dlugosc - 1); i++)
        std::cout << vector[i] << ", ";
    if (dlugosc > 0)
        std::cout << vector[dlugosc - 1];
    std::cout << "]" << std::endl;
}

int main()
{
    Wektor Vector1{2};
    Wektor Vector2{};
    Vector1.print();
    Vector2.print();
}

/*
Po wykonaniu otrzymano:
  Konstruktor parametryczny wektora o dlugosci 2.
  Konstruktor domyslny wektora.
  [0, 0]
  []
  Destruktor wektora.
  Destruktor wektora.
*/