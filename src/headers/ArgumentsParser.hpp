#ifndef ARGUMENTS_PARSER_HPP
#define ARGUMENTS_PARSER_HPP

#include <unordered_set>
#include <string>

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char* argv[]);
    bool isSet(const std::string& str) const;

private:
    std::unordered_set<std::string> mArgs;
};

#endif // ARGUMENTS_PARSER_HPP
