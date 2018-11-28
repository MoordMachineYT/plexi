#include "object_wrap.h"

using namespace plexi;

using std::pair;

ObjectWrap::ObjectWrap(Object* constructor) {
    this->values = new map<string, shared_ptr<Object>>;
    this->constructor = constructor;
}

string* ObjectWrap::ToString() {
    string* str = new string(this->constructor + " {");
    bool newline = false;
    for(auto it = this->values->begin(); it != this->values->end(); it++) {
        newline = true;
        Object* obj = it->second.get();
        str->append("\n  ");
        str->append(it->first);
        str->append(": ");
        str->append(obj != nullptr ? *obj->ToString() : "null");
    }
    if(newline) {
        str->append("\n");
    }
    str->append("}");
    return str;
}

bool ObjectWrap::HasOwnProperty(string& prop) {
    auto values = this->values;
    return values->find(prop) != values->end();
}

void ObjectWrap::SetProp(string& prop) {
    this->values->insert(pair<string, shared_ptr<Object>>(prop, shared_ptr<Object>(this->constructor)));
}

bool ObjectWrap::DeleteProp(string& prop) {
    auto it = this->values->find(prop);
    if(it == this->values->end()) {
        return false;
    }
    this->values->erase(prop);
    return true;
}
