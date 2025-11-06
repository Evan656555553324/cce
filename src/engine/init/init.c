#include <cce.h>
#include <init.h>
#include <string.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

static int cce_inited = 0;

int cce_engine_init(void)
{
    int retcode = 0;

    if ( cce_inited == 1 ) { return -1; }

    printf("CCE | Initializing CCE engine with OpenGL...\n");

    glfwInitHint(GLFW_WAYLAND_LIBDECOR, GLFW_FALSE);
    
    if (glfwInit() != 1) {
        fprintf(stderr, "CCE | ❌ Failed to initialize GLFW\n");
        return -1;
    }
    
    printf("CCE | ✅ GLFW initialized successfully\n");

    return retcode;
}

void cce_engine_cleanup(void)
{
    if ( cce_inited == 0 ) { return; }

    printf("CCE | Cleaning up CCE engine...\n");
    glfwTerminate();
    printf("CCE | ✅ Engine cleanup completed\n");

    cce_inited = 0;

    return;
}

int cce_get_version(char ** ver_str_ptr)
{
    strcpy(*ver_str_ptr, CCE_VERSION);
    return 0;
}