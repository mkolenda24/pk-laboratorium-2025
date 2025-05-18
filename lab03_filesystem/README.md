# Laboratorium 3 � Zarz�dzanie plikami i katalogami w C++20

Projekt z zakresu operacji na plikach i katalogach w j�zyku C++. Program umo�liwia wykonywanie r�nych operacji na plikach i katalogach, takich jak: tworzenie katalog�w, wy�wietlanie zawarto�ci, kopiowanie plik�w, usuwanie plik�w/katalog�w oraz liczenie plik�w.

## Funkcje programu

1. **Sprawdzanie i tworzenie katalogu**  
   Funkcja sprawdza, czy katalog istnieje, a je�li nie, tworzy go.

2. **Wy�wietlanie zawarto�ci katalogu**  
   Funkcja wy�wietla wszystkie pliki i katalogi w zadanym katalogu.

3. **Kopiowanie pliku**  
   Funkcja kopiuje plik do katalogu docelowego, je�li ten plik jeszcze nie istnieje.

4. **Usuwanie pliku lub katalogu**  
   Funkcja usuwa wskazany plik lub katalog.

5. **Liczenie plik�w w katalogu i podkatalogach**  
   Funkcja liczy liczb� plik�w w zadanym katalogu i wszystkich jego podkatalogach.

## Przyk�ad u�ycia

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