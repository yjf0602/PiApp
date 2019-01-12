#include "app_camera.h"

App_Camera::App_Camera()
{
    icon_n = cv::imread(APP_CAMERA_ICON_N);
    icon_p = cv::imread(APP_CAMERA_ICON_P);
    app_name = "Camera";
    printf("camera icon: %d*%d\r\n", icon_n.cols, icon_n.rows);
}

App_Camera::~App_Camera()
{

}

void App_Camera::init()
{

}

void App_Camera::run()
{

}
