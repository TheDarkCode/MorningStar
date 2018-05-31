#ifndef MORNINGSTARUPDATEDIALOG_H
#define MORNINGSTARUPDATEDIALOG_H

#include <QDialog>
#include <QTextBrowser>
#include <QGridLayout>
#include <QLabel>

#include "morningstarupdater.h"

class MorningStarUpdateDialog : public QDialog
{
    Q_OBJECT

    QLabel* currentVersionTitleLabel;
    QLabel* currentVersionContentLabel;
    QLabel* remoteVesionTitleLabel;
    QLabel* remoteVesionContentLabel;
    QTextBrowser* updateInfoText;
    QGridLayout*  mainLayout;
    QLabel* downloadLinkLabel;

    void setRemoteVersion(const QString& version);
    void setCurrentVersion(const QString& version);
    void setBodyText(const QString& bodyText);
    void setDownloadLink(const QString& link);

public:
    explicit MorningStarUpdateDialog(QWidget *parent = 0);

    void setUpdateRelease(const MorningStarReleaseInfo &rel);

signals:

public slots:
};

#endif // MORNINGSTARUPDATEDIALOG_H
