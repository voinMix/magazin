#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    float price;
    string description;
    int stock;

    Product(string n, float p, string d, int s) {
        name = n;
        price = p;
        description = d;
        stock = s;
    }
};

class Store {
public:
    string name;
    vector<Product> products;

    Store(string n) {
        name = n;
    }

    void addProduct(string n, float p, string d, int s) {
        Product newProduct(n, p, d, s);
        products.push_back(newProduct);
    }

    void showProducts() {
        cout << "Products available in " << name << ":" << endl;
        for (int i = 0; i < products.size(); i++) {
            cout << products[i].name << " - " << products[i].price << "$" << endl;
        }
    }

    bool buyProduct(int index) {
        if (index >= 0 && index < products.size() && products[index].stock > 0) {
            products[index].stock--;
            cout << "You bought a " << products[index].name << " for " << products[index].price << "$" << endl;
            return true;
        }
        cout << "Sorry, this product is out of stock." << endl;
        return false;
    }
};

int main() {
    Store myStore("My Store");
    myStore.addProduct("Apple", 1.0, "Fresh and juicy", 5);
    myStore.addProduct("Banana", 0.5, "Yellow and sweet", 10);
    myStore.addProduct("Orange", 1.5, "Rich in vitamin C", 3);

    myStore.showProducts();
    myStore.buyProduct(0);
    myStore.buyProduct(0);
    myStore.buyProduct(0);
    myStore.buyProduct(0);
    myStore.buyProduct(0);
    myStore.buyProduct(0);

    return 0;
}