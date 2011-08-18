/*
 *  Copyright (c) 2011 Evgeny Proydakov <lord.tiran@gmail.com>
 */

#include <string.h>
#include <cmath>

#include <QtGui/QApplication>
#include <QLineF>
#include <QDebug>

#include <v_player_config.h>
#include <v_player_process.h>
#include <v_testing_robot_facade.h>

#define msleep(msec) usleep(msec * 1000)

int getRandomDirection()
{
    return qrand() % 2 == 0 ? 1 : -1;
}

class ObjectIsCrash
{
public:
    ObjectIsCrash(uint crashIteration) : m_crashIteration(crashIteration), m_iteration(0), m_lastPoint(0, 0), m_lastPhi(0) {}

    bool isCrash(QPointF& point, qreal phi)
    {
        qreal deltaPos = QLineF(point, m_lastPoint).length();
        qreal deltaP = fabs(phi - m_lastPhi);

        m_lastPoint = point;
        m_lastPhi = phi;

        if(deltaPos < minimumDeltaPosition && deltaP < minimumDeltaPhi) {
            ++m_iteration;
        }
        else {
            m_iteration = 0;
        }
        if(m_iteration >= m_crashIteration) {
            m_iteration = 0;
            qDebug() << "ROBOT CRASHED";
            return true;
        }
        return false;
    }

private:
    static const qreal minimumDeltaPosition = 0.0001;
    static const qreal minimumDeltaPhi = 0.0001;

private:
    uint m_crashIteration;
    int m_iteration;
    QPointF m_lastPoint;
    qreal m_lastPhi;

};

int main( int argc, char *argv[] )
{
    QApplication a(argc, argv);
    Q_UNUSED(a);

    QString worldName(PLAYER_POLYGON_WORLD_CONFIG_FILE);
    VPlayerProcess* process = new VPlayerProcess(worldName);

    msleep(3600);

    VTestingRobotFacade* facade = new VTestingRobotFacade;
    facade->connectToDevices();

    qreal velocity = 1.9;
    qreal omega = 2.9;
    const int num = 50000;

    QPointF point;
    qreal phi;

    ObjectIsCrash robotIsStuck(5);

    for(int i = 1; i < num; ++i) {
        facade->setSpeed(velocity, 0);
        facade->getPosition( point, phi );
        if(robotIsStuck.isCrash(point, phi)) {
            qDebug() << "ROBOT IS STUCK !!!" << i;
            velocity *= getRandomDirection();
            facade->setSpeed(velocity, omega * getRandomDirection());
            usleep(300000);
            facade->setSpeed(velocity, 0);
        }
        usleep(100);
    }

    delete facade;
    delete process;

    return 1;
}
