# Laboratorium 4 – Zarz¹dzanie sklepem z produktami spo¿ywczymi (C++20)

Projekt stworzony w ramach zajêæ laboratoryjnych z programowania w C++.  
Program umo¿liwia zarz¹dzanie produktami spo¿ywczymi poprzez operacje takie jak filtrowanie, rabaty oraz sortowanie.

## Funkcje programu

1. **Filtracja produktów**  
   Wyœwietla produkty, których cena jest wy¿sza ni¿ 20 z³.

2. **Rabaty**  
   Aplikacja rabatu 10% na ceny produktów.

3. **Sortowanie**  
   Sortowanie produktów po cenie w porz¹dku rosn¹cym.

## Przyk³ad u¿ycia

```cpp
    // Utworzenie wektora produktów
    std::vector<FoodProduct> products = {
        {"Mleko", 4.50, 1.0},
        {"Chleb", 2.30, 0.5},
        {"Woda", 1.99, 1.5},
        {"Jogurt", 6.99, 0.3},
        {"Baton", 9.50, 0.2},
        {"Kawa", 27.99, 2.0},
        {"Piers z kurczaka", 25.99, 1.0}
    };
    
    // Produkty dro¿sze ni¿ 20 z³
    auto filtered = products | std::ranges::views::filter([](FoodProduct& product) { return product.get_price() > 20; });
    std::cout << "Produkty dro¿sze ni¿ 20 z³:\n";
    for (const auto& product : filtered) {
        std::cout << product.get_info() << "\n";
    }

    // Produkty po rabacie 10%
    auto discounted = products | std::ranges::views::transform([](FoodProduct& product) {
        product.set_price(product.get_price() * 0.9);
        return product;
        });
    std::cout << "\nProdukty po rabacie 10%:\n";
    for (const auto& product : discounted) {
        std::cout << product.get_info() << "\n";
    }

    // Produkty posortowane po cenie
    std::vector<FoodProduct> sorted_products(std::ranges::begin(products), std::ranges::end(products));
    std::ranges::sort(sorted_products, {}, &FoodProduct::get_price);
    std::cout << "\nProdukty posortowane po cenie (rosn¹co):\n";
    for (const auto& product : sorted_products) {
        std::cout << product.get_info() << "\n";
    }
```