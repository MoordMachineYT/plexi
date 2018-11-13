#ifndef OBJECT_WRAP_H
#define OBJECT_WRAP_H

#include <string>
#include <map>
#include <memory>

namespace plexi {
    using std::string;
    using std::map;
    using std::shared_ptr;
    
    // Map initializer
    class Object {
    public:
        virtual string* ToString();
    };
    
    class ObjectWrap {
    public:
        string constructor;
        map<string, shared_ptr<Object>>* values; // heap
        ObjectWrap(string = "Object");
        string* ToString();
        bool HasOwnProperty(string&);
        void SetProp(string&, Object*);
        bool DeleteProp(string&);
    };
}

#endif /* OBJECT_WRAP_H */
