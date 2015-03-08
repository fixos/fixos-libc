#include <sys/sysctl.h>
#include <bits/inline_syscalls.h>

int sysctlnametomib(const char *name, int *mibp, size_t *sizep) {
	return _IN_sysctl_mibname(name, mibp, sizep);
}
