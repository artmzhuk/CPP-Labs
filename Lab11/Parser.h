#ifndef CPP_LABS_PARSER_H
#define CPP_LABS_PARSER_H
#include <string>

class Parser {
public:
    Parser(const std::string &string);
    void parseS();

private:
    int currentIndex;
    std::string stringParse;
    void parseExpr();
    void parseAdds();
    void parseTerm();
    void error();
};


#endif //CPP_LABS_PARSER_H
