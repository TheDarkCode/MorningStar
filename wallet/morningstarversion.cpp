#include "morningstarversion.h"
#include "util.h"
#include "clientversion.h"

#include <stdexcept>

void MorningStarVersion::checkInitialization()
{
    if(major < 0 || minor < 0 || revision < 0 || build < 0)
        throw std::runtime_error("MorningStarVersion object is not initialized.");
}

MorningStarVersion::MorningStarVersion(int Major, int Minor, int Revision, int Build)
{
    major = Major;
    minor = Minor;
    revision = Revision;
    build = Build;
}

bool MorningStarVersion::operator>(const MorningStarVersion &rhs)
{
    checkInitialization();
    if(this->major > rhs.major)
        return true;
    else if(this->major < rhs.major)
        return false;

    if(this->minor > rhs.minor)
        return true;
    else if(this->minor < rhs.minor)
        return false;

    if(this->revision > rhs.revision)
        return true;
    else if(this->revision < rhs.revision)
        return false;

    if(this->build > rhs.build)
        return true;
    else if(this->build < rhs.build)
        return false;

    return false;
}

bool MorningStarVersion::operator<(const MorningStarVersion &rhs)
{
    return (!(*this > rhs) && !(*this == rhs));
}

bool MorningStarVersion::operator>=(const MorningStarVersion &rhs)
{
    return !(*this < rhs);
}

bool MorningStarVersion::operator<=(const MorningStarVersion &rhs)
{
    return !(*this > rhs);
}

bool MorningStarVersion::operator==(const MorningStarVersion &rhs)
{
    return (major    == rhs.major &&
            minor    == rhs.minor &&
            revision == rhs.revision &&
            build    == rhs.build);
}

bool MorningStarVersion::operator!=(const MorningStarVersion &rhs)
{
    return !(*this == rhs);
}

std::string MorningStarVersion::toString()
{
    return ToString(major)    + "." +
           ToString(minor)    + "." +
           ToString(revision) + "." +
           ToString(build);

}

void MorningStarVersion::clear()
{
    *this = MorningStarVersion();
}

void MorningStarVersion::setMajor(int value)
{
    major = value;
}

void MorningStarVersion::setMinor(int value)
{
    minor = value;
}

void MorningStarVersion::setRevision(int value)
{
    revision = value;
}

void MorningStarVersion::setBuild(int value)
{
    build = value;
}

int MorningStarVersion::getMajor() const
{
    return major;
}

int MorningStarVersion::getMinor() const
{
    return minor;
}

int MorningStarVersion::getRevision() const
{
    return revision;
}

int MorningStarVersion::getBuild() const
{
    return build;
}

MorningStarVersion MorningStarVersion::GetCurrentMorningStarVersion()
{
    return MorningStarVersion(CLIENT_VERSION_MAJOR,
                         CLIENT_VERSION_MINOR,
                         CLIENT_VERSION_REVISION,
                         CLIENT_VERSION_BUILD);
}
