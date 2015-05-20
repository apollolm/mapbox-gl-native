////From http://www.kdab.com/opengl-in-qt-5-1-part-1/
//
//#include "qt_glwindow.h"
//
//#include <QtGui/QOpenGLContext>
//#include <QtGui/QOpenGLPaintDevice>
//#include <QtGui/QOpenGLContext>
//#include <QtCore/QCoreApplication>
//
//QTGLWindow::QTGLWindow(QWindow * parent)
//: QWindow(parent)
//, m_update_pending(false)
//, m_animating(false)
//, m_context(0)
//, m_device(0)
//{
//    // Tell Qt we will use OpenGL for this window
//    setSurfaceType(QWindow::OpenGLSurface);
//    setFlags(Qt::Window | Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
//
//    //initializeOpenGLFunctions();
//    // Specify the format and create platform-specific surface
////    QSurfaceFormat format;
////    format.setDepthBufferSize(16);
//////    format.setDepthBufferSize( 24 );
//////    format.setMajorVersion( 4 );
//////    format.setMinorVersion( 3 );
////    //format.setSamples( 4 );
////    //format.setProfile( QSurfaceFormat::CoreProfile );
////    setFormat(format);
////    create();
////    
////    // Create an OpenGL context
////    m_context = new QOpenGLContext;
////    m_context->setFormat(format);
////    m_context->create();
////    
////    // Make the context current on this window
////    m_context->makeCurrent(this);
////    
////    // Obtain a functions object and resolve all entry points
////    // m_funcs is declared as: QOpenGLFunctions_4_3_Core* m_funcs
////    m_funcs = m_context->versionFunctions();
////    if ( !m_funcs ) {
////        qWarning("Could not obtain OpenGL versions object");
////        exit( 1 );
////    }
////    m_funcs->initializeOpenGLFunctions();
//}
//
//QTGLWindow::~QTGLWindow()
//{
//    //delete m_device;
//}
//
//void QTGLWindow::makeContextCurrent(QWindow *window)
//{
//    //Set context to be current
//    m_context->makeCurrent(window);
//}
//
//void QTGLWindow::renderLater()
//{
//    if (!m_update_pending) {
//        m_update_pending = true;
//        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
//    }
//}
//
//bool QTGLWindow::event(QEvent *event)
//{
//    switch (event->type()) {
//        case QEvent::UpdateRequest:
//            m_update_pending = false;
//            renderNow();
//            return true;
//        default:
//            return QWindow::event(event);
//    }
//}
//
//void QTGLWindow::renderNow()
//{
//    if (!isExposed())
//        return;
//    
//    bool needsInitialize = false;
//    
//    if (!m_context) {
//        m_context = new QOpenGLContext(this);
//        m_context->setFormat(requestedFormat());
//        m_context->create();
//        
//        needsInitialize = true;
//    }
//    
//    m_context->makeCurrent(this);
//    
//    if (needsInitialize) {
//        
//        // Obtain a functions object and resolve all entry points
//        // m_funcs is declared as: QOpenGLFunctions_4_3_Core* m_funcs
//        m_funcs = m_context->versionFunctions();
//        if ( !m_funcs ) {
//            qWarning("Could not obtain OpenGL versions object");
//            exit( 1 );
//        }
//        m_funcs->initializeOpenGLFunctions();
//        //initialize();
//    }
//    
//    //render();
//    
//    m_context->swapBuffers(this);
//    
////    if (m_animating)
////        renderLater();
//}
//
//void QTGLWindow::exposeEvent(QExposeEvent *event)
//{
//    Q_UNUSED(event);
//    
//    if (isExposed())
//        renderNow();
//}
//
//void QTGLWindow::setAnimating(bool animating)
//{
//    m_animating = animating;
//    
//    if (animating)
//        renderLater();
//}

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
//#include "qt_glwindow.h"
//
//#include <QtCore/QCoreApplication>
//
//#include <QtGui/QOpenGLContext>
//#include <QtGui/QOpenGLPaintDevice>
//#include <QtGui/QPainter>
//
//QTGLWindow::QTGLWindow(QWindow *parent)
//: QWindow(parent)
//, m_update_pending(false)
//, m_animating(false)
//, m_context(0)
//, m_device(0)
//{
//    setSurfaceType(QWindow::OpenGLSurface);
//}
//
//QTGLWindow::~QTGLWindow()
//{
//    delete m_device;
//}
//void QTGLWindow::render(QPainter *painter)
//{
//    Q_UNUSED(painter);
//}
//
//void QTGLWindow::initializeQTWindow()
//{
//}
//
//void QTGLWindow::render()
//{
//    if (!m_device)
//        m_device = new QOpenGLPaintDevice;
//    
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//    
//    m_device->setSize(size());
//    
//    QPainter painter(m_device);
//    render(&painter);
//}
//
//void QTGLWindow::renderLater()
//{
//    if (!m_update_pending) {
//        m_update_pending = true;
//        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
//    }
//}
//
//bool QTGLWindow::event(QEvent *event)
//{
//    switch (event->type()) {
//        case QEvent::UpdateRequest:
//            m_update_pending = false;
//            renderNow();
//            return true;
//        default:
//            return QWindow::event(event);
//    }
//}
//
//void QTGLWindow::exposeEvent(QExposeEvent *event)
//{
//    Q_UNUSED(event);
//    
//    if (isExposed())
//        renderNow();
//}
//
//void QTGLWindow::renderNow()
//{
//    if (!isExposed())
//        return;
//    
//    bool needsInitialize = false;
//    
//    if (!m_context) {
//        m_context = new QOpenGLContext(this);
//        m_context->setFormat(requestedFormat());
//        m_context->create();
//        
//        needsInitialize = true;
//    }
//    
//    m_context->makeCurrent(this);
//    
//    if (needsInitialize) {
//        initializeOpenGLFunctions();
//        initializeQTWindow();
//    }
//    
//    render();
//    
//    m_context->swapBuffers(this);
//    
//    if (m_animating)
//        renderLater();
//}
//
//void QTGLWindow::setAnimating(bool animating)
//{
//    m_animating = animating;
//    
//    if (animating)
//        renderLater();
//}



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
//#include "qt_glwindow.h"
//
//#include <QtGui/QOpenGLContext>
//#include <QtGui/QOpenGLFunctions>
//#include <QtCore/qmath.h>
//
//Renderer::Renderer(const QSurfaceFormat &format, Renderer *share, QScreen *screen)
//: m_initialized(false)
//, m_format(format)
//, m_currentWindow(0)
//{
//    m_context = new QOpenGLContext(this);
//    if (screen)
//        m_context->setScreen(screen);
//    m_context->setFormat(format);
//    if (share)
//        m_context->setShareContext(share->m_context);
//    m_context->create();
//}
//
//HelloWindow::HelloWindow(const QSharedPointer<Renderer> &renderer)
//: m_colorIndex(0), m_renderer(renderer)
//{
//    setSurfaceType(QWindow::OpenGLSurface);
//    setFlags(Qt::Window | Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
//    
//    setGeometry(QRect(10, 10, 640, 480));
//    
//    setFormat(renderer->format());
//    
//    create();
//    
//    updateColor();
//}
//
//void HelloWindow::exposeEvent(QExposeEvent *)
//{
//    m_renderer->setAnimating(this, isExposed());
//}
//
//void HelloWindow::mousePressEvent(QMouseEvent *)
//{
//    updateColor();
//}
//
//QColor HelloWindow::color() const
//{
//    QMutexLocker locker(&m_colorLock);
//    return m_color;
//}
//
//void HelloWindow::updateColor()
//{
//    QMutexLocker locker(&m_colorLock);
//    
//    QColor colors[] =
//    {
//        QColor(100, 255, 0),
//        QColor(0, 100, 255)
//    };
//    
//    m_color = colors[m_colorIndex];
//    m_colorIndex = 1 - m_colorIndex;
//}
//
//void Renderer::setAnimating(HelloWindow *window, bool animating)
//{
//    QMutexLocker locker(&m_windowLock);
//    if (m_windows.contains(window) == animating)
//        return;
//    
//    if (animating) {
//        m_windows << window;
//        if (m_windows.size() == 1)
//            QTimer::singleShot(0, this, SLOT(render()));
//    } else {
//        m_currentWindow = 0;
//        m_windows.removeOne(window);
//    }
//}
//
//void Renderer::render()
//{
//    QMutexLocker locker(&m_windowLock);
//    
//    if (m_windows.isEmpty())
//        return;
//    
//    HelloWindow *surface = m_windows.at(m_currentWindow);
//    QColor color = surface->color();
//    
//    m_currentWindow = (m_currentWindow + 1) % m_windows.size();
//    
//    if (!m_context->makeCurrent(surface))
//        return;
//    
//    QSize viewSize = surface->size();
//    
//    locker.unlock();
//    
//    if (!m_initialized) {
//        initialize();
//        m_initialized = true;
//    }
//    
//    QOpenGLFunctions *f = m_context->functions();
//    f->glViewport(0, 0, viewSize.width() * surface->devicePixelRatio(), viewSize.height() * surface->devicePixelRatio());
//    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    
//    f->glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
//    f->glFrontFace(GL_CW);
//    f->glCullFace(GL_FRONT);
//    f->glEnable(GL_CULL_FACE);
//    f->glEnable(GL_DEPTH_TEST);
//    
//    m_program->bind();
//    m_vbo.bind();
//    
//    m_program->enableAttributeArray(vertexAttr);
//    m_program->enableAttributeArray(normalAttr);
//    m_program->setAttributeBuffer(vertexAttr, GL_FLOAT, 0, 3);
//    const int verticesSize = vertices.count() * 3 * sizeof(GLfloat);
//    m_program->setAttributeBuffer(normalAttr, GL_FLOAT, verticesSize, 3);
//    
//    QMatrix4x4 modelview;
//    modelview.rotate(m_fAngle, 0.0f, 1.0f, 0.0f);
//    modelview.rotate(m_fAngle, 1.0f, 0.0f, 0.0f);
//    modelview.rotate(m_fAngle, 0.0f, 0.0f, 1.0f);
//    modelview.translate(0.0f, -0.2f, 0.0f);
//    
//    m_program->setUniformValue(matrixUniform, modelview);
//    m_program->setUniformValue(colorUniform, color);
//    
//    m_context->functions()->glDrawArrays(GL_TRIANGLES, 0, vertices.size());
//    
//    m_context->swapBuffers(surface);
//    
//    m_fAngle += 1.0f;
//    
//    QTimer::singleShot(0, this, SLOT(render()));
//}
//
//void Renderer::initialize()
//{
//    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
//    vshader->compileSourceCode(
//                               "attribute highp vec4 vertex;"
//                               "attribute mediump vec3 normal;"
//                               "uniform mediump mat4 matrix;"
//                               "uniform lowp vec4 sourceColor;"
//                               "varying mediump vec4 color;"
//                               "void main(void)"
//                               "{"
//                               "    vec3 toLight = normalize(vec3(0.0, 0.3, 1.0));"
//                               "    float angle = max(dot(normal, toLight), 0.0);"
//                               "    vec3 col = sourceColor.rgb;"
//                               "    color = vec4(col * 0.2 + col * 0.8 * angle, 1.0);"
//                               "    color = clamp(color, 0.0, 1.0);"
//                               "    gl_Position = matrix * vertex;"
//                               "}");
//    
//    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
//    fshader->compileSourceCode(
//                               "varying mediump vec4 color;"
//                               "void main(void)"
//                               "{"
//                               "    gl_FragColor = color;"
//                               "}");
//    
//    m_program = new QOpenGLShaderProgram(this);
//    m_program->addShader(vshader);
//    m_program->addShader(fshader);
//    m_program->link();
//    m_program->bind();
//    
//    vertexAttr = m_program->attributeLocation("vertex");
//    normalAttr = m_program->attributeLocation("normal");
//    matrixUniform = m_program->uniformLocation("matrix");
//    colorUniform = m_program->uniformLocation("sourceColor");
//    
//    m_fAngle = 0;
//    createGeometry();
//    
//    m_vbo.create();
//    m_vbo.bind();
//    const int verticesSize = vertices.count() * 3 * sizeof(GLfloat);
//    m_vbo.allocate(verticesSize * 2);
//    m_vbo.write(0, vertices.constData(), verticesSize);
//    m_vbo.write(verticesSize, normals.constData(), verticesSize);
//}
//
//void Renderer::createGeometry()
//{
//    vertices.clear();
//    normals.clear();
//    
//    qreal x1 = +0.06f;
//    qreal y1 = -0.14f;
//    qreal x2 = +0.14f;
//    qreal y2 = -0.06f;
//    qreal x3 = +0.08f;
//    qreal y3 = +0.00f;
//    qreal x4 = +0.30f;
//    qreal y4 = +0.22f;
//    
//    quad(x1, y1, x2, y2, y2, x2, y1, x1);
//    quad(x3, y3, x4, y4, y4, x4, y3, x3);
//    
//    extrude(x1, y1, x2, y2);
//    extrude(x2, y2, y2, x2);
//    extrude(y2, x2, y1, x1);
//    extrude(y1, x1, x1, y1);
//    extrude(x3, y3, x4, y4);
//    extrude(x4, y4, y4, x4);
//    extrude(y4, x4, y3, x3);
//    
//    const qreal Pi = 3.14159f;
//    const int NumSectors = 100;
//    
//    for (int i = 0; i < NumSectors; ++i) {
//        qreal angle1 = (i * 2 * Pi) / NumSectors;
//        qreal x5 = 0.30 * qSin(angle1);
//        qreal y5 = 0.30 * qCos(angle1);
//        qreal x6 = 0.20 * qSin(angle1);
//        qreal y6 = 0.20 * qCos(angle1);
//        
//        qreal angle2 = ((i + 1) * 2 * Pi) / NumSectors;
//        qreal x7 = 0.20 * qSin(angle2);
//        qreal y7 = 0.20 * qCos(angle2);
//        qreal x8 = 0.30 * qSin(angle2);
//        qreal y8 = 0.30 * qCos(angle2);
//        
//        quad(x5, y5, x6, y6, x7, y7, x8, y8);
//        
//        extrude(x6, y6, x7, y7);
//        extrude(x8, y8, x5, y5);
//    }
//    
//    for (int i = 0;i < vertices.size();i++)
//        vertices[i] *= 2.0f;
//}
//
//void Renderer::quad(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4)
//{
//    vertices << QVector3D(x1, y1, -0.05f);
//    vertices << QVector3D(x2, y2, -0.05f);
//    vertices << QVector3D(x4, y4, -0.05f);
//    
//    vertices << QVector3D(x3, y3, -0.05f);
//    vertices << QVector3D(x4, y4, -0.05f);
//    vertices << QVector3D(x2, y2, -0.05f);
//    
//    QVector3D n = QVector3D::normal
//    (QVector3D(x2 - x1, y2 - y1, 0.0f), QVector3D(x4 - x1, y4 - y1, 0.0f));
//    
//    normals << n;
//    normals << n;
//    normals << n;
//    
//    normals << n;
//    normals << n;
//    normals << n;
//    
//    vertices << QVector3D(x4, y4, 0.05f);
//    vertices << QVector3D(x2, y2, 0.05f);
//    vertices << QVector3D(x1, y1, 0.05f);
//    
//    vertices << QVector3D(x2, y2, 0.05f);
//    vertices << QVector3D(x4, y4, 0.05f);
//    vertices << QVector3D(x3, y3, 0.05f);
//    
//    n = QVector3D::normal
//    (QVector3D(x2 - x4, y2 - y4, 0.0f), QVector3D(x1 - x4, y1 - y4, 0.0f));
//    
//    normals << n;
//    normals << n;
//    normals << n;
//    
//    normals << n;
//    normals << n;
//    normals << n;
//}
//
//void Renderer::extrude(qreal x1, qreal y1, qreal x2, qreal y2)
//{
//    vertices << QVector3D(x1, y1, +0.05f);
//    vertices << QVector3D(x2, y2, +0.05f);
//    vertices << QVector3D(x1, y1, -0.05f);
//    
//    vertices << QVector3D(x2, y2, -0.05f);
//    vertices << QVector3D(x1, y1, -0.05f);
//    vertices << QVector3D(x2, y2, +0.05f);
//    
//    QVector3D n = QVector3D::normal
//    (QVector3D(x2 - x1, y2 - y1, 0.0f), QVector3D(0.0f, 0.0f, -0.1f));
//    
//    normals << n;
//    normals << n;
//    normals << n;
//    
//    normals << n;
//    normals << n;
//    normals << n;
//}





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
#include "qt_glwindow.h"

