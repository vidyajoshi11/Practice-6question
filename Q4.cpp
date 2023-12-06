#include <iostream>
#include <cstring>

class Personnel {
private:
    char* name;
    char* dateOfBirth;
    char* bloodGroup;
    double height;
    double weight;
    char* insurancePolicy;
    char* contactAddress;
    char* telephoneNumber;
    char* drivingLicense;

public:
    // Constructor to initialize the data
    Personnel(const char* name, const char* dateOfBirth, const char* bloodGroup,
              double height, double weight, const char* insurancePolicy,
              const char* contactAddress, const char* telephoneNumber, const char* drivingLicense)
        : height(height), weight(weight) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->dateOfBirth = new char[strlen(dateOfBirth) + 1];
        strcpy(this->dateOfBirth, dateOfBirth);

        this->bloodGroup = new char[strlen(bloodGroup) + 1];
        strcpy(this->bloodGroup, bloodGroup);

        this->insurancePolicy = new char[strlen(insurancePolicy) + 1];
        strcpy(this->insurancePolicy, insurancePolicy);

        this->contactAddress = new char[strlen(contactAddress) + 1];
        strcpy(this->contactAddress, contactAddress);

        this->telephoneNumber = new char[strlen(telephoneNumber) + 1];
        strcpy(this->telephoneNumber, telephoneNumber);

        this->drivingLicense = new char[strlen(drivingLicense) + 1];
        strcpy(this->drivingLicense, drivingLicense);
    }

    // Destructor to release memory
    ~Personnel() {
        delete[] name;
        delete[] dateOfBirth;
        delete[] bloodGroup;
        delete[] insurancePolicy;
        delete[] contactAddress;
        delete[] telephoneNumber;
        delete[] drivingLicense;
    }

    // Copy constructor
    Personnel(const Personnel& other) : Personnel(other.name, other.dateOfBirth, other.bloodGroup,
                                                 other.height, other.weight, other.insurancePolicy,
                                                 other.contactAddress, other.telephoneNumber,
                                                 other.drivingLicense) {}

    // Function to display personnel information
    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Date of Birth: " << dateOfBirth << std::endl;
        std::cout << "Blood Group: " << bloodGroup << std::endl;
        std::cout << "Height: " << height << " feet" << std::endl;
        std::cout << "Weight: " << weight << " kg" << std::endl;
        std::cout << "Insurance Policy: " << insurancePolicy << std::endl;
        std::cout << "Contact Address: " << contactAddress << std::endl;
        std::cout << "Telephone Number: " << telephoneNumber << std::endl;
        std::cout << "Driving License No.: " << drivingLicense << std::endl;
    }
};

int main() {
    // Create an instance of the Personnel class
    Personnel person("John Doe", "01-01-1990", "A+", 5.9, 70.5,
                     "Policy1234", "123 Street, City", "1234567890", "DL12345");

    // Display personnel information
    person.displayInfo();

    return 0;
}
