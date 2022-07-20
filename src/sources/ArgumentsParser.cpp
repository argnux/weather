#include "ArgumentsParser.hpp"

ArgumentsParser::ArgumentsParser(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++) {
        mArgs.insert(argv[i]);
    }
}

bool ArgumentsParser::isSet(const std::string& str) const
{
    return mArgs.find(str) != mArgs.end();
}
