#include "utils.h"

extern "C"
{
#include "../lcd_1in3/DEV_Config.h"
#include "../lcd_1in3/LCD_1in3.h"
#include "../lcd_1in3/GUI_Paint.h"
#include "../lcd_1in3/GUI_BMP.h"
}

void DrawMatOnLCD(cv::Mat& m, cv::Point p)
{
    printf("DrawMatOnLcd\r\n");
    for(int y=0; y<m.rows; y++)
    {
        for(int x=0; x<m.cols; x++)
        {
            unsigned short data;

            unsigned char b = m.at<cv::Vec3b>(y,x)[0];
            unsigned char g = m.at<cv::Vec3b>(y,x)[1];
            unsigned char r = m.at<cv::Vec3b>(y,x)[2];

            data = RGB(r,g,b);

            GUI_SetPixel(x+p.x, y+p.y, data);
        }
    }

    LCD_Display();

}


