/*
 *  Copyright (c) Evgeny Proydakov <lord.tiran@gmail.com> 2011
 */

#ifndef __V_TESTING_ROBOT_FACADE_H
#define __V_TESTING_ROBOT_FACADE_H

#include <QPointF>
#include <QStringList>

namespace PlayerCc
{
class PlayerClient;
class Position2dProxy;
}

const int DEFAULT_PORT = 6665;
const QString DEFAULT_HOST = "localhost";

class VTestingRobotFacade
{
public:
    VTestingRobotFacade();
    ~VTestingRobotFacade();

    bool connectToDevices(qint32 port = DEFAULT_PORT, const QString& hostName = "localhost");
    void disconnectFromDevices( );

    bool setSpeed(qreal velocity, qreal omega);
    bool getSpeed(qreal &velocity, qreal &omega);
    bool getPosition(QPointF &point, qreal &phi);

private:
    PlayerCc::PlayerClient *m_playerClient;
    PlayerCc::Position2dProxy *m_position2dProxy;

    QString m_hostName;
    qint32 m_port;
};

#endif /* __V_TESTING_ROBOT_FACADE_H */
