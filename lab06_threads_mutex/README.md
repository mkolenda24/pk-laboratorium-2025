# Lab 6 – Programowanie współbieżne w C++

## Temat

Wykorzystanie wątków, zmiennych atomowych, mutexów oraz zmiennych warunkowych (`std::condition_variable`) w C++.

## Zadanie 1 – Zmienne atomowe i wątki

Zaimplementuj funkcję `inc`, która inkrementuje zmienną typu `std::atomic<int>` z użyciem wielu wątków.

### Wymagania:

- Stwórz dwa wątki, każdy zwiększa zmienną o inną wartość (np. 30 000 i 70 000),
- Po zakończeniu działania wypisz końcową wartość zmiennej.

## Zadanie 2 – Producent i konsument

Zaimplementuj klasyczny problem **producenta-konsumenta** z użyciem:

- `std::mutex`,
- `std::condition_variable`.

### Wymagania:

- Producent dodaje dane (max 10),
- Konsument pobiera dane (min 0),
- Użyj `wait(...)` i `notify_one()` do synchronizacji.

## Zadanie 3 – Sekwencjonowanie wątków: A → C → A → B → A → C ...

Zaimplementuj trzy funkcje:

- `A()` – wypisuje "A",
- `C()` – wypisuje "C",
- `B()` – wypisuje "B".

### Warunki:

- Kolejność wykonywania musi być: A → C → A → B → A → C ..., itd.,
- Zaimplementuj kontrolę przepływu przy pomocy zmiennej `etap` oraz `std::condition_variable`.

## Przykład użycia

```cpp
// Zadanie 1
std::atomic<int> licznik{0};
std::thread t1(inc, std::ref(licznik), 30000);
std::thread t2(inc, std::ref(licznik), 70000);
t1.join();
t2.join();
std::cout << "ostateczna wartosc: " << licznik.load() << std::endl;
```

```cpp
// Zadanie 2
std::thread producentThread(producent);
std::thread konsumentThread(konsument);
producentThread.join();
konsumentThread.join();
```

```cpp
// Zadanie 3
std::jthread A_thread(A);
std::jthread B_thread(B);
std::jthread C_thread(C);
```

