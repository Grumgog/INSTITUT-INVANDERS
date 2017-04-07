#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

#include "UserClass/player.h"
#include "UserClass/enemy.h"
#include "UserClass/paintobjectabstract.h"
#include "UserClass/bullet.h"
#include "UserClass/statusmanager.h"
#include "helping.h"


#include <vector>
#include <stdlib.h>
#include <time.h>

const double ort = 11.0d;

namespace Ui {
class Widget;
}

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    //----Методы opengl окна----
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    //--------------------------
    void timerEvent(QTimerEvent* te);
    void mouseMoveEvent(QMouseEvent* me);
    void mousePressEvent(QMouseEvent* me);


    ~Widget();

private:
    double xg, yg;
    std::vector<PaintObjectAbstract*> paintVector;
    std::vector<Enemy*> EnemyVector;
    std::vector<Bullet*> BulletVector;
    SM::StatusManager* ST;
    Player* player;
    double coef;
    int idShootEnemyTimer;
    Ui::Widget *ui;
};

#endif // WIDGET_H
