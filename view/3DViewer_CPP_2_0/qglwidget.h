#ifndef QGLWIDGET_H
#define QGLWIDGET_H


#include <QOpenGLWidget>
#include <QtOpenGL>


class S21Render : public QGLWidget {
    Q_OBJECT
public:
    S21Render(QWidget *parent = Q_NULLPTR);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

};

#endif // QGLWIDGET_H
