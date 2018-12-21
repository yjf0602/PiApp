#ifndef APP_CAMERA_H
#define APP_CAMERA_H

#include "../app.h"

#define APP_CAMERA_ICON     "res/app_camera/camera_icon.jpg"
#define APP_CAMERA_ICON_S   "res/app_camera/camera_icon_s.jpg"

class App_Camera : public App
{
public:
    App_Camera();
    ~App_Camera();

    void init(void);
    void run(void);
};


#endif
