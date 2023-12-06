#include <iostream>
#include <iomanip>

class WeatherReport {
private:
    int day_of_month;
    int high_temp;
    int low_temp;
    double amount_rain;
    double amount_snow;

public:
    // Constructor with default values
    WeatherReport()
        : day_of_month(99), high_temp(999), low_temp(-999), amount_rain(0), amount_snow(0) {}

    // Function to set values for each field
    void setWeatherData() {
        std::cout << "Enter day of the month: ";
        std::cin >> day_of_month;

        std::cout << "Enter high temperature: ";
        std::cin >> high_temp;

        std::cout << "Enter low temperature: ";
        std::cin >> low_temp;

        std::cout << "Enter amount of rain: ";
        std::cin >> amount_rain;

        std::cout << "Enter amount of snow: ";
        std::cin >> amount_snow;
    }

    // Function to display the weather report
    void displayReport() {
        std::cout << "\nWeather Report for Day " << day_of_month << ":\n";
        std::cout << "---------------------------------\n";
        std::cout << "High Temperature: " << high_temp << "F\n";
        std::cout << "Low Temperature: " << low_temp << "F\n";
        std::cout << "Amount of Rain: " << amount_rain << " inches\n";
        std::cout << "Amount of Snow: " << amount_snow << " inches\n";
        std::cout << "---------------------------------\n";
    }
};

int main() {
    WeatherReport monthlyReport[31]; // Assuming maximum 31 days in a month
    int choice;

    do {
        std::cout << "\nMonthly Weather Report\n";
        std::cout << "1. Enter Data for a Day\n";
        std::cout << "2. Display Report for a Day\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int day;
                std::cout << "Enter day of the month (1-31): ";
                std::cin >> day;
                if (day >= 1 && day <= 31) {
                    monthlyReport[day - 1].setWeatherData();
                    std::cout << "Data entered for day " << day << std::endl;
                } else {
                    std::cout << "Invalid day entered!\n";
                }
                break;
            }
            case 2: {
                int day;
                std::cout << "Enter day of the month to display report: ";
                std::cin >> day;
                if (day >= 1 && day <= 31) {
                    monthlyReport[day - 1].displayReport();
                } else {
                    std::cout << "Invalid day entered!\n";
                }
                break;
            }
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter again.\n";
        }
    } while (choice != 3);

    return 0;
    }
