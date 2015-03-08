#include <sys/sysctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// for struct proc_uinfo
#include <fixos/process.h>


/**
 * Minimalist top-like program, using sysctl() calls.
 */


// helper to read a sysctl value by name, as a string
static void read_sysctl_str(const char *name, char *buf, int len) {
	size_t size;

	size = len-1;
	if(!sysctlbyname(name, buf, &size, NULL, 0))
		buf[size] = '\0';
	else
		buf[0] = '\0';

}

static void test_print_sysinfo() {
	char ostype[32];
	char osrelease[32];
	char osbuilddate[32];
	char machine[32];

	read_sysctl_str("kern.ostype", ostype, sizeof(ostype));
	read_sysctl_str("kern.osrelease", osrelease, sizeof(osrelease));
	read_sysctl_str("kern.osbuilddate", osbuilddate, sizeof(osbuilddate));
	read_sysctl_str("hw.machine", machine, sizeof(machine));

	printf(	"Kernel informations (sysctl) :\n"
			"%s %s (%s), hw: %s\n", ostype, osrelease, osbuilddate, machine);
}

static const char *state_string(int state) {
	switch(state) {
	case PROCESS_STATE_RUNNING:
		return "R";
	case PROCESS_STATE_CREATE:
		return "C";
	case PROCESS_STATE_ZOMBIE:
		return "Z";
	case PROCESS_STATE_STOPPED:
		return "T";
	case PROCESS_STATE_INTERRUPTIBLE:
		return "S";
	case PROCESS_STATE_UNINTERRUPTIBLE:
		return "D";
	}
	return "?";
}


static void print_all_proc() {
	static struct proc_uinfo *proc_array = NULL;
	const int mib[3] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL};

	size_t size = 0;

	// get the number of process and realloc proc_array
	sysctl(mib, 3, NULL, &size, NULL, 0);
	proc_array = realloc(proc_array, size);

	// retrieve all process infos
	if(sysctl(mib, 3, proc_array, &size, NULL, 0) == 0) {
		int i;
		int nb;

		nb = size/sizeof(struct proc_uinfo);

		// print various "general" infos
		int trunning = 0;
		int tsleeping = 0;
		for(i=0; i<nb; i++) {
			if(proc_array[i].state == PROCESS_STATE_RUNNING)
				trunning++;
			else if(proc_array[i].state == PROCESS_STATE_INTERRUPTIBLE
					|| proc_array[i].state == PROCESS_STATE_UNINTERRUPTIBLE)
				tsleeping++;
		}
		printf("T: %d Total, %d Run, %d Sleep\n", nb, trunning, tsleeping);
		
		for(i=0; i<nb; i++) {
			struct proc_uinfo *proc = & proc_array[i];

			printf("pid %d : %s, cpu=%d%%, {%d,%d}\n",
					proc->pid, state_string(proc->state), 
					proc->cpu_usage / 100, proc->uticks, proc->kticks);
		}
	}
	else {
		printf("sysctl() error, with size=%d\n", size);
	}
}


int main(int argc, char **argv) {
	const struct timespec refreshtime = {.tv_nsec = 500000000, .tv_sec = 0 };
	test_print_sysinfo();
	while(1) {
		// erase screen and set cursor to HOME (will be flushed later)
		printf("\x1B[2J\x1B[H");
		print_all_proc();
		nanosleep(&refreshtime, NULL);
	}
	exit(0);
}
