#include <iostream>
#include <cmath>

using namespace std;

class EquilateralTriangle {
private:
    float a;
    float circumference;
    float area;
public:
    void SetA(float length) {
        a = length;

        circumference = a * 3;
        area = (sqrt(3) * a * a) / 4;
    }

    friend void PrintResults(const EquilateralTriangle&);
    friend class Homework;
};

void PrintResults(const EquilateralTriangle& et) {
    cout << "circumference = " << et.circumference << endl;
    cout << "area = " << et.area << endl;
}

class Homework {
public:
    static void PrintResults(const EquilateralTriangle& et) {
        cout << "circumference = " << et.circumference << endl;
        cout << "area = " << et.area << endl;
    }
};

int main()
{
    EquilateralTriangle et;
    et.SetA(3);

    PrintResults(et);
    Homework::PrintResults(et);

    system("pause>null");
}