# Laboratorium 2 – Analiza i ukrywanie adresów e-mail (C++17 + regex)

Projekt stworzony w ramach zajęć laboratoryjnych z programowania w C++.  
Program przetwarza tekst zawierający adresy e-mail w celu ich analizy i ukrywania nazw użytkowników.

## Funkcje programu

1. **Walidacja e-maila**  
   Sprawdza, czy podany adres e-mail jest poprawny według zadanego wzorca.

2. **Ukrywanie nazw użytkowników**  
   Zamienia część przed @ na „anonimowy”, np.:  
   `jan.kowalski@example.com` → `anonimowy@example.com`

3. **Wyszukiwanie poprawnych e-maili**  
   Wypisuje wszystkie poprawne adresy e-mail z tekstu, pomijając błędne.

4. **Zliczanie domen**  
   Zlicza liczbę wystąpień każdej domeny w znalezionych adresach (bez rozróżniania wielkości liter).

## Przykład użycia

```cpp
	std::cout << "zadanie 1:" << std::endl;
	std::string email = "michal@gmail.pl";
	check(email);
	std::string tekst = "Kontakt: kowalski@o2.com, dsadas@gmailcom, marcin@interia.pl, PIOtr.Pl, info@uni.edu, admin@rzad.GOV, @spoko.pl, test@gmail.COM, user@GMail.com, pawel@.DE";
	std::cout << std::endl << "zadanie 2" << std::endl;
	std::cout << "tekst przed uktryciem:" << std::endl << tekst << std::endl << "tekst po ukryciu:" << std::endl;
	hide(tekst);
	std::cout << std::endl << "zadanie 3 i 4:" << std::endl;
	search(tekst);
```

