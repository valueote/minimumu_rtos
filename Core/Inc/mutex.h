#ifndef __MUTEX_H
#define __MUTEX_H

#include "list.h"
#include "task.h"
#include <stdint.h>

typedef struct mutex {
  uint32_t locked;
  list_t block_list;
  tcb_t *holder;
} mutex_t;

typedef mutex_t *mutex_handler;

mutex_handler mutex_create(void);
void mutex_delete(mutex_handler mutex);
uint32_t mutex_lock(mutex_handler mutex, uint32_t block_ticks);
uint32_t mutex_release(mutex_handler mutex);

#endif /*__MUTEX_H*/
