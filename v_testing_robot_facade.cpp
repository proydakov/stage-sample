/*
 *  Copyright (c) Evgeny Proydakov <lord.tiran@gmail.com> 2011
 */

#include <libplayerc++/playerc++.h>

#include <QDebug>
#include <QProcess>
#include <QPointF>

#include <v_testing_robot_facade.h>

VTestingRobotFacade::VTestingRobotFacade() :
    m_playerClient(0),
    m_position2dProxy(0),
    m_hostName(DEFAULT_HOST),
    m_port(DEFAULT_PORT)
{
}

VTestingRobotFacade::~VTestingRobotFacade()
{
    if(m_playerClient)
        disconnectFromDevices();
}

bool VTestingRobotFacade::connectToDevices(qint32 port, const QString& hostName)
{
    Q_ASSERT(!m_playerClient);

    m_port = port;
    m_hostName = hostName;

    try {
        m_playerClient = new PlayerCc::PlayerClient(std::string(m_hostName.toAscii()), m_port);
    }
    catch(...) {
    }
    if( m_playerClient ) {
        m_position2dProxy = new PlayerCc::Position2dProxy(m_playerClient);
        m_position2dProxy->SetMotorEnable(true);
        m_playerClient->StartThread();
    }
    return m_playerClient;
}

void VTestingRobotFacade::disconnectFromDevices( )
{
    Q_ASSERT(m_playerClient);
    m_playerClient->StopThread();
    delete m_position2dProxy;
    m_position2dProxy = 0;
    delete m_playerClient;
    m_playerClient = 0;
}

bool VTestingRobotFacade::setSpeed(qreal velocity, qreal omega)
{
    if(m_playerClient)
        m_position2dProxy->SetSpeed(velocity, omega);
    return m_playerClient;
}

bool VTestingRobotFacade::getSpeed(qreal &velocity, qreal &omega)
{
    if(m_playerClient) {
        velocity = m_position2dProxy->GetXSpeed();
        omega = m_position2dProxy->GetYawSpeed();
    }
    return m_playerClient;
}

bool VTestingRobotFacade::getPosition(QPointF &point, qreal &phi)
{
    if(m_playerClient) {
        point.setX(m_position2dProxy->GetXPos());
        point.setY(m_position2dProxy->GetYPos());
        phi = m_position2dProxy->GetYaw();
    }
    return m_playerClient;
}
