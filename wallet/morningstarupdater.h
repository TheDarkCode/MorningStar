#ifndef MORNINGSTARUPDATER_H
#define MORNINGSTARUPDATER_H

#include <string>

#include "version.h"
#include "clientversion.h"
#include "morningstarversion.h"
#include "morningstarreleaseinfo.h"

#include "curltools.h"

class MorningStarUpdater
{

public:
    static const std::string ClientVersionSrcFileLink;
    static const std::string ReleasesInfoURL;
    static const std::string LatestReleaseURL;

    MorningStarUpdater();
    void checkIfUpdateIsAvailable(boost::promise<bool> &updateIsAvailablePromise, MorningStarReleaseInfo &lastRelease);

    static MorningStarVersion ParseVersion(const std::string& versionFile);
    static std::string GetDefineFromCFile(const std::string& fileData, const std::string &fieldName);
    static std::string RemoveCFileComments(const std::string& fileData);
};

struct RemovePreReleaseFunctor
{
    bool operator() (const MorningStarReleaseInfo& r)
    {
        return r.getIsPreRelease();
    }
};

struct MorningStarReleaseVersionGreaterComparator
{
    bool operator() (const MorningStarReleaseInfo& r1, const MorningStarReleaseInfo& r2)
    {
        return r1.getVersion() > r2.getVersion();
    }
};


#endif // MORNINGSTARUPDATER_H
