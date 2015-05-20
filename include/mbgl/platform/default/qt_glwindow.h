///****************************************************************************
// **
// ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
// ** Contact: http://www.qt-project.org/legal
// **
// ** This file is part of the documentation of the Qt Toolkit.
// **
// ** $QT_BEGIN_LICENSE:BSD$
// ** You may use this file under the terms of the BSD license as follows:
// **
// ** "Redistribution and use in source and binary forms, with or without
// ** modification, are permitted provided that the following conditions are
// ** met:
// **   * Redistributions of source code must retain the above copyright
// **     notice, this list of conditions and the following disclaimer.
// **   * Redistributions in binary form must reproduce the above copyright
// **     notice, this list of conditions and the following disclaimer in
// **     the documentation and/or other materials provided with the
// **     distribution.
// **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
// **     of its contributors may be used to endorse or promote products derived
// **     from this software without specific prior written permission.
// **
// **
// ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
// **
// ** $QT_END_LICENSE$
// **
// ****************************************************************************/
//
//#include <QtGui/QWindow>
//#include <QtGui/QOpenGLFunctions>
//
//class QPainter;
//class QOpenGLContext;
//class QOpenGLPaintDevice;
//
//class QTGLWindow : public QWindow, protected QOpenGLFunctions
//{
//    Q_OBJECT
//public:
//    explicit QTGLWindow(QWindow *parent = 0);
//    ~QTGLWindow();
//    
//    //virtual void render(QPainter *painter);
//    //virtual void render();
//    
//    //virtual void initializeQTWindow();
//    
//    void setAnimating(bool animating);
//    
//    virtual void makeContextCurrent(QWindow *window);
//    
//    
//    
//    
//public slots:
//    void renderLater();
//    void renderNow();
//    
//protected:
//    bool event(QEvent *event) Q_DECL_OVERRIDE;
//    
//    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;
//    
//private:
//    bool m_update_pending;
//    bool m_animating;
//    
//    QAbstractOpenGLFunctions *m_funcs;
//    QOpenGLContext *m_context;
//    QOpenGLPaintDevice *m_device;
//};


//
///****************************************************************************
// **
// ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
// ** Contact: http://www.qt-project.org/legal
// **
// ** This file is part of the examples of the Qt Toolkit.
// **
// ** $QT_BEGIN_LICENSE:BSD$
// ** You may use this file under the terms of the BSD license as follows:
// **
// ** "Redistribution and use in source and binary forms, with or without
// ** modification, are permitted provided that the following conditions are
// ** met:
// **   * Redistributions of source code must retain the above copyright
// **     notice, this list of conditions and the following disclaimer.
// **   * Redistributions in binary form must reproduce the above copyright
// **     notice, this list of conditions and the following disclaimer in
// **     the documentation and/or other materials provided with the
// **     distribution.
// **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
// **     of its contributors may be used to endorse or promote products derived
// **     from this software without specific prior written permission.
// **
// **
// ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
// **
// ** $QT_END_LICENSE$
// **
// ****************************************************************************/
//
//#include <QtGui/QWindow>
//
//#include <QtGui/QColor>
//#include <QtCore/QMutex>
//#include <QtGui/QOpenGLShaderProgram>
//#include <QtGui/QOpenGLBuffer>
//#include <QtCore/QSharedPointer>
//#include <QtCore/QTimer>
//
//
//class HelloWindow;
//
//class Renderer : public QObject
//{
//    Q_OBJECT
//    
//public:
//    explicit Renderer(const QSurfaceFormat &format, Renderer *share = 0, QScreen *screen = 0);
//    
//    QSurfaceFormat format() const { return m_format; }
//    
//    void setAnimating(HelloWindow *window, bool animating);
//    
//    private slots:
//    void render();
//    
//private:
//    void initialize();
//    
//    void createGeometry();
//    void createBubbles(int number);
//    void quad(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
//    void extrude(qreal x1, qreal y1, qreal x2, qreal y2);
//    
//    qreal m_fAngle;
//    
//    QVector<QVector3D> vertices;
//    QVector<QVector3D> normals;
//    int vertexAttr;
//    int normalAttr;
//    int matrixUniform;
//    int colorUniform;
//    
//    bool m_initialized;
//    QSurfaceFormat m_format;
//    QOpenGLContext *m_context;
//    QOpenGLShaderProgram *m_program;
//    QOpenGLBuffer m_vbo;
//    
//    QList<HelloWindow *> m_windows;
//    int m_currentWindow;
//    
//    QMutex m_windowLock;
//};
//
//class HelloWindow : public QWindow
//{
//public:
//    explicit HelloWindow(const QSharedPointer<Renderer> &renderer);
//    
//    QColor color() const;
//    void updateColor();
//    
//    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;
//    
//private:
//    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
//    
//    int m_colorIndex;
//    QColor m_color;
//    const QSharedPointer<Renderer> m_renderer;
//    mutable QMutex m_colorLock;
//};
//
//
//
//
///****************************************************************************
// **
// ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
// ** Contact: http://www.qt-project.org/legal
// **
// ** This file is part of the QtCore module of the Qt Toolkit.
// **
// ** $QT_BEGIN_LICENSE:BSD$
// ** You may use this file under the terms of the BSD license as follows:
// **
// ** "Redistribution and use in source and binary forms, with or without
// ** modification, are permitted provided that the following conditions are
// ** met:
// **   * Redistributions of source code must retain the above copyright
// **     notice, this list of conditions and the following disclaimer.
// **   * Redistributions in binary form must reproduce the above copyright
// **     notice, this list of conditions and the following disclaimer in
// **     the documentation and/or other materials provided with the
// **     distribution.
// **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
// **     of its contributors may be used to endorse or promote products derived
// **     from this software without specific prior written permission.
// **
// **
// ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
// **
// ** $QT_END_LICENSE$
// **
// ****************************************************************************/
//
#ifndef QTGLWindow_H
#define QTGLWindow_H

//#include "geometryengine.h"

#include <QtWidgets/QOpenGLWidget>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QMatrix4x4>
#include <QtGui/QQuaternion>
#include <QtGui/QVector2D>
#include <QtCore/QBasicTimer>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLTexture>

//class GeometryEngine;

class QTGLWindow : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
    
public:
    explicit QTGLWindow(QWidget *parent = 0);
    ~QTGLWindow();

protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *e) Q_DECL_OVERRIDE;
    
    //void keyPressEvent(QKeyEvent *event);
    
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    
    //void initShaders();
    //void initTextures();
    
private:
    QBasicTimer timer;
    QOpenGLShaderProgram program;
    //GeometryEngine *geometries;
    
    QOpenGLTexture *texture;
    
    QMatrix4x4 projection;
    
    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed;
    QQuaternion rotation;
    
    bool m_core;
    bool m_transparent;
};

#endif // QTGLWindow_H
