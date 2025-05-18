#include <thread>
#include <atomic>
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>

//zad1
void inc(std::atomic<int>& liczba, int ile) {
    for (int i = 0; i < ile; ++i) {
        ++liczba;
    }
    std::cout << "aktualna wartosc: " << liczba.load() << std::endl;
}

//zad2
constexpr int ROZMIAR = 10;
int dane = 0;
std::mutex mtx_dane;
std::condition_variable cv1;

void producent() {
    for (int i = 0; i < 15; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::unique_lock<std::mutex> lock(mtx_dane);
        cv1.wait(lock, [] { return dane < ROZMIAR; });

        ++dane;
        std::cout << "[producent] wyprodukowano. liczba danych: " << dane << std::endl;
        cv1.notify_one();
    }
    std::cout << "[producent] zakonczono produkcje.\n";
}

void konsument() {
    for (int i = 0; i < 15; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::unique_lock<std::mutex> lock(mtx_dane);
        cv1.wait(lock, [] { return dane > 0; });

        --dane;
        std::cout << "[konsument] skonsumowano. liczba danych: " << dane << std::endl;
        cv1.notify_one();
    }
    std::cout << "[konsument] zakonczono konsumpcje.\n";
}

std::mutex mtx;
std::condition_variable cv2;
int etap = 0;

void A() {
    for (int i = 0; i < 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv2.wait(lock, [] { return etap == 0 || etap == 2; });

        std::cout << "A";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        if (etap == 0)
            etap = 1;
        else
            etap = 3;

        cv2.notify_all();
    }
}

void C() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv2.wait(lock, [] { return etap == 1; });

        std::cout << "C";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        etap = 2;
        cv2.notify_all();
    }
}

void B() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv2.wait(lock, [] { return etap == 3; });

        std::cout << "B\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        etap = 0;
        cv2.notify_all();
    }
}

int main() {

    //zad1 
    std::atomic<int> liczba{ 0 };

    std::thread t1(inc, std::ref(liczba), 30000);
    std::thread t2(inc, std::ref(liczba), 70000);

    t1.join();
    t2.join();

    std::cout << "ostateczna watrosc: " << liczba.load() << std::endl;

    //zad2

    std::thread tt1(producent);
    std::thread tt2(konsument);

    tt1.join();
    tt2.join();

    //zad3

    std::jthread watekA(A);
    std::jthread watekB(B);
    std::jthread watekC(C);

    return 0;
}