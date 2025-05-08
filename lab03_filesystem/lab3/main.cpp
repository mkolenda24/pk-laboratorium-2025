#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Zadanie 1: Sprawdzenie istnienia katalogu i jego utworzenie, jeœli nie istnieje
void checkOrCreateDirectory(const std::string& path) {
    fs::path dir_path(path);
    if (fs::exists(dir_path)) {
        std::cout << "Katalog " << path << " ju¿ istnieje." << std::endl;
    }
    else {
        fs::create_directories(dir_path);
        std::cout << "Katalog " << path << " zosta³ utworzony." << std::endl;
    }
}

// Zadanie 2: Wyœwietlenie zawartoœci katalogu
void printDirectoryInfo(const std::string& path) {
    fs::path dirPath(path);
    if (!fs::exists(dirPath)) {
        std::cout << "Katalog nie istnieje." << std::endl;
        return;
    }

    std::cout << "Zawartoœæ katalogu:\n";
    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (fs::is_directory(entry)) {
            std::cout << "[DIR] " << entry.path().filename().string() << std::endl;
        }
        else if (fs::is_regular_file(entry)) {
            auto size = fs::file_size(entry);
            std::cout << "[FILE] " << entry.path().filename().string()
                << " (rozmiar: " << size << " B)" << std::endl;
        }
    }
}

// Zadanie 3: Kopiowanie pliku, jeœli nie istnieje w katalogu docelowym
void copyFileIfNotExists(const std::string& src, const std::string& dest) {
    fs::path srcPath(src);
    fs::path destPath(dest);

    if (!fs::exists(srcPath)) {
        std::cerr << "B³¹d! Plik Ÿród³owy nie istnieje." << std::endl;
        return;
    }

    if (fs::exists(destPath)) {
        std::cout << "Plik docelowy ju¿ istnieje: " << dest << std::endl;
    }
    else {
        fs::copy_file(srcPath, destPath);
        std::cout << "Plik zosta³ skopiowany do: " << dest << std::endl;
    }
}

// Zadanie 4: Usuwanie pliku lub katalogu
void deleteDirOrFile(const std::string& path) {
    fs::path target(path);

    if (!fs::exists(target)) {
        std::cerr << "B³¹d! Œcie¿ka nie istnieje." << std::endl;
        return;
    }

    if (fs::is_regular_file(target)) {
        fs::remove(target);
        std::cout << "Plik " << path << " zosta³ usuniêty." << std::endl;
    }
    else if (fs::is_directory(target)) {
        fs::remove_all(target);
        std::cout << "Katalog " << path << " zosta³ usuniêty." << std::endl;
    }
}

// Zadanie 5: Liczenie plików w katalogu i podkatalogach
int countFiles(const std::string& path) {
    fs::path dirPath(path);
    if (!fs::exists(dirPath)) {
        std::cerr << "B³¹d! Katalog nie istnieje." << std::endl;
        return 0;
    }

    int count = 0;
    for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
        if (fs::is_regular_file(entry)) {
            count++;
        }
    }
    std::cout << "Liczba plików w katalogu i podkatalogach: " << count << "\n";
    return count;
}

int main() {
    std::string dir = "katalog";
    std::string dir2 = "katalog2";
    std::string copy_file = "katalog/png1.png";
    int count;

    checkOrCreateDirectory(dir);  // Zadanie 1
    printDirectoryInfo(dir);  // Zadanie 2
    copyFileIfNotExists(copy_file, "katalog2/usmiech.png");  // Zadanie 3
    deleteDirOrFile("katalog2/usmiech.png");  // Zadanie 4
    count = countFiles("icons");  // Zadanie 5

    return 0;
}
