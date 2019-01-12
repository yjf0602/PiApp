#include "app.h"
#include <stdlib.h>

extern "C"
{
#include "../lcd_1in3/DEV_Config.h"
#include "../lcd_1in3/LCD_1in3.h"
#include "../lcd_1in3/GUI_Paint.h"
#include "../lcd_1in3/GUI_BMP.h"
}

#include "../utils/utils.h"

#include "app_camera/app_camera.h"

using namespace std;

vector<App*> app_list;

static void app_regist(void);
static void app_update_icons(void);

static int app_index = 0;

std::string app_toolbar_string = "PiApp";
std::string app_status_bar_string;

void app_init()
{
    // init lcd 1in3
    if(DEV_ModuleInit() != 0){
        DEV_ModuleExit();
        return;
    }
    LCD_Init(HORIZONTAL);
	LCD_Clear(GBLUE);
    
    GUI_NewImage(IMAGE_RGB, LCD_WIDTH, LCD_HEIGHT, IMAGE_ROTATE_0, IMAGE_COLOR_POSITIVE);
    GUI_Clear(GBLUE);
    
    app_regist();

    app_update_tools_bar();
    app_update_icons();
    app_update_status_bar();
}

static void app_regist(void)
{
    App* app = new App_Camera();
    app_list.push_back(app);
}

static void app_update_icons(void)
{
    cv::Mat m = app_list.at(0)->icon_n;
    DrawMatOnLCD(m, cv::Point(40,40));
}

void app_set_tools_bar_message(std::string message)
{
    app_toolbar_string = message;
}

void app_update_tools_bar(void)
{
    GUI_DrawRectangle(1, 1, 240, 15, BLUE, DRAW_FILL_FULL, DOT_PIXEL_1X1);
    GUI_DrawString_EN(2,2, app_toolbar_string.c_str(), &Font12, BLUE, WHITE);
    LCD_DisplayWindows(1,1,240,15);
}

void app_set_status_bar_message(std::string message)
{
    app_status_bar_string = message; 
}

void app_update_status_bar(void)
{
    GUI_DrawRectangle(1, 226, 240, 240, BLUE, DRAW_FILL_FULL, DOT_PIXEL_1X1);
    GUI_DrawString_EN(2,227, app_status_bar_string.c_str(), &Font12, BLUE, WHITE);
    LCD_DisplayWindows(1, 226, 240, 240);
}

void app_loop()
{
    
}



