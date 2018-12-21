#include <stdio.h>
#include "app/app.h"

int main(int argc, char **)
{
    printf("PiApp start ...\r\n");
    
    // init apps
    app_init();
    
    // into app loops
    app_loop();
    
    printf("PiApp stop ...\r\n");
    
    return 0;
}



