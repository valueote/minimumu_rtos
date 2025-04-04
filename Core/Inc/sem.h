#ifndef __SEM_H
#define __SEM_H

#include "list.h"
#include "mem.h"
#include <stdint.h>
typedef struct semaphore {
  uint32_t count;
  list_t block_list;
} semaphore_t;

semaphore_t *semaphore_create(const uint32_t count);
void semaphore_delete(semaphore_t *sem);
void semaphore_lock(semaphore_t *sem, uint32_t block_time);
void semaphore_release(semaphore_t *sem);

#endif /*__SEM_H*/
