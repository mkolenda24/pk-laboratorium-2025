#include <iostream>
#include <regex>
#include <string>
#include <map>

void check(const std::string email) {
	std::regex pattern("[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,3}");

	if (std::regex_match(email, pattern)) {
		std::cout << "email jest poprawny" << std::endl;
	}
	else {
		std::cout << "email jest niepoprawny" << std::endl;
	}

}

void hide(std::string tekst) {
	std::regex pattern("[a-zA-Z0-9]+@");
	std::string result;
	result = std::regex_replace(tekst, pattern, "anonimowy@");
	tekst = result;
	std::cout << tekst << std::endl;
}

void search(std::string tekst) {
	std::regex pattern("([a-zA-Z0-9]+@)([a-zA-Z0-9]+\\.[a-zA-Z]{2,3})");
	std::smatch matches;
	std::map<std::string, int> counter;

	std::cout << "znalezione maile:" << std::endl;
	while (std::regex_search(tekst, matches, pattern)) {
		std::string fullEmail = matches[0];
		std::string domain = matches[2];

		for (char& c : domain) c = tolower(c);

		counter[domain]++;

		std::cout << "- " << fullEmail << std::endl;
		tekst = matches.suffix().str();
	}

	std::cout << std::endl << "wystapienia domen:" << std::endl;
	for (const auto& [domain, count] : counter) {
		std::cout << "- " << domain << ": " << count << " wystapien\n";
	}

}

int main()
{
	std::cout << "zadanie 1:" << std::endl;
	std::string email = "michal@gmail.pl";
	check(email);
	std::string tekst = "Kontakt: kowalski@o2.com, dsadas@gmailcom, marcin@interia.pl, PIOtr.Pl, info@uni.edu, admin@rzad.GOV, @spoko.pl, test@gmail.COM, user@GMail.com, pawel@.DE";
	std::cout << std::endl << "zadanie 2" << std::endl;
	std::cout << "tekst przed uktryciem:" << std::endl << tekst << std::endl << "tekst po ukryciu:" << std::endl;
	hide(tekst);
	std::cout << std::endl << "zadanie 3 i 4:" << std::endl;
	search(tekst);
}