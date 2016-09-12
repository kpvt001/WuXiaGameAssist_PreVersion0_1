#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QMutex>



class Task : public QObject
{
    Q_OBJECT
public:
    class TaskParam
    {
    public:
        explicit TaskParam(void *param, bool hold = false);
        virtual ~TaskParam();

        inline void Lock(){ mMutex.lock();}
        inline void UnLock() { mMutex.unlock();}
        inline void* Param() {return mParam;}

    private:
        QMutex mMutex;
        void *mParam;
        bool mHoldParam;
    };

    explicit Task(QObject *parent = 0);
    virtual ~Task();

signals:
    void Trigger(TaskParam *info);

public slots:
    //void Start(TaskParam *param = nullptr); // the task will delete the param.
    //void Stop();

protected:
    virtual void RunBody() = 0; // will called by Start.

private:

    TaskParam *mParam;
};

#endif // TASK_H
