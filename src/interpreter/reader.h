#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <map>

using std::string;
using std::ifstream;
using std::map;

namespace plexi {
    typedef struct {
        bool strict;
        size_t bytes_read;
        string name;
        bool external;
    } FileInfo;
    
    class Reader {
    public:
        FileInfo file_info;
        ifstream reader;
        bool reading;
        string* content;
        Reader(string, bool = false);
        void Read();
    };
}

#endif /* READER_H */
