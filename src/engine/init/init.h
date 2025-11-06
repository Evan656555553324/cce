#ifndef CCE_INIT_GUARD_H
#define CCE_INIT_GUARD_H

int cce_engine_init(void);
void cce_engine_cleanup(void);
int cce_get_version(char ** ver_str_ptr);

#endif