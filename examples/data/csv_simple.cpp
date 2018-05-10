#include <ffw/math.h>
#include <ffw/data.h>
#include <cassert>
#include <iostream>

int main() {

    //! [example0]
    // Make sure the lines are separated by \n !!!
    std::string str =
        "Year,Make,Model,length\n"
        "1997,Ford,E350,2.34\n"
        "2000,Mercury,Cougar,2.38\n";

    ffw::Array arr = ffw::decodeCsv(str);
    // ffw::Array arr = ffw::decodeCsvFile("file.csv");

    if(arr.size() == 0) {
        std::cerr << "Failed to open CSV!" << std::endl;
        assert(false);
    }

    // Returns the number of lines in csv
    assert(arr.size() == 3);

    // Returns the number of columns using the first row
    assert(arr[0].getAsArray().size() == 4);
        
    // Returns Mercury
    assert(arr[2].getAsArray()[1].toString() == "Mercury");

    // Returns 1997
    assert(arr[1].getAsArray()[0].toInt() == 1997);
    //! [example0]

    return 0;
}
