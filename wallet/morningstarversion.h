#ifndef MORNINGSTARVERSION_H
#define MORNINGSTARVERSION_H

#include <string>

//TODO: Sam: Write unit tests for this class's comparators
class MorningStarVersion
{
    int major;
    int minor;
    int revision;
    int build;
    void checkInitialization();

public:
    MorningStarVersion(int Major = -1, int Minor = -1, int Revision = -1, int Build = -1);
    bool operator>(const MorningStarVersion& rhs);
    bool operator<(const MorningStarVersion& rhs);
    bool operator>=(const MorningStarVersion& rhs);
    bool operator<=(const MorningStarVersion& rhs);
    bool operator==(const MorningStarVersion& rhs);
    bool operator!=(const MorningStarVersion& rhs);
    std::string toString();
    void clear();

    void setMajor(int value);
    void setMinor(int value);
    void setRevision(int value);
    void setBuild(int value);

    int getMajor() const;
    int getMinor() const;
    int getRevision() const;
    int getBuild() const;

    static MorningStarVersion GetCurrentMorningStarVersion();
};

#endif // MORNINGSTARVERSION_H
