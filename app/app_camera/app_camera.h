#ifndef APP_CAMERA_H
#define APP_CAMERA_H

#include "../app.h"

#define APP_CAMERA_ICON_N     "res/app_camera/camera_n.jpg"
#define APP_CAMERA_ICON_P     "res/app_camera/camera_n.jpg"

class App_Camera : public App
{
public:
    App_Camera();
    ~App_Camera();

    void init(void);
    void run(void);
};


#endif
