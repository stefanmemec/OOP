#include <iostream>
#include <cmath>
using namespace std;

class Kompleksenbroj {
    float realen;
    float imaginaren;

public:
    Kompleksenbroj(float r = 0, float i = 0) : realen(r), imaginaren(i) {}

    float getRealen() const { return realen; }
    float getImaginaren() const { return imaginaren; }

    void operator-() {
        realen = -realen;
        imaginaren = -imaginaren;
    }

    Kompleksenbroj operator+(const Kompleksenbroj &c) const {
        return Kompleksenbroj(realen + c.realen, imaginaren + c.imaginaren);
    }

    bool operator==(const Kompleksenbroj &c) const {
        return (realen == c.realen && imaginaren == c.imaginaren);
    }

    Kompleksenbroj& operator=(const Kompleksenbroj &c) {
        if (this != &c) {
            realen = c.realen;
            imaginaren = c.imaginaren;
        }
        return *this;
    }

    Kompleksenbroj operator-(const Kompleksenbroj &c) const {
        return Kompleksenbroj(realen - c.realen, imaginaren - c.imaginaren);
    }

    void operator~() {
        imaginaren = -imaginaren;
    }

    Kompleksenbroj operator/(const Kompleksenbroj &c) const {
        float imenitel = c.realen * c.realen + c.imaginaren * c.imaginaren;
        return Kompleksenbroj((realen * c.realen + imaginaren * c.imaginaren) / imenitel,
                             (imaginaren * c.realen - realen * c.imaginaren) / imenitel);
    }

    bool operator!=(const Kompleksenbroj &c) const {
        return (realen != c.realen || imaginaren != c.imaginaren);
    }

    Kompleksenbroj& operator++() {
        ++realen;
        ++imaginaren;
        return *this;
    }

    Kompleksenbroj operator++(int) {
        Kompleksenbroj temp = *this;
        ++(*this);
        return temp;
    }

    Kompleksenbroj& operator--() {
        --realen;
        --imaginaren;
        return *this;
    }

    Kompleksenbroj operator--(int) {
        Kompleksenbroj temp = *this;
        --(*this);
        return temp;
    }

    float operator!() const {
        return sqrt(realen * realen + imaginaren * imaginaren);
    }

    Kompleksenbroj operator*(const Kompleksenbroj &c) const {
        return Kompleksenbroj(realen * c.realen - imaginaren * c.imaginaren,
                             realen * c.imaginaren + imaginaren * c.realen);
    }

    void vnesi() {
        cin >> realen >> imaginaren;
    }

    void pecati() const {
        if (imaginaren > 0) cout << realen << "+" << imaginaren << "i";
        else if (imaginaren == 0) cout << realen;
        else cout << realen << imaginaren << "i";
    }
};

int main() {
    Kompleksenbroj x, y, z;
    cout << "Vnesete  kompleksen broj: ";
    x.vnesi();
    cout << "prv kompleksen broj: ";
    x.pecati();
    cout << endl;
    -x;
    cout << "negativen broj: ";
    x.pecati();
    cout << endl;
    
    cout << "vtor kompleksen broj: ";
    y.vnesi();
    cout << endl;
    z = y + x;
    cout << "zbir: ";
    z.pecati();
    cout << endl;
    
    cout << (x == x ? "ednakvi" : "ne ednakvi") << endl;
    
    z = x;
    ~z;
    ++z;
    cout << "Smenet: ";
    z.pecati();
    cout << endl;
    
    cout << "Koren: " << !x << endl;
    return 0;
}
