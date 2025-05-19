#include <iostream>
#include <thread>
#include <future>

//zad1
long long sumRange(int start, int end) {
	long long suma = 0;
	for (int i = start; i <= end; i++) {
		suma += i;
	}
	return suma;
}

//zad2
unsigned long long factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

//zad3
void square(std::future<int> future) {
	int value = future.get();
	int square = value * value;
	std::cout << "Kwadrat liczby " << value << " to: " << square << std::endl;
}


int main() {
	//zad1
	int start = 1;
	int end = 1000000;

	std::future<long long> futureSum = std::async(std::launch::async, sumRange, start, end);
	std::cout << "Suma liczb od " << start << " do " << end << " wynosi: " << futureSum.get() << std::endl;

	//zad2
	int number = 54;
	std::packaged_task<unsigned long long(int)> task(factorial);
	std::future<unsigned long long> result = task.get_future();
	std::thread t(std::move(task), number);

	std::cout << number << "! = " << result.get() << std::endl;
	t.join();

	//zad3 
	int number2;
	std::cout << "Podaj liczbe calkowita: ";
	std::cin >> number2;

	std::promise<int> promise;
	std::future<int> future = promise.get_future();

	std::thread t1(square, std::move(future));
	promise.set_value(number);
	t1.join();

	return 0;
}