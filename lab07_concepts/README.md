# Lab 7 – Koncepty w C++20

## Temat

Użycie konceptów w funkcjach i klasach szablonowych w języku C++20.

## Zadanie

Napisz funkcję szablonów `print_even`, która:

- przyjmuje kontener (np. `std::vector`, `std::list`, `std::array`),
- wypisuje tylko **parzyste elementy**.

### Warunki:

- Kontener musi być iterowalny (`begin()`, `end()`),
- Typ elementu musi wspierać:
  - operator `%` i `==`,
  - operator `<<` dla `std::ostream`.

## Wymagania

1. Zdefiniuj trzy koncepty:
   - `IsIterable<T>` – sprawdza `begin()` i `end()`,
   - `HasModAndEquality<T>` – sprawdza `%` i `== 0`,
   - `IsStreamInsertable<T>` – sprawdza możliwość wypisania przez `<<`.

2. Użyj różnych stylów definicji:
   - `requires(...)` w nagłówku,
   - `requires { ... }` w ciele,
   - połączenie konceptów typu `std::same_as`, `std::input_iterator`.

3. Zaimplementuj `print_even` jako:
   - funkcję wolnostojącą,
   - metodę klasy szablonowej `EvenPrinter`.

4. Przetestuj na:
   - `std::vector<int>`,
   - `std::list<int>`,
   - `std::array<int, N>`.

5. Dodaj przykład, który nie przejdzie (np. `std::vector<std::string>`).

## Przykład użycia

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
```
