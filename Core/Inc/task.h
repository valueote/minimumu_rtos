#ifndef __TASK_H
#define __TASK_H

#include "config.h"
#include "list.h"
#include "stm32f1xx.h"
#include <stddef.h>
#include <stdint.h>

#define INITIAL_XPSR (0x01000000)
#define START_ADDRESS_MASK (0xfffffffeUL)
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define task_switch() *((volatile uint32_t *)0xe000ed04) = 1UL << 28UL
#define TRUE 1
#define FALSE 0

typedef struct tcb {
  uint32_t *stack_top;
  uint32_t priority;
  uint32_t *stack;
  list_node_t state_node;
} tcb_t;
typedef void (*task_func_t)(void *);
typedef tcb_t *task_handler_t;

void task_create(task_func_t func, void *func_parameters, uint32_t stack_depth,
                 uint32_t priority, task_handler_t *handler);
void task_delete(task_handler_t *handler);
void task_delay(uint32_t ticks);
void task_suspend(task_handler_t *handler);
void task_resume(task_handler_t *handler);
tcb_t *get_current_tcb(void);

void scheduler_init(void);
void scheduler_start(void);
void scheduler_suspend(void);
void scheduler_resume(void);

uint32_t critical_enter(void);
void critical_exit(uint32_t ret);

#endif
