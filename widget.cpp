#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "UserClass/npc.h"

Widget::Widget(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    // Иницилизация объектов игры
    //player = new Player(0x0000FFAA, Point(), 3); // Игрок
    Player::instance(0x0000FFAA,Point(), 3);
    ST = new SM::StatusManager(SM::playScreen); // Менеджер состояний

    setMouseTracking(true); // Начать регистрацию движений мыши
    startTimer(100/6); // Таймер FPS - Frame Per Second - Кадры В Секунду

    idShootEnemyTimer = startTimer(5000); // Враги стреляют по таймеру
    // Иницилизация глобальных переменных
    xg = 0;
    yg = 0;
    coef = 0.0d;
    // Создаем врагов
    for(int i = 1; i<=3; i++)
    {
        for(int j = 1; j<=(10/i);j++)
        {
            EnemyVector.push_back(new Enemy(0x00FF0000, Point(-5+j,10-i)));
        }
    }
    // Великий и Ужасный Рандомный Зверь
    srand(time(NULL));
}

void Widget::timerEvent(QTimerEvent *te)
{
    // Если игрок играет
    if(ST->getStatus() == SM::playScreen)
    {
        // Наш корабль к курсору
        Point To((xg - Player::instance().getCoord().x())/11, (yg - Player::instance().getCoord().y())/11);
        Player::instance().moveTo(Player::instance().getCoord() + To);


        // Если пришло время стрелять
        if(te->timerId() == idShootEnemyTimer)
        for(std::vector<Enemy*>::iterator i = EnemyVector.begin(); i!=EnemyVector.end(); i++)
        {
            // Записываем выстрел в вектор
            if((1+rand()%50) < 20)
                BulletVector.push_back(new Bullet(0x000A00FF, Point((*i)->getCoord()), false));
        }
        // Если врагов не осталось создать еще группу!
        if(EnemyVector.empty())
        {
            for(int i = 1; i<=3; i++)
            {
                for(int j = 1; j<=(10/i);j++)
                {
                    EnemyVector.push_back(new Enemy(0x00FF0000, Point(-5+j,10-i)));
                }
            }
        }
        //Если персоонаж игрока во время игры получил критические повреждения
        if(ST->getStatus() == SM::playScreen && Player::instance().getLife()<=0)
        {
            ST->pushStatus(SM::deathScrean);
        }

        // Обновить экран
        updateGL();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *me)
{

    // Высчитываем координаты в системе OpenGL
    int x = me->pos().x();
    int y = me->pos().y();
    float w = width(), h = height();
    xg = (x-w/2)/(w/2);
    yg = (-y+h/2)/(h/2);

    if(w<=h)
    {
        xg*=ort+ort*(w/h);
        yg*=ort;
    }
    else
    {
        yg*=ort+ort*(h/w);
        xg*=ort;
    }

}

void Widget::mousePressEvent(QMouseEvent *me)
{
    // Если игрок играет
    if(ST->getStatus() == SM::playScreen)
    {
        BulletVector.push_back(new Bullet(0x000000FF, Player::instance().getCoord(), 1));
    }
}

void Widget::initializeGL()
{
    // Иницилизация настроек OpengGL
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float w = width(), h = height();
    if(width()<=height())
        glOrtho(-ort+(-ort*(w/h)), ort+ort*(w/h), -ort, ort, -1, 1);
    else
        glOrtho(-ort, ort, -ort+(-ort*(h/w)), ort+ort*(h/w), -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DOUBLEBUFFER);
}

void Widget::paintGL()
{
    // Если игрок играет
    if(ST->getStatus() == SM::playScreen)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Нарисовать звезды
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
        double mix, max, miy, may;
        getOpengGlSizeWindow(mix, max, miy, may, width(), height(), ort);
        for(double x = mix; x <= max; x+=0.5)
        {
            for(double y = miy; y <= may; y+=0.5)
            {
                if((1+rand()%25) <=1)
                    glVertex2d(x,y);
            }
        }
        glEnd();

        // Нарисовать объекты на поле
        paintVector.clear();
        paintVector.push_back(&(Player::instance()));
        //Добавляем вектора объектов наследников в отрисовочный вектор
        addVector(paintVector, EnemyVector);
        addVector(paintVector, BulletVector);
        for(std::vector<PaintObjectAbstract*>::iterator i = paintVector.begin(); i!=paintVector.end(); i++)
        {
            (*i)->paint();
        }

        // Проверить коллизии на пули
        for(std::vector<Bullet*>::iterator i = BulletVector.begin(); i!=BulletVector.end(); i++)
        {

            if((*i)->getDirection() == false && NPC::intersection(&Player::instance(), (*i)))
            {
                 Player::instance().minLife();
            }
            bool breakLoop = false; // Нельзя использовать Векторы если хотябы один элемент
            // был удален - итератор не действителен!
            for(std::vector<Enemy*>::iterator j = EnemyVector.begin(); j!=EnemyVector.end(); j++)
            {
                 if(NPC::intersection((*i), (*j)) && (*i)->getDirection()==true)
                 {
                     EnemyVector.erase(j);
                     BulletVector.erase(i);
                     breakLoop = true;
                 }
                 if(breakLoop) break; // Уходим из цикла
            }
            if(breakLoop) break; // Избегаем goto label;
            // Если пуля больше не на поле
            if(!(*i)->onField(-coef, coef))
            {
                BulletVector.erase(i);
                break;
            }
            //Иначе переместить пули -????-
            (*i)->moveTo(( ((*i)->getDirection())?((*i)->getCoord()+Point(0,0.5)):((*i)->getCoord()+Point(0,-0.5)) ));
        }

    }
    //Если персоонаж игрока получил критические повреждения
    else if(ST->getStatus() == SM::deathScrean)
    {
        glClearColor(1,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0,0,1);
        renderText(0,0,0, QString("ВЫ ПРОИГРАЛИ"),QFont(QString("MS Shell Dlg 2"), 10, 10));
    }
    glFlush();
}
void Widget::resizeGL(int w, int h)
{
    glViewport(0,0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
    {
         this->coef = ort+(-ort*(w/h));
         glOrtho(-ort+(-ort*(w/h)), ort+ort*(w/h), -ort, ort, -1, 1);
    }
    else
    {
        this->coef = ort+(ort*(h/(float)w));
        glOrtho(-ort, ort, -ort+(-ort*(h/(float)w)), ort+(ort*(h/(float)w)), -1, 1);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

Widget::~Widget()
{
    delete ui;
    delete player;
    for(std::vector<Enemy*>::iterator i = EnemyVector.begin(); i!=EnemyVector.end(); i++)
    {
        delete (*i);
    }
    for(std::vector<Bullet*>::iterator i = BulletVector.begin(); i!=BulletVector.end(); i++)
    {
        delete (*i);
    }
}
