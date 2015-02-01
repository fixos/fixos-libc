#include <sys/sysctl.h>
#include <bits/inline_syscalls.h>
#include <stddef.h>

/**
 * Use the two other defined sysctlxxx functions to implement naively this one.
 */

// max number of components in MIB name (should be enough!)
#define SYSCTLBYNAME_MAX 10

int sysctlbyname(const char *name, void *oldp, size_t *oldlenp,
		const void *newp, size_t newlen)
{
	size_t mibsize;
	int mib[SYSCTLBYNAME_MAX];

	mibsize = SYSCTLBYNAME_MAX;
	if(sysctlnametomib(name, mib, &mibsize) == 0) {
		return sysctl(mib, mibsize, oldp, oldlenp, newp, newlen);
	}

	return -1;
}

