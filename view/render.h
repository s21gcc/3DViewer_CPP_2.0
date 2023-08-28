#ifndef RENDER_H
#define RENDER_H

#define GL_SILENCE_DEPRECATION
#include <QOpenGLWidget>
#include "../model/parser.h"

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <QMouseEvent>


class Render : public QOpenGLWidget {
    Q_OBJECT
public:
    Render(QWidget *parent = nullptr);
    void Parse();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
private:
    Parser oznak_pars;
    float xRot, yRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent* mo) override;
    void mouseMoveEvent(QMouseEvent* mo) override;
};

#endif // RENDER_H
