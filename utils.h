#ifndef UTILS_H
#define UTILS_H

#include <string>

inline std::string getFileExtension(const std::string &filePath) {
    return filePath.substr(filePath.find_last_of(".") + 1);
}

#endif
