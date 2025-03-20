#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "red_black_tree.h"

int main(int argc, char* argv[]) {
    // read input file name from argv[1]
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];

    size_t pos = inputFile.find_last_of(".");
    std::string baseName;
    if (pos != std::string::npos) {
        baseName = inputFile.substr(0, pos);
    } else {
        baseName = inputFile;
        inputFile += ".txt";
    }
    std::string outputFile = baseName + "_output_file.txt";
    std::ofstream outFile(outputFile, std::ios::out);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << outputFile << std::endl;
        return 1;
    }

    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << inputFile << std::endl;
        return 1;
    }

    RedBlackTree rbt;

    // read input file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string command;
        std::getline(ss, command, '(');

        if (command == "addLicence") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            if (plateNum.size() > 0) {
                // remove double quotes
                plateNum.erase(plateNum.find_first_of('"'), 1);  // remove leading double quote
                plateNum.erase(plateNum.find_last_of('"'), 1);   // remove trailing double quote
                if (rbt.addLicense(plateNum)) {
                    outFile << plateNum << " registered successfully." << std::endl;
                } else {
                    outFile << "Failed to register " << plateNum << ": already exists."
                            << std::endl;
                }
            } else {
                outFile << rbt.addLicense() << " created and registered successfully." << std::endl;
            }
        } else if (command == "dropLicense") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            // plateNum.erase(0, 1);  // remove leading space
            // plateNum.erase(plateNum.find_last_not_of(" \n\r\t") + 1);  // remove trailing
            // whitespace
            std::cout << "Dropping license: " << plateNum << std::endl;
        } else if (command == "lookupLicense") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum.erase(0, 1);                                      // remove leading space
            plateNum.erase(plateNum.find_last_not_of(" \n\r\t") + 1);  // remove trailing whitespace
            std::cout << "Looking up license: " << plateNum << std::endl;
        } else if (command == "lookupPrev") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum.erase(0, 1);                                      // remove leading space
            plateNum.erase(plateNum.find_last_not_of(" \n\r\t") + 1);  // remove trailing whitespace
            std::cout << "Looking up previous license: " << plateNum << std::endl;
        } else if (command == "lookupNext") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum.erase(0, 1);                                      // remove leading space
            plateNum.erase(plateNum.find_last_not_of(" \n\r\t") + 1);  // remove trailing whitespace
            std::cout << "Looking up next license: " << plateNum << std::endl;
        } else if (command == "lookupRange") {
            std::string lo, hi;
            std::getline(ss, lo, ',');
            lo.erase(0, 1);                                // remove leading space
            lo.erase(lo.find_last_not_of(" \n\r\t") + 1);  // remove trailing whitespace
            std::getline(ss, hi, ')');
            hi.erase(0, 1);                                // remove leading space
            hi.erase(hi.find_last_not_of(" \n\r\t") + 1);  // remove trailing whitespace
            std::cout << "Looking up range: " << lo << " to " << hi << std::endl;
        } else if (command == "revenue") {
            std::cout << "Calculating revenue" << std::endl;
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }

    file.close();

    rbt.printTree();
}