#include <QtGui/QMouseEvent>
#include <QtGui/QOpenGLShaderProgram>
#include <QtCore/QCoreApplication>

#include <math.h>

QTGLWindow::QTGLWindow(QWidget *parent) :
QOpenGLWidget(parent),
texture(0),
angularSpeed(0)
{
    m_core = QCoreApplication::arguments().contains(QStringLiteral("--coreprofile"));
    // --transparent causes the clear color to be transparent. Therefore, on systems that
    // support it, the widget will become transparent apart from the logo.
    m_transparent = QCoreApplication::arguments().contains(QStringLiteral("--transparent"));
    if (m_transparent)
        setAttribute(Qt::WA_TranslucentBackground);
    
    //mbgl::gl::InitializeExtensions(QOpenGLContext::getProcAddress);
}

QTGLWindow::~QTGLWindow()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    delete texture;
    doneCurrent();
}

//void QTGLWindow::keyPressEvent(QKeyEvent *event)
//{
//    // Save mouse press position
//    switch (event->key())
//    {
//        case (Qt::Key_Left):
//            
//            break;
//        case (Qt::Key_Right):
//            
//            break;
//        case (Qt::Key_Up):
//            
//            break;
//        case (Qt::Key_Down):
//            
//            break;
//    }
//}

void QTGLWindow::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}

