#ifndef __LINUX_SPINLOCK_TYPES_UP_H
#define __LINUX_SPINLOCK_TYPES_UP_H

#ifndef __LINUX_SPINLOCK_TYPES_H
# error "please don't include this file directly"
#endif

/*
 * include/linux/spinlock_types_up.h - spinlock type definitions for UP
 *
 * portions Copyright 2005, Red Hat, Inc., Ingo Molnar
 * Released under the General Public License (GPL).
 */

#ifdef CONFIG_DEBUG_SPINLOCK

typedef struct {
	volatile unsigned int slock;
} raw_spinlock_t;

#define __RAW_SPIN_LOCK_UNLOCKED { 1 }

#else

typedef EMPTY_STRUCT_DECL(/* unnamed */) raw_spinlock_t;

#define __RAW_SPIN_LOCK_UNLOCKED { }

#endif

#ifdef CONFIG_DEBUG_LOCK_ALLOC
typedef struct {
	/* no debug version on UP */
} raw_rwlock_t;
#else
typedef EMPTY_STRUCT_DECL(/* unnamed */) raw_rwlock_t;
#endif

#define __RAW_RW_LOCK_UNLOCKED { }

#endif /* __LINUX_SPINLOCK_TYPES_UP_H */
