/* This file is part of FineFramework project */
#ifndef FFW_DATA_HELPERS
#define FFW_DATA_HELPERS

#include <string>
#include "../config.h"

namespace ffw {
    /**
    * @ingroup data
    */
    bool FFW_API stringContainsWhitespace(std::string::const_iterator begin, std::string::const_iterator end);
    /**
    * @ingroup data
    */
    bool FFW_API stringisInteger(std::string::const_iterator begin, std::string::const_iterator end);
    /**
    * @ingroup data
    */
    bool FFW_API stringisFloat(std::string::const_iterator begin, std::string::const_iterator end);
    /**
    * @ingroup data
    */
    bool FFW_API stringisBool(std::string::const_iterator begin, std::string::const_iterator end);
};

#endif