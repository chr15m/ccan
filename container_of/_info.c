#include <stdio.h>
#include <string.h>
#include "config.h"

/**
 * container_of - routine for upcasting
 *
 * It is often convenient to create code where the caller registers a pointer
 * to a generic structure and a callback.  The callback might know that the
 * pointer points to within a larger structure, and container_of gives a
 * convenient and fairly type-safe way of returning to the enclosing structure.
 *
 * This idiom is an alternative to providing a void * pointer for every
 * callback.
 *
 * Example:
 *	struct info
 *	{
 *		int my_stuff;
 *		struct timer timer;
 *	};
 *
 *	static void my_timer_callback(struct timer *timer)
 *	{
 *		struct info *info = container_of(timer, struct info, timer);
 *		printf("my_stuff is %u\n", info->my_stuff);
 *	}
 *
 *	int main()
 *	{
 *		struct info info = { .my_stuff = 1 };
 *
 *		register_timer(&info.timer);
 *		...
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;

	if (strcmp(argv[1], "depends") == 0) {
		printf("check_type\n");
		return 0;
	}

	return 1;
}