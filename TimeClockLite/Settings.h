#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include <QString>

class Settings : public QObject
{
public:
    Settings(QObject *parent = nullptr);
    static Settings& Global();

    inline bool IsTestMode() const {return mIsTestMode;}
    inline void SetTestMode(bool mode = true) {mIsTestMode = mode;}

private:
    bool mIsTestMode;
};

#endif // SETTINGS_H
