#ifndef MBGL_COMMON_QT_VIEW
#define MBGL_COMMON_QT_VIEW

#include <mbgl/mbgl.hpp>
#include <qt_glwindow.h>

class QTView : public mbgl::View{
public:
    QTView(bool fullscreen = false);
    ~QTView();

    void initialize(mbgl::Map *map) override;
    void activate() override;
    void deactivate() override;
    void notify() override;
    void invalidate(std::function<void()> render) override;

//    static void onKey(QTGLWindow *window, int key, int scancode, int action, int mods);
//    static void onScroll(QTGLWindow *window, double xoffset, double yoffset);
//    static void onResize(QTGLWindow *window, int width, int height);
//    static void onMouseClick(QTGLWindow *window, int button, int action, int modifiers);
//    static void onMouseMove(QTGLWindow *window, double x, double y);

    // Callback called when the user presses the key mapped to style change.
    // The expected action is to set a new style, different to the current one.
    void setChangeStyleCallback(std::function<void()> callback);

    void setShouldClose();

    void setWindowTitle(const std::string&);

    void run();
    void fps();
    
    QTGLWindow *window = nullptr;
    
private:
   bool fullscreen = false;
//    bool tracking = false;
//    bool rotating = false;
//
//    double lastX = 0, lastY = 0;
//
//    double lastClick = -1;
    
    std::function<void()> changeStyleCallback;
};

#endif
