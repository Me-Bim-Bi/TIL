//
// Created by Chu Ha Thanh on 2024-12-16.
//

#ifndef GENERIC_FUNC_H
#define GENERIC_FUNC_H

//template funktion. Man ligger allt på header fil, behöver inte deklarerar det i .cpp filer, annars det når inte koden på .cpp filen. Det gäller bara för funktion mall, klassmall blah blah.
template <typename T>
T add(T a, T b);

template <typename T>
T add(T a, T b) {
	return a + b;
}

template <typename T1, typename T2, typename T3>
T3 add(T1 a, T2 b);

template <typename T1, typename T2, typename T3>
T3 add(T1 a, T2 b) {
	return a + b;
}




#endif //GENERIC_FUNC_H
