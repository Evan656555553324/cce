#include "../../build/include/cce.h"
#include <stdio.h>
#include <time.h>
#include <GL/gl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int width = 1920;
    int height = 1080;
    long int seed = 12017928637467512;
    printf("=== CCE Pixel Grid Test ===\n");
    srand(time(NULL)); // Random
    //srand(seed); // Seed 
    
    if (cce_engine_init() != 0) {
        printf("Engine init failed\n");
        return -1;
    }
    
    Window* window = cce_window_create(1920, 1080, CCE_NAME " " CCE_VERSION " | " "Pixel Grid");
    if (!window) {
        printf("Window creation failed\n");
        cce_engine_cleanup();
        return -1;
    }
    
    cce_setup_2d_projection(width, height);
    
    printf("Starting pixel grid rendering...\n");
    
    int frame = 0;
    static int a = 0;
    while (cce_window_should_close(window) == 0 && frame < 300) {
        if (!a)
        {
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            cce_draw_pixel_grid(5, width, height);
            cce_window_swap_buffers(window);
        }
        a++;
        
        cce_window_poll_events();
        
        frame++;
        if (frame % 60 == 0) {
            printf("Frame: %d\n", frame);
        }
        usleep(16666);
    }
    
    printf("Test completed\n");
    cce_window_destroy(window);
    cce_engine_cleanup();
    return 0;
}