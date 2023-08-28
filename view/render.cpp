#include "render.h"



Render::Render(QWidget *parent) : QOpenGLWidget(parent) {}

void Render::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LINE_STIPPLE);

    // Инициализация OpenGL
}

void Render::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
    // Обработка изменения размеров виджета
}

void Render::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glVertexPointer(3, GL_DOUBLE, 0, oznak_pars.GetInfo().vertexes.data());
    glEnableClientState(GL_VERTEX_ARRAY);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    gluPerspective(90.0f, width() / height(), 0.1f, 1000.0f);
    glTranslatef(0,0,-10);
    glRotatef(xRot, 1,0,0);
    glRotatef(yRot, 0,1,0);


    // lines
    glDrawElements(GL_LINES, oznak_pars.GetInfo().num_facets * 2, GL_UNSIGNED_INT, oznak_pars.GetInfo().facets.data());
    glColor3f(1, 1, 1);
    glPointSize(1);
    glDrawArrays(GL_POINTS, 0, oznak_pars.GetInfo().num_vertexes);
    // Код рисования с использованием OpenGL
}

void Render::Parse() {
    oznak_pars.ParseFile("/Users/oznakban/CLionProjects/3DViewer_CPP_2.0/cube.obj");
    update();
}

void Render::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

void Render::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}
