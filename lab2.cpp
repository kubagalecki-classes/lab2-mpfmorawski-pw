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

    Wektor(int vec_n) : dlugosc{vec_n}, pojemnosc{vec_n}
    {
        std::cout << "Konstruktor parametryczny wektora o dlugosci " << dlugosc << ".\n";
        vector = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++)
            vector[i] = 0.;
    }

    ~Wektor()
    {
        std::cout << "Destruktor wektora.\n";
        delete[] vector;
    }

    int getDlugosc() { return dlugosc; }
    int getPojemnosc() { return pojemnosc; }

    void print();
    void zmienDlugosc(int);

private:
    int dlugosc;
    int pojemnosc;
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

void Wektor::zmienDlugosc(int newLength)
{
    if (newLength <= pojemnosc) {
        if (newLength < dlugosc) {
            for (int i = newLength; i < dlugosc; i++)
                vector[i] = 0.;
        }
        dlugosc = newLength;
    }
    else {
        double* newvector = new double[newLength];
        for (int i = 0; i < pojemnosc; i++)
            newvector[i] = vector[i];
        delete[] vector;
        for (int i = pojemnosc; i < newLength; i++)
            newvector[i] = 0;
        vector = newvector;
        delete[] newvector;
        dlugosc   = newLength;
        pojemnosc = newLength;
    }
}

int main()
{
    Wektor Vector1{3};
    Vector1.print();
    Vector1.zmienDlugosc(5);
    Vector1.print();
    Vector1.zmienDlugosc(2);
    Vector1.print();
}

/*
Po wykonaniu otrzymano:
  Konstruktor parametryczny wektora o dlugosci 3.
  [0, 0, 0]
  [0, 0, 0, 0, 0]
  [0, 0]
  Destruktor wektora.
*/