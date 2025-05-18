# Lab 7 � Koncepty w C++20

## Temat

U�ycie koncept�w w funkcjach i klasach szablonowych w j�zyku C++20.

## Zadanie

Napisz funkcj� szablonow� `print_even`, kt�ra:

- przyjmuje kontener (np. `std::vector`, `std::list`, `std::array`),
- wypisuje tylko **parzyste elementy**.

### Warunki:

- Kontener musi by� iterowalny (`begin()`, `end()`),
- Typ elementu musi wspiera�:
  - operator `%` i `==`,
  - operator `<<` dla `std::ostream`.

## Wymagania

1. Zdefiniuj trzy koncepty:
   - `IsIterable<T>` � sprawdza `begin()` i `end()`,
   - `HasModAndEquality<T>` � sprawdza `%` i `== 0`,
   - `IsStreamInsertable<T>` � sprawdza mo�liwo�� wypisania przez `<<`.

2. U�yj r�nych styl�w definicji:
   - `requires(...)` w nag��wku,
   - `requires { ... }` w ciele,
   - po��czenie koncept�w typu `std::same_as`, `std::input_iterator`.

3. Zaimplementuj `print_even` jako:
   - funkcj� wolnostoj�c�,
   - metod� klasy szablonowej `EvenPrinter`.

4. Przetestuj na:
   - `std::vector<int>`,
   - `std::list<int>`,
   - `std::array<int, N>`.

5. Dodaj przyk�ad, kt�ry nie przejdzie (np. `std::vector<std::string>`).

## Przyk�ad u�ycia

```cpp
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::list<int> lst = { 6, 7, 8, 9, 10 };
    std::array<int, 5> arr = { 11, 12, 13, 14, 15 };

    std::cout << "Using print_even function:" << std::endl;
    print_even(vec);
    print_even(lst);
    print_even(arr);

    std::cout << "Using EvenPrinter class:" << std::endl;
    EvenPrinter<std::vector<int>> printerVec;
    printerVec.print(vec);

    EvenPrinter<std::list<int>> printerLst;
    printerLst.print(lst);

    EvenPrinter<std::array<int, 5>> printerArr;
    printerArr.print(arr);

