#include "render.h"

Render::Render(QWidget *parent) : QOpenGLWidget(parent) {}

void Render::initializeGL() {
    // Инициализация OpenGL
}

void Render::resizeGL(int w, int h) {
    // Обработка изменения размеров виджета
}

void Render::paintGL() {
    // Код рисования с использованием OpenGL
}
