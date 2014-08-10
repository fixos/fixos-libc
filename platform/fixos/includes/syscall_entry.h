#ifndef _SYSCALL_ARCH_SYSCALL_H
#define _SYSCALL_ARCH_SYSCALL_H

#include "fixos/syscalls.h"

// fast userland raw syscall declaration
// As extended asm directive is not working at top-level, some things are
// done to perform macro substitution before integer value of syscall is needed
#define _SYSCALL_DECL(name,id) _SYSCALL_DECL_S(name, id)
#define _SYSCALL_DECL_S(name,id) _SYSCALL_DECL_SS(name, id)

#define _SYSCALL_DECL_SS(name,id) \
	__asm__ ( \
			"_" #name " :" \
			"    trapa #" #id " ;" \
			"    rts ; " \
			)

// inline syscall entry method
#define _SYSCALL_ENTRY(id) \
	__asm__ volatile ("trapa %0;" : : "n"(id) )

#endif //_SYSCALL_ARCH_SYSCALL_H
