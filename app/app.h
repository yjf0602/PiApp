#ifndef _APP_H
#define _APP_H

#include <string>
#include "opencv2/opencv.hpp"

#define WINDOW_HEIGHT   240
#define WINDOW_WIDTH    240

#define ICON_HEIGHT     100
#define ICON_WIDTH      115

#define BAR_HEIGHT      15
#define ICON_GAP        10


class App
{
public:
    App(){};
    ~App(){};
    virtual void init(void) = 0;
    virtual void run(void) = 0;
    std::string app_name;
    cv::Mat icon;
    cv::Mat icon_select;
};

void app_init();
void app_loop();

void app_set_tools_bar_message(std::string message);
void app_update_tools_bar(void);
void app_set_status_bar_message(std::string message);
void app_update_status_bar(void);


#endif
