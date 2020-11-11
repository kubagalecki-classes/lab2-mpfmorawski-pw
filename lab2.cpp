#include <iostream>

class Wektor
{

public:
    Wektor() : dlugosc{0}, pojemnosc{0}
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

    Wektor(const Wektor& W)
    {
        std::cout << "Konstruktor kopiujacy wektora.\n";
        double* temp;
        temp = new double[W.dlugosc];
        for (int i = 0; i < W.dlugosc; i++)
            temp[i] = W.vector[i];

        vector       = temp;
        double temp0 = temp[0];
        delete[] temp;
        vector[0] = temp0;

        dlugosc   = W.dlugosc;
        pojemnosc = W.pojemnosc;
    }

    Wektor& operator=(const Wektor& W)
    {
        std::cout << "Kopiujacy operator przypisania wektora.\n";
        if (this != &W) {
            double* temp;
            temp = new double[W.dlugosc];
            for (int i = 0; i < W.dlugosc; i++)
                temp[i] = W.vector[i];

            vector       = temp;
            double temp0 = temp[0];
            delete[] temp;
            vector[0] = temp0;

            dlugosc   = W.dlugosc;
            pojemnosc = W.pojemnosc;
        }
        return *this;
    }

    ~Wektor()
    {
        std::cout << "Destruktor wektora.\n";
        delete[] vector;
    }

    double& operator[](int);

    int getDlugosc() { return dlugosc; }
    int getPojemnosc() { return pojemnosc; }

    void print();
    void zmienDlugosc(int);

private:
    double* vector;
    int     dlugosc;
    int     pojemnosc;
};

double& Wektor::operator[](int i)
{
    if (i >= dlugosc)
        zmienDlugosc(i + 1);

    return vector[i];
}

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
            newvector[i] = 0.;

        vector      = newvector;
        double temp = vector[0];
        delete[] newvector; // UWAGA: po tej linijce również vector[0] = 0
        vector[0] = temp;
        dlugosc   = newLength;
        pojemnosc = newLength;
    }
}

int main()
{
    Wektor Vector1{3};
    for (double i = 0.; i < Vector1.getDlugosc(); i++)
        Vector1[i] = i + 1;
    Vector1.print();

    Wektor Vector2{};
    Vector2.print();

    Vector2 = Vector1 = Vector1;
    Vector2.print();

    std::cout << std::endl;

    Vector2[1] = 5.;
    Vector1.print();
    Vector2.print();

    std::cout << std::endl;

    Vector1[2] = 7.;
    Vector1.print();
    Vector2.print();

    std::cout << std::endl;

    Vector1[5] = 6.;
    Vector1.print();
    Vector2.print();
}

/*
Po wykonaniu otrzymano:
  Konstruktor parametryczny wektora o dlugosci 3.
  [1, 2, 3]
  Konstruktor kopiujacy wektora.
  [1, 2, 3]

  [1, 2, 3]
  [1, 5, 3]

  [1, 2, 7]
  [1, 5, 3]

  [1, 2, 7, 0, 0, 6]
  [1, 5, 3]
  Destruktor wektora.
  Destruktor wektora.
*/