#include "linter.h"
#include "token.h"

#include <regex>

using namespace plexi;

using std::regex;
using std::regex_match;
using std::regex_replace;
using std::smatch;

regex method_match_no_default("\\bmdef\\s+[A-Za-z]\\w*\\s*\(((\\s*[A-Za-z]\\w*\\s+[A-Za-z]\\w*\\s*,)*\\s*[A-Za-z]\\w*\\s+[A-Za-z]\\w*)?\\s*\\)\\s*:\\s*\\{");
regex method_match_with_default("\\bmdef\\s+[A-Za-z]\\w*\\s*\(((\\s*[A-Za-z]\\w*\\s+[A-Za-z]\\w*\\s*(=\\s*([^,\\s;]\\s*)+)?,)*\\s*[A-Za-z]\\w*\\s+[A-Za-z]\\w*\\s*(=\\s*([^,\\s\\);]\\s*)+)?)?\\s*\\)\\s*:\\s*\\{");
regex variable_match("\\bdef\\s+[A-Za-z]\\w*\\s*((\\(.*\\)\\s*[A-Za-z]\\w*)|(=[^;]+));");
regex class_match("\\bcdef\\s+[A-Za-z]\\w*\\s*\\{");

vector<string> linter::split_at(string& code, char divisor) {
    vector<string> vec;
    string a;
    for(char s: code) {
        a.push_back(s);
        if(s == divisor) {
            vec.push_back(a);
            a = "";
        }
    }
    if(a != "") {
        vec.push_back(a);
    }
    return vec;
}

void linter::trim(string& str) {
    while(str[0] == ' ' || str[0] == '\n' || str[0] == '\t' || str[0] == '\r') {
        str.erase(0, 1);
    }
    size_t len = str.length() - 1;
    while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t' || str[len] == '\r') {
        str.erase(str.length() - 1, 1);
    }
}

linter::LintError linter::lint(string& str, map<string, Token>&) {
    vector<string> expectedScopeDeclarations;
    LintError err;
    vector<string> vec = split_at(str, ';');
    if(vec.size() == 0) {
        err.noInput = true;
        return err;
    }
    smatch match;
    for(string line: vec) {
        trim(line);
    }
    return err;
}
