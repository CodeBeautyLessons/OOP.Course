#include <iostream>

using namespace std;

class Instrument {
public:
    virtual void MakeSound() = 0;
};

class Accordion : public Instrument {
public:
    void MakeSound() {
        cout << "Accordion playing...\n";
    }
};

class Piano : public Instrument {
public:
    void MakeSound() {
        cout << "Piano playing...\n";
    }
};

int main()
{
    Instrument* i1 = new Accordion();
    i1->MakeSound();

    Instrument* i2 = new Piano();
    i1->MakeSound();

    Piano pi;


    Instrument* Instruments[2] = { i1, i2 };

    for (auto i : Instruments) {
        i->MakeSound();
    }

    return 0;
}
