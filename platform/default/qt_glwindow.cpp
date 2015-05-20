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
