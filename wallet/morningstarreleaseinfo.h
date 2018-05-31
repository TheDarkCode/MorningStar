#ifndef MORNINGSTARRELEASEINFO_H
#define MORNINGSTARRELEASEINFO_H

#include "json_spirit.h"
#include "morningstarversion.h"

#include <string>

class MorningStarReleaseInfo
{
    std::string versionStr;
    MorningStarVersion version;
    std::string htmlURL;
    std::string bodyText;
    bool isPreRelease;

    static std::string GetStrField(const json_spirit::Object& data, const std::string& fieldName);
    static bool GetBoolField(const json_spirit::Object &data, const std::string &fieldName);
    static MorningStarVersion VersionTagStrToObj(std::string VersionStr);
    static MorningStarReleaseInfo ParseSingleReleaseData(const json_spirit::Object& data);

public:
    MorningStarReleaseInfo();

    static std::vector<MorningStarReleaseInfo> ParseAllReleaseDataFromJSON(const std::string& data);
    bool getIsPreRelease() const;
    MorningStarVersion getVersion() const;
    std::string getUpdateDescription() const;
    std::string getDownloadLink() const;
    void clear();
};


#endif // MORNINGSTARRELEASEINFO_H
