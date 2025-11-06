#include "../../build/include/cce.h"
#include <stdio.h>
#include <unistd.h>
#include <GL/gl.h>

int main(void)
{
    printf("=== CCE OpenGL Window Test ===\n");
    
    if (cce_engine_init() != 0) {
        printf("❌ Engine initialization failed!\n");
        return -1;
    }
    
    Window* window = cce_window_create(1920, 1080, CCE_NAME " " CCE_VERSION " | " "OpenGL Window");
    if (!window)
    {
        printf("❌ Window creation failed!\n");
        cce_engine_cleanup();
        return -1;
    }
    
    printf("✅ Window created successfully\n");
    printf("🔵 You should see a window for 5 seconds...\n");
    
    int frames = 0;
    while (!cce_window_should_close(window) && frames < 300)
    {

        cce_window_poll_events();
        
        glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        cce_window_swap_buffers(window);
        
        frames++;
        usleep(16666);
    }
    
    printf("✅ Test completed after %d frames\n", frames);
    
    cce_window_destroy(window);
    //cce_engine_cleanup();
    
    return 0;
}