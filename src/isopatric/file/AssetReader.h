#ifndef ISOPATRIC_ISOPATRIC_FILE_ASSETREADER_H
#define ISOPATRIC_ISOPATRIC_FILE_ASSETREADER_H

namespace isopatric::file {
    class AssetReader {
    public:
        static std::string readFileToString(const std::string &filePath);
        static std::string readBinary(const std::string &filePath);
    };
}

#endif //ISOPATRIC_ISOPATRIC_FILE_ASSETREADER_H
