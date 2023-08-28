#include <iostream>
#include <fstream>
#include <sstream>

struct data_entries
{
    int serial_num,year;
    double int_rate,inflation_rate;
};

int main(){
    std::ifstream document("india_data.csv");
if(!document.is_open())
{
   std::cerr<<"Failed to open the file "<<std::endl;
}

    const int max_data_entries = 100;
data_entries data[max_data_entries];
int data_entries_count=0;

std::string store_line;
while(std::getline(document,store_line)  && data_entries_count<max_data_entries)
{
     std::istringstream iss(store_line);
        char comma;

if(iss>> data[ data_entries_count].serial_num >>comma>> data[ data_entries_count].year>> comma>> data[ data_entries_count].int_rate>> comma>> data[ data_entries_count].inflation_rate)
{
    data_entries_count++;
}

else
{
    std::cerr<<"failed to read the file"<<store_line<<std::endl;

}
}
if (iss >> data[dataCount].serialnum >> comma >> data[dataCount].year >> comma >> data[dataCount].interestRate >> comma >> data[dataCount].inflationRate) {
           dataCount++;
        } else {
            std::cerr << "Failed to parse line: " << line << std::endl;
        }
    }

document.close();
return 0;
for (int i = 1; i < data_entries_count; i++) {
        std::cout <<"Serial num: " << data[i].serial_num <<",Year: " << data[i].year << ", Interest Rate: " << data[i].int_rate << ", Inflation Rate: " << data[i].inflation_rate << std::endl;
    }
}

