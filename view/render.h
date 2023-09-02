#ifndef RENDER_H
#define RENDER_H

#define GL_SILENCE_DEPRECATION
#include <QOpenGLWidget>
#include "../model/model.h"

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <QMouseEvent>


class Render : public QOpenGLWidget {
    Q_OBJECT
public:
    Render(QWidget *parent = nullptr);
    void Parse();
    void Scale(double size) {
        _3d_obj.Scale(size);
        update();
    }
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
private:
//    double angle, size, offset;
    Model _3d_obj;
    float xRot, yRot;
    QPoint mPos;
    void mousePressEvent(QMouseEvent* mo) override;
    void mouseMoveEvent(QMouseEvent* mo) override;
};

#endif // RENDER_H
