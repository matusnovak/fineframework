#include <ffw/math.h>
#include <ffw/data.h>
#include <cassert>
#include <iostream>

int main() {

    //! [example0]
    ffw::CsvLoader loader;

    // First param: file path
    // Second param: delimiter (some CSV use ;) default: ,
    // Third param: how are string represented? default: "
    if(!loader.openFromFile("file.csv", ',', '\"')){
        std::cerr << "File failed to open!" << std::endl;
        assert(false);
    }
    else {
        while(!loader.eof()){
            // If getRow(true) is used with false, it will not perform
            // any type conversion and everything will be parsed as string
            ffw::Array row = loader.getRow(true);

            assert(row.size() == 4);

            for(ffw::Any var : row) {
                if(var.isBool()) {
                    std::cout << var.toBool();
                }
                else if(var.isFloat()) {
                    std::cout << var.toFloat();
                }
                else if(var.isInt()) {
                    std::cout << var.toInt();
                }
                else if(var.empty()) {
                    std::cout << "NULL";
                }
                else {
                    std::cout << var.toString();
                }
                std::cout << ",";
            }
            std::cout << std::endl;
        }
    }
    //! [example0]

    //! [example1]
    std::string str = "1999;Chevy;\"Venture \"\"Extended Edition, Very Large\"\"\";;5000.00";
    ffw::Array arr = ffw::CsvLoader::tokenize(str, 0, str.size(), true, ';', '\"');

    assert(arr.size() == 5);

    assert(arr[0].toInt() == 1999);
    assert(arr[2].toString() == "Venture \"Extended Edition, Very Large\"");
    assert(arr[3].empty() == true);
    //! [example1]

    return 0;
}
