/*
 *  Copyright (c) 2011 Evgeny Proydakov <lord.tiran@gmail.com>
 */

#ifndef _V_PLAYER_PROCESS_H
#define _V_PLAYER_PROCESS_H

#include <QProcess>

class QProcess;

class VPlayerProcess
{
public:
    VPlayerProcess(const QString& worldName)
    {
        m_playerProcess = new QProcess;
        m_playerProcess->start("player", QStringList(worldName));
        m_playerProcess->waitForStarted(-1);
    }

    ~VPlayerProcess()
    {
        m_playerProcess->terminate();
        m_playerProcess->waitForFinished(-1);
        delete m_playerProcess;
    }

private:
    VPlayerProcess(const VPlayerProcess&);
    VPlayerProcess& operator = (const VPlayerProcess&);

private:
    QProcess *m_playerProcess;
    QString m_processName;
};

#endif // _V_PLAYER_PROCESS_H

