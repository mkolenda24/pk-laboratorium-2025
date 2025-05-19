# Lab 5 – Programowanie współbieżne w C++

## Temat

Wykorzystanie mechanizmów `std::async`, `std::packaged_task`, `std::promise` oraz `std::future` w programowaniu współbieżnym w C++.

---

## Zadanie 1 – Asynchroniczne obliczanie sumy

Zaimplementuj funkcję `sumRange`, która oblicza sumę liczb całkowitych z podanego zakresu, a następnie uruchom ją z użyciem `std::async`.

### Wymagania:

- Funkcja przyjmuje dwa argumenty: początek i koniec zakresu,
- Obliczenia wykonują się w tle dzięki `std::async`,
- Po zakończeniu działania wynik jest pobierany przez `future.get()`.

---

## Zadanie 2 – Obliczanie silni z użyciem `std::packaged_task`

Zaimplementuj funkcję `factorial`, która rekurencyjnie oblicza silnię, i uruchom ją w osobnym wątku przy użyciu `std::packaged_task`.

### Wymagania:

- Wykorzystaj `std::packaged_task<unsigned long long(int)>`,
- Uruchom zadanie w nowym wątku,
- Odczytaj wynik przy użyciu `future.get()`.

---

## Zadanie 3 – Komunikacja między wątkami: `std::promise` i `std::future`

Zaimplementuj funkcję, która otrzymuje liczbę całkowitą przez `std::future`, a następnie oblicza i wypisuje jej kwadrat.

### Wymagania:

- Wątek główny ustawia wartość przez `promise.set_value(...)`,
- Drugi wątek odbiera wartość przez `future.get()` i wypisuje wynik.

---

## Przykład użycia

```cpp
// Zadanie 1
auto future_result = std::async(std::launch::async, sumRange, 1, 1000000);
std::cout << "Suma: " << future_result.get() << std::endl;
```

```cpp
// Zadanie 2
std::packaged_task<unsigned long long(int)> task(factorial);
std::future<unsigned long long> result = task.get_future();
std::thread t(std::move(task), 10);
t.join();
std::cout << "10! = " << result.get() << std::endl;
```

```cpp
// Zadanie 3
std::promise<int> prom;
std::future<int> fut = prom.get_future();
std::thread t(print_square, std::move(fut));
prom.set_value(8);
t.join();
```