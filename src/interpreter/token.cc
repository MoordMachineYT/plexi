#include "token.h"

using namespace plexi;

Token::Token(string type, Object* obj = nullptr, bool constant = false) {
    this->type = type;
    this->value = obj;
    this->constant = constant;
}
