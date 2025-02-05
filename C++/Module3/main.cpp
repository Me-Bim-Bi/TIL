#include <iostream>

#include "EggPackage.h"
#include "Milk.h"
#include "Product.h"

int main()
{
    Product product1;
    cout << product1.getDescription() << endl;

    Product product2(123.45, "B123");
    cout << product2.getDescription() << endl;

    Milk Arla(100, "B234", 1.5);
    cout << Arla.getDescription() << endl;

    EggPackage Skåne(40.5, "T0112", "M", 15);
    cout << Skåne.getDescription() << endl;

    Milk ABC(10, "M123");
    EggPackage XYZ;
    cout << ABC.getDescription() << endl;
    cout << XYZ.getDescription() << endl;

    Milk test;
    test.addMilk(100, "M123", 3);
    test.addMilk(120, "B234", 5);
    cout << "print out test" << test.getDescriptionArray() << endl;
    return 0;
}
