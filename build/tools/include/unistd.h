#ifndef UNISTD_H_
#define UNISTD_H_

#ifndef _MSC_VER
#   include_next <unistd.h>
#else

#ifndef __STRICT_ANSI__

#include <stdlib.h>
#include <process.h>
#include <direct.h>
#include <fcntl.h>

#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
//#define   X_OK    1       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */

#define STDIN_FILENO   fileno(stdin)
#define STDOUT_FILENO  fileno(stdout)
#define STDERR_FILENO  fileno(stderr)

#define srandom srand
#define random rand

#ifndef _MODE_T_
#define	_MODE_T_
typedef unsigned short _mode_t;

#ifndef	_NO_OLDNAMES
typedef _mode_t	mode_t;
#endif  /* Not _NO_OLDNAMES */
#endif	/* Not _MODE_T_ */

#endif /* __STRICT_ANSI__ */

#endif /* _MSC_VER */

#endif /* UNISTD_H_ */