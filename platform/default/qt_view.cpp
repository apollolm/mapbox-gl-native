#include <mbgl/platform/default/qt_view.h>
//#include <mbgl/platform/default/qt_glwindow.h>
#include <mbgl/platform/gl.hpp>
#include <mbgl/platform/log.hpp>
#include <mbgl/util/gl_helper.hpp>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFunctions>
#include <QtCore/QThread>

#include <cassert>
#include <string>
#include <iostream>


void glfwError(int error, const char *description) {
    mbgl::Log::Error(mbgl::Event::OpenGL, "GLFW error (%i): %s", error, description);
    assert(false);
}

QTView::QTView(bool fullscreen_) :
fullscreen(fullscreen_)
{
//    
//    m_glContextIsMovedToGraphicsThread = false;
//    m_threadingModelChanged = false;
//    m_threadingModel = m_viewer->getThreadingModel();
//    connect(this, SIGNAL(needToMoveGLContextToGraphicsThread()), this, SLOT(moveGLContextToThreadGraphicsThread()), Qt::BlockingQueuedConnection);
//    connect(this, SIGNAL(movedGLContextToGraphicsThread()), this, SLOT(trySetThreadingModel()), Qt::QueuedConnection);
//    
    QSurfaceFormat format;
    format.setDepthBufferSize(16);
    
#ifdef GL_ES_VERSION_2_0
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    format.setMajorVersion(2);
    format.setMinorVersion(0);
    format.setRenderableType(QSurfaceFormat::OpenGLES);
#endif
    
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setRedBufferSize(8);
    format.setGreenBufferSize(8);
    format.setBlueBufferSize(8);
    format.setAlphaBufferSize(8);
    format.setStencilBufferSize(8);
    format.setDepthBufferSize(16);
    
    window = new QTGLWindow();
    window->setFormat(format);
    window->resize(640, 480);
    
    if (fullscreen) {
        //Be fullscreen
       window->showMaximized();
    }
    else{
       window->show();
    }
    
    qDebug() << "window (main) thread ID = " << window->thread()->currentThreadId();
    
    window->doneCurrent();
    
    QString versionString(QLatin1String(reinterpret_cast<const char*>(glGetString(GL_VERSION))));
    qDebug() << "Driver Version String:" << versionString;
    qDebug() << "Current Context:" << window->format();

    //I don't know how to initialize this with QT's getProcAddress.
    //mbgl::gl::InitializeExtensions(QOpenGLContext::getProcAddress);
    
    //window->setAnimating(true);
    //window->renderNow();
}

QTView::~QTView() {
    //Clean up QtGLWindow

}



void QTView::initialize(mbgl::Map *map_) {
    View::initialize(map_);

 
    
}

//void QTView::initializeQTWindow()
//{
//    m_program = new QOpenGLShaderProgram(this);
//    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
//    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
//    m_program->link();
//    m_posAttr = m_program->attributeLocation("posAttr");
//    m_colAttr = m_program->attributeLocation("colAttr");
//    m_matrixUniform = m_program->uniformLocation("matrix");
//}
//
//void QTView::render(){
//    
//}

//void QTView::onKey(QTGLWindow *window, int key, int /*scancode*/, int action, int mods) {
//    
//    //Call the gl_window onKey handler
//    
//}
//
//void QTView::onScroll(QTGLWindow *window, double /*xOffset*/, double yOffset) {
//    
//    //Call the gl_window onScroll handler
//    
//}
//
//void QTView::onResize(QTGLWindow *window, int width, int height ) {
//   
//    //Call the gl_window onResize handler
//    
//}
//
//void QTView::onMouseClick(QTGLWindow *window, int button, int action, int modifiers) {
//    
//    //Call the gl_window mousePressEvent handler
//    
//}
//
//void QTView::onMouseMove(QTGLWindow *window, double x, double y) {
//    
//    //Call the gl_window onMouseMove handler
//    
//}

void QTView::run() {
    //app->exec();
}

//void QtView::makeContextCurrent(){
//    
//}

void QTView::activate() {
    //I'm stuck here, since this gets called from the Map/render thread? and it fails if we call window->context()-moveToThread because only the owning thread of the context can move it...(I think).
    QThread *renderThread = QThread::currentThread();
    qDebug() << "currentThread() = " << renderThread->currentThreadId();
    
    window->doneCurrent();
   
    //window->context()->moveToThread(renderThread); //Nope
    //window->makeCurrent();
}

void QTView::deactivate() {
    window->doneCurrent();
}

void QTView::notify() {
    
}

void QTView::invalidate(std::function<void()> render) {
    render();
    //swapBuffers
}

void QTView::fps() {
    
}

void QTView::setChangeStyleCallback(std::function<void()> callback) {
    changeStyleCallback = callback;
}

void QTView::setShouldClose() {

}

void QTView::setWindowTitle(const std::string& title) {
    window->setWindowTitle(QString::fromStdString(title));
}

namespace mbgl {
namespace platform {

double elapsed() { 
    return 3.33;
}

#ifndef GL_ES_VERSION_2_0
void showDebugImage(std::string name, const char *data, size_t width, size_t height) {
    
    std::cout << name;
    MBGL_CHECK_ERROR(glDrawPixels(width, height, GL_LUMINANCE, GL_UNSIGNED_BYTE, data));
}

//void showColorDebugImage(std::string name, const char *data, size_t logicalWidth, size_t logicalHeight, size_t width, size_t height) {
//    
//}
#endif

}
}
