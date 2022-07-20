#pragma once

#include <unordered_set>
#include <string>

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char* argv[]);
    bool isSet(const std::string& str) const;

private:
    std::unordered_set<std::string> mArgs;
};
