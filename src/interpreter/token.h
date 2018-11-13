#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

#include "../objects/object_wrap.h"

using std::string;

namespace plexi {
    class Token {
    public:
        string type;
        Object* value;
        bool constant;
        Token(string, Object*, bool);
    };
}

#endif /* TOKENIZER_H */
