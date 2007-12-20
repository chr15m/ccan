#ifndef CCAN_CONTAINER_OF_H
#define CCAN_CONTAINER_OF_H
#include <stddef.h>

#include "config.h"
#include "check_type/check_type.h"

/**
 * container_of - get pointer to enclosing structure
 * @member_ptr: pointer to the structure member
 * @containing_type: the type this member is within
 * @member: the name of this member within the structure.
 *
 * Given a pointer to a member of a structure, this macro does pointer
 * subtraction to return the pointer to the enclosing type.
 *
 * Example:
 *	struct info
 *	{
 *		int some_other_field;
 *		struct foo my_foo;
 *	};
 *
 *	struct info *foo_to_info(struct foo *foop)
 *	{
 *		return container_of(foo, struct info, my_foo);
 *	}
 */
#define container_of(member_ptr, containing_type, member)		\
	 ((containing_type *)						\
	  ((char *)(member_ptr) - offsetof(containing_type, member))	\
	  - check_types_match(*(member_ptr), ((containing_type *)0)->member))


#endif /* CCAN_CONTAINER_OF_H */