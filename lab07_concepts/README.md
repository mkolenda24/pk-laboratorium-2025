# Lab 7 – Koncepty w C++20

## Temat

U¿ycie konceptów w funkcjach i klasach szablonowych w jêzyku C++20.

## Zadanie

Napisz funkcjê szablonow¹ `print_even`, która:

- przyjmuje kontener (np. `std::vector`, `std::list`, `std::array`),
- wypisuje tylko **parzyste elementy**.

### Warunki:

- Kontener musi byæ iterowalny (`begin()`, `end()`),
- Typ elementu musi wspieraæ:
  - operator `%` i `==`,
  - operator `<<` dla `std::ostream`.

## Wymagania

1. Zdefiniuj trzy koncepty:
   - `IsIterable<T>` – sprawdza `begin()` i `end()`,
   - `HasModAndEquality<T>` – sprawdza `%` i `== 0`,
   - `IsStreamInsertable<T>` – sprawdza mo¿liwoœæ wypisania przez `<<`.

2. U¿yj ró¿nych stylów definicji:
   - `requires(...)` w nag³ówku,
   - `requires { ... }` w ciele,
   - po³¹czenie konceptów typu `std::same_as`, `std::input_iterator`.

3. Zaimplementuj `print_even` jako:
   - funkcjê wolnostoj¹c¹,
   - metodê klasy szablonowej `EvenPrinter`.

4. Przetestuj na:
   - `std::vector<int>`,
   - `std::list<int>`,
   - `std::array<int, N>`.

5. Dodaj przykład, który nie przejdzie (np. `std::vector<std::string>`).

## Przykład u¿ycia

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

