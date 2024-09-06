#include "utils.h"
#include <string>

std::string getFileExtension(const std::string &filePath) {
    return filePath.substr(filePath.find_last_of(".") + 1);
}
