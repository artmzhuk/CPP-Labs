#include "Parser.h"

int main(){
    Parser p ("a + 10 - (x - 1)");
    p.parseS();
}