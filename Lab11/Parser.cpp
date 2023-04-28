#include <iostream>
#include <cctype>
#include "Parser.h"


Parser::Parser(const std::string &string) : currentIndex(0) {
    stringParse = string;
    std::erase(stringParse, ' ');
}

void Parser::parseS() {
    parseExpr();
    if (currentIndex != stringParse.size()) {
        error();
    }
}

void Parser::parseExpr() {
    parseTerm();
    parseAdds();
}

void Parser::parseAdds() {
    if (currentIndex == stringParse.size()) {
        std::cout << "epsilon" << std::endl;
        return;
    }
    if (stringParse[currentIndex] == '+') {
        std::cout << "+ <Expr>" << std::endl;
        currentIndex++;
        parseExpr();
    } else if (stringParse[currentIndex] == '-') {
        std::cout << "- <Expr>" << std::endl;
        currentIndex++;
        parseExpr();
    } else {
        std::cout << "epsilon" << std::endl;
    }
}

void Parser::parseTerm() {
    if (std::isalpha(stringParse[currentIndex])) {
        std::cout << "IDENT" << std::endl;
        while (currentIndex < stringParse.size() && (std::isalpha(stringParse[currentIndex])
                                                     || std::isdigit(stringParse[currentIndex]))) {
            currentIndex++;
        }
    } else if (std::isdigit(stringParse[currentIndex])) {
        std::cout << "NUMBER" << std::endl;
        while (currentIndex < stringParse.size() && std::isdigit(stringParse[currentIndex])) {
            currentIndex++;
        }
    } else if (stringParse[currentIndex] == '(') {
        std::cout << "(<Expr>)" << std::endl;
        currentIndex++;
        parseExpr();
        if (stringParse[currentIndex] == ')') {
            currentIndex++;
        } else {
            error();;
        }
    } else {
        error();
    }
}

void Parser::error() {
    std::cout << "syntax error at (line 1, col " << currentIndex << ")" << std::endl;
    exit(-1);
}
