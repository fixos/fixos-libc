#include <sys/sysctl.h>
#include <bits/inline_syscalls.h>
#include <stddef.h>
#include <errno.h>


/**
 * As FiXos implements sysctl by distinct sysctl_read() and sysctl_write(),
 * we need to call the good one (or both) depending arguments.
 */

int sysctl(const int *name, size_t namelen, void *oldp, size_t *oldlenp,
		const void *newp, size_t newlen)
{
	int ret = 1;

	/*printf("receive sysctl (%d: [", namelen);
	for(int i=0; i<namelen; i++)
		printf("%d%s", name[i], i+1==namelen ? "" : ",");
	printf("]), oldlenp=%p\n", oldlenp);*/

	// oldp may be NULL if caller wants only the size of the given data...
	if(oldp != NULL || oldlenp != NULL) {
		ret = _IN_sysctl_read(name, namelen, oldp, oldlenp);
		//printf("ret=%d, oldlen=%d\n", ret, *oldlenp);
	}
	if(ret >= 0 && newp != NULL) {
		ret = _IN_sysctl_write(name, namelen, newp, newlen);
	}

	// if none read/write, signal an error (EINVAL)
	if(ret == 1) {
		ret = -1;
		errno = EINVAL;
	}

	return ret;
}

