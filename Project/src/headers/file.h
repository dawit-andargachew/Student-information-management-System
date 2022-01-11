#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>


template <typename ObjType>
class File
{

protected:
    std::string dir;
    std::ifstream inFile;
    std::ofstream outFile;
    std::vector<ObjType>* data;

    static std::vector<std::string> split(const std::string& str, char delimiter) {

        std::vector<std::string> tokens;
        std::string buffer = "";

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == delimiter) {
                tokens.push_back(buffer);
                buffer = "";
            }
            else {
                buffer += str[i];
            }
        }
        tokens.push_back(buffer);
    
        return tokens;
    }


public:
    File(std::string dir, char mode)
        : dir(dir)
    {
        data = new std::vector<ObjType>();

        if (mode == 'r') {

            inFile.open(dir);
            if (inFile.fail()) {
                std::cerr << "Unable to open the file!\n\n";
                exit(1);
            }
        }
        else if (mode == 'w') {
            outFile.open(dir);
            if (inFile.fail()) {
                std::cerr << "Unable to open the file!\n\n";
                exit(1);
            }
        }

        else {
            std::cerr << "Invalid open mode: "<<mode<<"\n\n";
            exit(1);
        }

    }

    virtual std::vector<ObjType>* read() = 0;
    virtual bool write(std::vector<ObjType>* data) = 0;


    virtual ~File() {
        delete data;
    }
};

#endif