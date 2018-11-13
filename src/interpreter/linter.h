#ifndef LINTER_H
#define LINTER_H

#include <vector>
#include <string>
#include <map>

#include "token.h"

using std::vector;
using std::string;
using std::map;

namespace plexi {
namespace linter {
    typedef struct {
        bool noInput;
        bool syntax;
        bool reference;
        bool type;
    } LintError;
    vector<string> split_at(string&, char);
    void trim(string&);
    LintError lint(string&, map<string, Token>&);
    void removeComments(vector<string>&);
}
}

#endif /* LINTER_H */
