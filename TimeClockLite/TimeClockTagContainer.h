#ifndef TIMECLOCKTAGCONTAINER_H
#define TIMECLOCKTAGCONTAINER_H

#include <QVector>
#include <QTime>
#include <QMutex>



class TimeClockTagContainer
{
public:
    struct TimeTag
    {
        int tag;
        QTime time;
    };

    TimeClockTagContainer();

    TimeTag& operator[](int i);

    void AddTag(int tag, const QTime &time);
    int RemoveTag(int tag);
    int Count() const;

private:
    QVector<TimeTag> mElements;
    QMutex mMutex;
    bool mAutoSort;
};

#endif // TIMECLOCKTAGCONTAINER_H
