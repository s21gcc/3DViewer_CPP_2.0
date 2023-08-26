#ifndef RENDER_H
#define RENDER_H

#include <QOpenGLWidget>

class Render : public QOpenGLWidget {
    Q_OBJECT
public:
    Render(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // RENDER_H
