#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function to write data to a CSV file
void writeToCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return;
    }

    // Iterate through each row of data
    for (const auto& row : data) {
        // Iterate through each element of the row
        for (auto it = row.begin(); it != row.end(); ++it) {
            // Write the element to the file
            file << *it;
            // Add a comma if it's not the last element in the row
            if (std::next(it) != row.end()) {
                file << ";";
            }
        }
        // End the row with a new line
        file << std::endl;
    }

    // Close the file
    file.close();

    std::cout << "Data has been written to " << filename << std::endl;
}

int main() {
    // Sample data to write to CSV file
    std::vector<std::vector<std::string>> data = {
        {"Name", "Age", "City"},
        {"John", "25", "New York"},
        {"Alice", "30", "Los Angeles"},
        {"Bob", "35", "Chicago"}
    };

    // Specify the filename
    std::string filename = "output.csv";

    // Write data to the CSV file
    writeToCSV(filename, data);

    return 0;
}
