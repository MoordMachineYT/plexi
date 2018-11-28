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
        Object* constructor;
        map<string, shared_ptr<Object>>* values; // heap
        ObjectWrap(Object);
        string* ToString();
        bool HasOwnProperty(string&);
        void SetProp(string&);
        bool DeleteProp(string&);
    };
}

#endif /* OBJECT_WRAP_H */
