#include "reader.h"
#include <unistd.h>

using namespace plexi;

Reader::Reader(string file, bool external) {
    this->file_info.name = file;
    this->reading = false;
    this->file_info.external = external;
}

void Reader::Read() {
    string path = getcwd(NULL, 0);
    path.append(this->file_info.name);
    this->reader.open(path);
    if(this->reader.good()) {
        this->reading = true;
    } else {
        return;
    }
    string lib;
    string s;
    while(getline(this->reader, s)) {
        this->file_info.bytes_read += s.length();
        lib.append(s);
    }
    this->content = (&lib);
}
