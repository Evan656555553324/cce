#ifndef CCE_WINDOW_GUARD_H
#define CCE_WINDOW_GUARD_H

typedef struct Window Window;

Window* window_create(int width, int height, const char* title);
void window_destroy(Window* window);
int window_should_close(const Window* window);
void window_poll_events(void);
void window_swap_buffers(Window* window);
void window_make_current(Window* window);

#endif