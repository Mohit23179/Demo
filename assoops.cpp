#include <iostream>
#include <fstream>
#include <sstream>

struct DataPoint {
    int serialnum;
    int year;
    double interestRate;
    double inflationRate;
};

int main() {
    std::ifstream file("india_data.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    const int maxDataPoints = 100; // Maximum number of data points
    DataPoint data[maxDataPoints]; // Array to store data points
    int dataCount = 0; // Counter for actual data points

    std::string line;
    while (std::getline(file, line) && dataCount < maxDataPoints) {
        std::istringstream iss(line);
        char comma;
        
    if (iss >> data[dataCount].serialnum >> comma >> data[dataCount].year >> comma >> data[dataCount].interestRate >> comma >> data[dataCount].inflationRate) {
           dataCount++;
        } else {
            std::cerr << "Failed to parse line: " << line << std::endl;
        }
    }

    file.close();

    // Now you have loaded the data into the 'data' array up to 'dataCount' data points
    /*for (int i = 0; i < dataCount; ++i) {
        std::cout <<"Serial num: " << data[i].serialnum <<",Year: " << data[i].year << ", Interest Rate: " << data[i].interestRate << ", Inflation Rate: " << data[i].inflationRate << std::endl;
    }*/
    int year;
    int rownum;
    double amount;
    double moneyreceived1;
    double moneyreceived2;
    double amount1;
    double amount2;

    std::cin >> year;
    std::cin >> amount2;    
    amount = amount2;
    for (int i = 0; i < dataCount; ++i) {
            if (year == data[i].year){            
            rownum = i;
        }
    }
    std::cout<<dataCount<<std::endl;
    for(int i = rownum;i< dataCount;i++)
    {
        amount1 = amount*(1 + (data[i].interestRate -data[i].inflationRate)/100);
        std::cout<<amount1<<std::endl;
        amount = amount1;
        }

    
    for(int i = rownum;i< dataCount;i++)
    {
        amount1 = amount2*(1 + (data[rownum].interestRate - data[i].inflationRate)/100);
        std::cout<<"hi"<<amount1<<std::endl;
        amount2 = amount1;
    }

    return 0;
}