void QTGLWindow::mouseReleaseEvent(QMouseEvent *e)
{
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;
    
    // Rotation axis is perpendicular to the mouse position difference
    // vector
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();
    
    // Accelerate angular speed relative to the length of the mouse sweep
    qreal acc = diff.length() / 100.0;
    
    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();
    
    // Increase angular speed
    angularSpeed += acc;
}

void QTGLWindow::timerEvent(QTimerEvent *)
{
    // Decrease angular speed (friction)
    angularSpeed *= 0.99;
    
    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01) {
        angularSpeed = 0.0;
    } else {
        // Update rotation
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;
        
        // Request an update
        update();
    }
}


void QTGLWindow::initializeGL()
{
    initializeOpenGLFunctions();
    
    glCreateProgram();
    
    glClearColor(255, 0, 0, 1);
    
    //initShaders();
    //initTextures();
    
    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);
    
    // Enable back face culling
    glEnable(GL_CULL_FACE);

    //geometries = new GeometryEngine;
    
    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);
}

//static const char *vertexShaderSourceCore =
//"#version 150\n"
//"in vec4 vertex;\n"
//"in vec3 normal;\n"
//"out vec3 vert;\n"
//"out vec3 vertNormal;\n"
//"uniform mat4 projMatrix;\n"
//"uniform mat4 mvMatrix;\n"
//"uniform mat3 normalMatrix;\n"
//"void main() {\n"
//"   vert = vertex.xyz;\n"
//"   vertNormal = normalMatrix * normal;\n"
//"   gl_Position = projMatrix * mvMatrix * vertex;\n"
//"}\n";
//
//static const char *fragmentShaderSourceCore =
//"#version 150\n"
//"in highp vec3 vert;\n"
//"in highp vec3 vertNormal;\n"
//"out highp vec4 fragColor;\n"
//"uniform highp vec3 lightPos;\n"
//"void main() {\n"
//"   highp vec3 L = normalize(lightPos - vert);\n"
//"   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
//"   highp vec3 color = vec3(0.39, 1.0, 0.0);\n"
//"   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
//"   fragColor = vec4(col, 1.0);\n"
//"}\n";
//
//static const char *vertexShaderSource =
//"attribute vec4 vertex;\n"
//"attribute vec3 normal;\n"
//"varying vec3 vert;\n"
//"varying vec3 vertNormal;\n"
//"uniform mat4 projMatrix;\n"
//"uniform mat4 mvMatrix;\n"
//"uniform mat3 normalMatrix;\n"
//"void main() {\n"
//"   vert = vertex.xyz;\n"
//"   vertNormal = normalMatrix * normal;\n"
//"   gl_Position = projMatrix * mvMatrix * vertex;\n"
//"}\n";
//
//static const char *fragmentShaderSource =
//"varying highp vec3 vert;\n"
//"varying highp vec3 vertNormal;\n"
//"uniform highp vec3 lightPos;\n"
//"void main() {\n"
//"   highp vec3 L = normalize(lightPos - vert);\n"
//"   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
//"   highp vec3 color = vec3(0.39, 1.0, 0.0);\n"
//"   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n"
//"   gl_FragColor = vec4(col, 1.0);\n"
//"}\n";

