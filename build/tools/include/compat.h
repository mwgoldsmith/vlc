#ifndef BUILD_COMPAT_H
#define BUILD_COMPAT_H

#if defined(_MSC_VER)
#  define __attribute__(x)
#  define restrict          __restrict
#  define strncasecmp       strnicmp
#  define snwprintf         _snwprintf

#  if _MSC_VER < 1900
#    define snprintf        _snprintf
#  endif

#  ifndef __cplusplus
#    define inline          __inline
#  endif

#ifndef _MODE_T_
#define	_MODE_T_
typedef unsigned short _mode_t;

#ifndef	_NO_OLDNAMES
typedef _mode_t	mode_t;
#endif
#endif	/* Not _MODE_T_ */

#ifndef _PID_T_
#define	_PID_T_
typedef int	_pid_t;

#ifndef	_NO_OLDNAMES
typedef _pid_t	pid_t;
#endif
#endif	/* Not _PID_T_ */

#endif /* _MSC_VER */

#ifndef ssize_t
#  define SSIZE_T ssize_t
#endif

#ifndef SSIZE_MAX
# ifdef _WIN64
#  define SSIZE_MAX _I64_MAX
# else
#  define SSIZE_MAX LONG_MAX
# endif
#endif

typedef int        BOOL;
typedef int        WINBOOL;

#define R_OK      04

#define STDIN_FILENO   fileno(stdin)
#define STDOUT_FILENO  fileno(stdout)
#define STDERR_FILENO  fileno(stderr)

#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.78539816339744830962

/*
 * Constants for the stat st_mode member.
 */
#define  _S_IFIFO   0x1000  /* FIFO */
#define  _S_IFCHR   0x2000  /* Character */
#define  _S_IFBLK   0x3000  /* Block: Is this ever set under w32? */
#define  _S_IFDIR   0x4000  /* Directory */
#define  _S_IFREG   0x8000  /* Regular */

#define  _S_IFMT    0xF000  /* File type mask */

#define  _S_IEXEC   0x0040
#define  _S_IWRITE  0x0080
#define  _S_IREAD   0x0100

#define  _S_IRWXU  (_S_IREAD | _S_IWRITE | _S_IEXEC)
#define  _S_IXUSR  _S_IEXEC
#define  _S_IWUSR  _S_IWRITE
#define  _S_IRUSR  _S_IREAD

#define  _S_ISDIR(m)  (((m) & _S_IFMT) == _S_IFDIR)
#define  _S_ISFIFO(m) (((m) & _S_IFMT) == _S_IFIFO)
#define  _S_ISCHR(m)  (((m) & _S_IFMT) == _S_IFCHR)
#define  _S_ISBLK(m)  (((m) & _S_IFMT) == _S_IFBLK)
#define  _S_ISREG(m)  (((m) & _S_IFMT) == _S_IFREG)

#ifndef _NO_OLDNAMES

#define  S_IFIFO    _S_IFIFO
#define  S_IFCHR    _S_IFCHR
#define  S_IFBLK    _S_IFBLK
#define  S_IFDIR    _S_IFDIR
#define  S_IFREG    _S_IFREG
#define  S_IFMT     _S_IFMT
#define  S_IEXEC    _S_IEXEC
#define  S_IWRITE   _S_IWRITE
#define  S_IREAD    _S_IREAD
#define  S_IRWXU    _S_IRWXU
#define  S_IXUSR    _S_IXUSR
#define  S_IWUSR    _S_IWUSR
#define  S_IRUSR    _S_IRUSR

#define  S_ISDIR(m)  (((m) & S_IFMT) == S_IFDIR)
#define  S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define  S_ISCHR(m)  (((m) & S_IFMT) == S_IFCHR)
#define  S_ISBLK(m)  (((m) & S_IFMT) == S_IFBLK)
#define  S_ISREG(m)  (((m) & S_IFMT) == S_IFREG)

#endif  /* Not _NO_OLDNAMES */

#endif/*BUILD_COMPAT_H*/