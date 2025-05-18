# Laboratorium 3 – Zarz¹dzanie plikami i katalogami w C++20

Projekt z zakresu operacji na plikach i katalogach w jêzyku C++. Program umo¿liwia wykonywanie ró¿nych operacji na plikach i katalogach, takich jak: tworzenie katalogów, wyœwietlanie zawartoœci, kopiowanie plików, usuwanie plików/katalogów oraz liczenie plików.

## Funkcje programu

1. **Sprawdzanie i tworzenie katalogu**  
   Funkcja sprawdza, czy katalog istnieje, a jeœli nie, tworzy go.

2. **Wyœwietlanie zawartoœci katalogu**  
   Funkcja wyœwietla wszystkie pliki i katalogi w zadanym katalogu.

3. **Kopiowanie pliku**  
   Funkcja kopiuje plik do katalogu docelowego, jeœli ten plik jeszcze nie istnieje.

4. **Usuwanie pliku lub katalogu**  
   Funkcja usuwa wskazany plik lub katalog.

5. **Liczenie plików w katalogu i podkatalogach**  
   Funkcja liczy liczbê plików w zadanym katalogu i wszystkich jego podkatalogach.

## Przyk³ad u¿ycia

```cpp
 std::string dir = "katalog";
    std::string dir2 = "katalog2";
    std::string copy_file = "katalog/png1.png";
    int count;

    checkOrCreateDirectory(dir);  // Zadanie 1
    printDirectoryInfo(dir);  // Zadanie 2
    copyFileIfNotExists(copy_file, "katalog2/usmiech.png");  // Zadanie 3
    deleteDirOrFile("katalog2/usmiech.png");  // Zadanie 4
    count = countFiles("katalog");  // Zadanie 5
```