//void QTGLWindow::initShaders()
//{
//    // Compile vertex shader
//    
//    
//    if (!program.addShaderFromSourceCode(QOpenGLShader::Vertex, m_core ? vertexShaderSourceCore : vertexShaderSource))
//        close();
//    
//    // Compile fragment shader
//    if (!program.addShaderFromSourceCode(QOpenGLShader::Fragment, m_core ? fragmentShaderSourceCore : fragmentShaderSource))
//        close();
//    
//    // Link shader pipeline
//    if (!program.link())
//        close();
//    
//    // Bind shader pipeline for use
//    if (!program.bind())
//        close();
//}

//void QTGLWindow::initTextures()
//{
//    // Load cube.png image
////    texture = new QOpenGLTexture(QImage(":/cube.png").mirrored());
////    
////    // Set nearest filtering mode for texture minification
////    texture->setMinificationFilter(QOpenGLTexture::Nearest);
////    
////    // Set bilinear filtering mode for texture magnification
////    texture->setMagnificationFilter(QOpenGLTexture::Linear);
////    
////    // Wrap texture coordinates by repeating
////    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
////    texture->setWrapMode(QOpenGLTexture::Repeat);
//}

void QTGLWindow::resizeGL(int w, int h)
{
    w = 9;
    h= 2;
//    // Calculate aspect ratio
//    qreal aspect = qreal(w) / qreal(h ? h : 1);
//    
//    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
//    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;
//    
//    // Reset projection
//    projection.setToIdentity();
//    
//    // Set perspective projection
//    projection.perspective(fov, aspect, zNear, zFar);
}

void QTGLWindow::paintGL()
{
    // Clear color and depth buffer
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    
//    //texture->bind();
//    
//    // Calculate model view transformation
//    QMatrix4x4 matrix;
//    matrix.translate(0.0, 0.0, -5.0);
//    matrix.rotate(rotation);
//    
//    // Set modelview-projection matrix
//    program.setUniformValue("mvp_matrix", projection * matrix);
//
//    // Use texture unit 0 which contains cube.png
//    program.setUniformValue("texture", 0);
    
    // Draw cube geometry
    //geometries->drawCubeGeometry(&program);
}
