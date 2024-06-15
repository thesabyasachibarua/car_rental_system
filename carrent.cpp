#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;
    bool isRented;

    Car(string b, string m, int y) : brand(b), model(m), year(y), isRented(false) {}

    void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year;
        if (isRented)
            cout << " (Rented)";
        cout << endl;
    }
};

class CarRentalSystem {
private:
    vector<Car> cars;

public:
    void addCar(string brand, string model, int year) {
        cars.push_back(Car(brand, model, year));
    }

    void rentCar() {
        displayAvailableCars();
        cout << "Enter the number of the car you want to rent: ";
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= cars.size() && !cars[choice - 1].isRented) {
            cars[choice - 1].isRented = true;
            cout << "You have rented the car: ";
            cars[choice - 1].displayInfo();
        } else {
            cout << "Invalid choice or car already rented." << endl;
        }
    }

    void returnCar() {
        displayRentedCars();
        cout << "Enter the number of the car you want to return: ";
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= cars.size() && cars[choice - 1].isRented) {
            cars[choice - 1].isRented = false;
            cout << "You have returned the car: ";
            cars[choice - 1].displayInfo();
        } else {
            cout << "Invalid choice or car not rented." << endl;
        }
    }

    void displayAvailableCars() {
        cout << "Available cars:" << endl;
        for (size_t i = 0; i < cars.size(); ++i) {
            if (!cars[i].isRented) {
                cout << i + 1 << ". ";
                cars[i].displayInfo();
            }
        }
    }

    void displayRentedCars() {
        cout << "Rented cars:" << endl;
        for (size_t i = 0; i < cars.size(); ++i) {
            if (cars[i].isRented) {
                cout << i + 1 << ". ";
                cars[i].displayInfo();
            }
        }
    }
};

int main() {
    CarRentalSystem system;
    system.addCar("Toyota", "Corolla", 2020);
    system.addCar("Honda", "Civic", 2019);
    system.addCar("Ford", "Mustang", 2021);
    system.addCar("Dodge","camaro", 2022);

    int choice;
    do {
        cout << "\nCar Rental System" << endl;
        cout << "1. Display available cars" << endl;
        cout << "2. Rent a car" << endl;
        cout << "3. Return a car" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayAvailableCars();
                break;
            case 2:
                system.rentCar();
                break;
            case 3:
                system.returnCar();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
