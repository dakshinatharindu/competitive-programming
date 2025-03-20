#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "red_black_tree.h"

std::string getSubstringBetweenQuotes(const std::string& str) {
    size_t start = str.find_first_of('"');
    size_t end = str.find_last_of('"');

    if (start != std::string::npos && end != std::string::npos && start != end) {
        return str.substr(start + 1, end - start - 1);
    }
    return "";  // Return an empty string if quotes are not found or are invalid
}

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
                plateNum = getSubstringBetweenQuotes(plateNum);
                if (rbt.addLicense(plateNum)) {
                    outFile << plateNum << " registered successfully." << std::endl;
                } else {
                    outFile << "Failed to register " << plateNum << ": already exists."
                            << std::endl;
                }
            } else {
                outFile << rbt.addLicense() << " created and registered successfully." << std::endl;
            }
        } else if (command == "dropLicence") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum = getSubstringBetweenQuotes(plateNum);
            if (rbt.dropLicense(plateNum)) {
                outFile << plateNum << " removed successfully." << std::endl;
            } else {
                outFile << "Failed to remove " << plateNum << ": does not exist." << std::endl;
            }
        } else if (command == "lookupLicence") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum = getSubstringBetweenQuotes(plateNum);
            if (rbt.lookupLicense(plateNum)) {
                outFile << plateNum << " exists." << std::endl;
            } else {
                outFile << plateNum << " does not exist." << std::endl;
            }
        } else if (command == "lookupPrev") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum = getSubstringBetweenQuotes(plateNum);
            std::string prevPlate = rbt.lookupPrev(plateNum);
            outFile << plateNum << "'s prev is " << prevPlate << "." << std::endl;
        } else if (command == "lookupNext") {
            std::string plateNum;
            std::getline(ss, plateNum, ')');
            plateNum = getSubstringBetweenQuotes(plateNum);
            std::string nextPlate = rbt.lookupNext(plateNum);
            outFile << plateNum << "'s next is " << nextPlate << "." << std::endl;
        } else if (command == "lookupRange") {
            std::string lo, hi;
            std::getline(ss, lo, ',');
            std::getline(ss, hi, ')');

            lo = getSubstringBetweenQuotes(lo);
            hi = getSubstringBetweenQuotes(hi);

            std::vector<std::string> plates = rbt.lookupRange(lo, hi);
            outFile << "plate numbers between " << lo << " and " << hi << ": ";
            for (const auto& plate : plates) {
                outFile << plate;
                if (&plate != &plates.back()) {
                    outFile << ", ";
                }
            }
            outFile << "." << std::endl;
        } else if (command == "revenue") {
            outFile << "Current annual revenue is " << rbt.revenue() << " Galleons." << std::endl;
        } else if (command == "quit") {
            break;
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }

    file.close();

    rbt.printTree();
}