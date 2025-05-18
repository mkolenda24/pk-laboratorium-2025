#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <concepts>
#include <iterator>

template<typename T>
concept IsIterable = requires(T a) {
    { std::begin(a) } -> std::input_iterator;
    { std::end(a) } -> std::sentinel_for<decltype(std::begin(a))>;
};

template<typename T>
concept HasModAndEquality = requires(T a) {
    { a % 2 } -> std::same_as<T>;
    { a == 0 } -> std::convertible_to<bool>;
};

template<typename T>
concept IsStreamInsertable = requires(std::ostream & os, T a) {
    { os << a } -> std::same_as<std::ostream&>;
};

template<IsIterable Container>
    requires HasModAndEquality<typename Container::value_type>&&
IsStreamInsertable<typename Container::value_type>
void print_even(const Container& container) {
    for (const auto& element : container) {
        if (element % 2 == 0) {
            std::cout << element << " ";
        }
    }
    std::cout << std::endl;
}

template<typename Container>
    requires IsIterable<Container>&&
HasModAndEquality<typename Container::value_type>&&
IsStreamInsertable<typename Container::value_type>
class EvenPrinter {
public:
    void print(const Container& container) const {
        for (const auto& element : container) {
            if (element % 2 == 0) {
                std::cout << element << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::list<int> lst = { 6, 7, 8, 9, 10 };
    std::array<int, 5> arr = { 11, 12, 13, 14, 15 };

    std::cout << "Using print_even function:" << std::endl;
    print_even(vec);
    print_even(lst);
    print_even(arr);

    std::cout << "Using EvenPrinter class:" << std::endl;
    EvenPrinter<std::vector<int>> printerVec;
    printerVec.print(vec);

    EvenPrinter<std::list<int>> printerLst;
    printerLst.print(lst);

    EvenPrinter<std::array<int, 5>> printerArr;
    printerArr.print(arr);

    //std::vector<std::string> invalid = { "a", "b", "c", "d"};
    //print_even(invalid); // B³¹d kompilacji

    return 0;
}