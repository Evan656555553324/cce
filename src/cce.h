#ifndef CCE_GUARD_H
#define CCE_GUARD_H

#define CCE_VERSION "0.1.0"
#define CCE_VERNAME "Initial"
#define CCE_NAME    "CastleCore Engine"

typedef struct Window Window;

/*
    I N I T
*/

int cce_engine_init(void);
void cce_engine_cleanup(void);
int cce_get_version(char ** ver_str_ptr);

/*
    W I N D O W
*/

Window* cce_window_create(int width, int height, const char* title);
void cce_window_destroy(Window* window);
int cce_window_should_close(const Window* window);
void cce_window_poll_events(void);
void cce_window_swap_buffers(Window* window);
void cce_window_make_current(Window* window);

/*
    R E N D E R
*/

void cce_setup_2d_projection(int width, int height);
void cce_draw_pixel(int x, int y, int size, float r, float g, float b);
void cce_draw_pixel_grid(int pixel_size, int screen_width, int screen_height);

#endif