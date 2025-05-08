export module foodProduct;

import <vector>;
import <string>;
import <sstream>;
import <iomanip>;

export class FoodProduct
{
private:
    std::string name;
    double price;
    double weight;

public:
    FoodProduct(std::string n, double p, double w) : name(std::move(n)), price(p), weight(w) {}
    ~FoodProduct() = default;

    std::string get_info() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << "Nazwa: " << name
            << ", Cena: " << price << " z³"
            << ", Waga: " << weight << " kg";
        return oss.str();
    }

    double get_price() { return price; }
    void set_price(double p) { price = p; }
};