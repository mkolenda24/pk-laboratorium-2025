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

## Przykładowe dane wejściowe

```text
Kontakt: kowalski@o2.com, dsadas@gmailcom, marcin@interia.pl, PIOtr.Pl, info@uni.edu,
admin@rzad.GOV, @spoko.pl, test@gmail.COM, user@GMail.com, pawel@.DE