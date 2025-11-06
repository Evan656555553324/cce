#include <cce.h>
#include <window.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

struct Window {
    GLFWwindow* handle;
    int width;
    int height;
    const char* title;
};

void cce_window_make_current(Window* window) {
    if (window && window->handle) {
        glfwMakeContextCurrent(window->handle);
    }
}

void cce_window_swap_buffers(Window* window) {
    if (window && window->handle) {
        glfwSwapBuffers(window->handle);
    }
}

void cce_window_destroy(Window* window) {
    if (window) {
        printf("CCE | Destroying window: %s\n", window->title);
        glfwDestroyWindow(window->handle);
        free(window);
    }
}

int cce_window_should_close(const Window* window) {
    return window ? glfwWindowShouldClose(window->handle) : -1;
}

void cce_window_poll_events(void) {
    glfwPollEvents();
}

Window* cce_window_create(int width, int height, const char* title)
{
    printf("CCE | Creating OpenGL window: %dx%d '%s'\n", width, height, title);
    

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // Для macOS
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    
    // Создание окна
    GLFWwindow* glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!glfw_window) {
        fprintf(stderr, "CCE | ❌ Failed to create OpenGL window\n");
        return NULL;
    }
    
    // Создание структуры окна
    Window* window = malloc(sizeof(Window));
    window->handle = glfw_window;
    window->width = width;
    window->height = height;
    window->title = title;
    
    // Активируем контекст OpenGL
    cce_window_make_current(window);
    
    printf("CCE | ✅ OpenGL window created successfully\n");
    return window;
}