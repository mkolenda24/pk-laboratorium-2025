# Lab 1 – System zarządzania studentami (Moduły w C++20)

## Opis
Program implementuje prosty system zarządzania studentami z wykorzystaniem modułów w języku C++20. Umożliwia:
- Dodawanie studentów do bazy danych,
- Przypisywanie ocen konkretnemu studentowi,
- Wyświetlanie listy studentów wraz ze średnimi ocen.

## Struktura modułów

### Moduł `student`
Zawiera definicję klasy `Student`:
- **Pola:**
  - `std::string name` – imię studenta,
  - `std::vector<int> grades` – lista ocen.

- **Metody:**
  - `Student(const std::string& name)` – konstruktor,
  - `void addGrade(int grade)` – dodaje ocenę,
  - `double getAverage()` – zwraca średnią ocen,
  - `std::string getName()` – zwraca imię studenta,
  - `double calculateAverage(const std::vector<int>&)` – (prywatna) oblicza średnią ocen.

### Moduł `database`
Zawiera definicję klasy `StudentDatabase`:
- **Pole:**
  - `std::vector<Student> students` – lista studentów.

- **Metody:**
  - `void addStudent(const std::string& name)` – dodaje studenta,
  - `Student* findStudent(const std::string& name)` – znajduje i zwraca wskaźnik do studenta,
  - `void printStudents()` – wypisuje listę studentów i ich średnie ocen.

## Użycie
Program obsługuje interfejs tekstowy:
```
1. Add Student
2. Add grade
3. Display students
4. Exit
```