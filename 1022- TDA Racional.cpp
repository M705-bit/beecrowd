
#include <iostream>
#include <cstring>
using namespace std;

class CustomDivision {
public:
    int numerador;
    int denominador;

    CustomDivision(int num, int den) : numerador(num), denominador(den) {}

    void soma(const CustomDivision& obj1, const CustomDivision& obj2) {
        if (obj1.denominador == 0 || obj2.denominador == 0) {
            cout << "Error: Division by zero!" << endl;
        } else {
            int base = obj1.denominador * obj2.denominador;
            int topo = (obj1.numerador * obj2.denominador) + (obj2.numerador * obj1.denominador);
            simplifica(base, topo);
        }
    }

    void simplifica(int& base, int& topo) {
        int i = 2, base1 = base, topo1 = topo;
        while (i <= base1 && i <= topo1) {
            if (base1 % i == 0 && topo1 % i == 0) {
                base1 = base1 / i;
                topo1 = topo1 / i;
            } else {
                i++;
            }
        }

        cout << topo << " / " << base << " = " << topo1 << " / " << base1 << endl;
    }
};

int main() {
    int n1, n2, d1, d2;

    const char* s = "1 / 2 + 3 / 4";

    // Use sscanf with the correct format string
    sscanf(s, "%d / %d + %d / %d", &n1, &d1, &n2, &d2);

    CustomDivision obj1(n1, d1), obj2(n2, d2);
    obj1.soma(obj1, obj2);

    return 0;
}
