#include "AssetReader.h"

namespace isopatric::file {

    std::string AssetReader::readFileToString(const std::string &filePath) {
        std::ifstream file{filePath};
        if (!file) {
            LOG_ERROR("Could not open file {}", filePath);
            return "";
        }

        std::stringstream ss;
        ss << file.rdbuf();
        file.close();

        return ss.str();
    }

    std::string AssetReader::readBinary(const std::string &filePath) {
        std::string result;
        std::ifstream file{filePath, std::ios::binary};
        if (!file) {
            LOG_ERROR("Could not open file {}", filePath);
            return result;
        }

        file.seekg(0, std::ios::end);
        result.resize(file.tellg());
        file.seekg(0, std::ios::beg);

        file.read(&result[0], result.size());
        file.close();

        return result;
    }
}