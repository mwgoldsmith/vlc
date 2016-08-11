/*****************************************************************************
 * vlc_fixups.h: portability fixups included from config.h
 *****************************************************************************
 * Copyright © 1998-2008 the VideoLAN project
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/**
 * \file
 * This file is a collection of portability fixes
 */

#ifndef LIBVLC_FIXUPS_H
# define LIBVLC_FIXUPS_H 1

/* needed to detect uClibc */
#ifdef HAVE_FEATURES_H
#include <features.h>
#endif

/* C++11 says there's no need to define __STDC_*_MACROS when including
 * inttypes.h and stdint.h. */
#if defined (__cplusplus) && (!defined(HAVE_CXX11) || defined(__MINGW32__) || defined(__UCLIBC__))
# ifndef __STDC_FORMAT_MACROS
#  define __STDC_FORMAT_MACROS 1
# endif
# ifndef __STDC_CONSTANT_MACROS
#  define __STDC_CONSTANT_MACROS 1
# endif
# ifndef __STDC_LIMIT_MACROS
#  define __STDC_LIMIT_MACROS 1
# endif
#endif

 // ************************************************************************
 //
 // Define external linkage:
 //   COMPAT_API       Defines linkage to use for external symbols
 //
 // ************************************************************************
#ifdef __cplusplus
# define COMPAT_EXTERN extern "C"
#else
# define COMPAT_EXTERN
#endif

#if (defined(HAVE_WIN32) || defined(HAVE_WIN64))
#  if defined(COMPAT_DLL_EXPORT)
#    define COMPAT_EXPORT __declspec(dllexport)
#  else
#    if defined(_USRDLL)
#      define COMPAT_EXPORT __declspec(dllimport)
#    else
#      define COMPAT_EXPORT 
#    endif
#  endif
#elif TEST_GCC_VERSION(4,0)
# define COMPAT_EXPORT __attribute__((visibility("default")))
#else
# define COMPAT_EXPORT
#endif

#define COMPAT_API     COMPAT_EXTERN COMPAT_EXPORT


#if !defined (HAVE_GMTIME_R) || !defined (HAVE_LOCALTIME_R) \
 || !defined (HAVE_TIMEGM)
# include <time.h> /* time_t */
#endif

#ifndef HAVE_GETTIMEOFDAY
#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/time.h>
#endif
#endif

#ifndef HAVE_LLDIV
typedef struct
{
    long long quot; /* Quotient. */
    long long rem;  /* Remainder. */
} lldiv_t;
#endif

#if !defined(HAVE_GETENV) || \
    !defined(HAVE_USELOCALE)
# include <stddef.h> /* NULL */
#endif

#if !defined (HAVE_REWIND) || \
    !defined (HAVE_GETDELIM)
# include <stdio.h> /* FILE */
#endif

#if !defined (HAVE_POSIX_MEMALIGN) || \
    !defined (HAVE_MEMRCHR) || \
    !defined (HAVE_STRLCPY) || \
    !defined (HAVE_STRNDUP) || \
    !defined (HAVE_STRNLEN) || \
    !defined (HAVE_STRNSTR)
# include <stddef.h> /* size_t */
#endif

#ifndef HAVE_VASPRINTF
# include <stdarg.h> /* va_list */
#endif

#if !defined (HAVE_GETDELIM) || \
    !defined (HAVE_GETPID)   || \
    !defined (HAVE_SWAB)
# include <sys/types.h> /* ssize_t, pid_t */
#endif

#if !defined (HAVE_DIRFD) || \
    !defined (HAVE_FDOPENDIR)
# include <dirent.h>
#endif

#ifdef __cplusplus
# define VLC_NOTHROW throw ()
extern "C" {
#else
# define VLC_NOTHROW
#endif

/* stdio.h */
#ifndef HAVE_ASPRINTF
COMPAT_API int asprintf (char **, const char *, ...);
#endif

#ifndef HAVE_FLOCKFILE
COMPAT_API void flockfile (FILE *);
COMPAT_API int ftrylockfile (FILE *);
COMPAT_API void funlockfile (FILE *);
COMPAT_API int getc_unlocked (FILE *);
COMPAT_API int getchar_unlocked (void);
COMPAT_API int putc_unlocked (int, FILE *);
COMPAT_API int putchar_unlocked (int);
#endif

#ifndef HAVE_GETDELIM
COMPAT_API ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
COMPAT_API ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
#endif

#ifndef HAVE_REWIND
COMPAT_API void rewind (FILE *);
#endif

#ifndef HAVE_VASPRINTF
COMPAT_API int vasprintf (char **, const char *, va_list);
#endif

/* string.h */
#ifndef HAVE_FFSLL
COMPAT_API int ffsll(unsigned long long);
#endif

#ifndef HAVE_MEMRCHR
COMPAT_API void *memrchr(const void *, int, size_t);
#endif

#ifndef HAVE_STRCASECMP
COMPAT_API int strcasecmp (const char *, const char *);
#endif

#ifndef HAVE_STRCASESTR
COMPAT_API char *strcasestr (const char *, const char *);
#endif

#ifndef HAVE_STRDUP
COMPAT_API char *strdup (const char *);
#endif

#ifndef HAVE_STRVERSCMP
COMPAT_API int strverscmp (const char *, const char *);
#endif

#ifndef HAVE_STRNLEN
COMPAT_API size_t strnlen (const char *, size_t);
#endif

#ifndef HAVE_STRNSTR
COMPAT_API char * strnstr (const char *, const char *, size_t);
#endif

#ifndef HAVE_STRNDUP
COMPAT_API char *strndup (const char *, size_t);
#endif

#ifndef HAVE_STRLCPY
COMPAT_API size_t strlcpy (char *, const char *, size_t);
#endif

#ifndef HAVE_STRSEP
COMPAT_API char *strsep (char **, const char *);
#endif

#ifndef HAVE_STRTOK_R
COMPAT_API char *strtok_r(char *, const char *, char **);
#endif

/* stdlib.h */
#ifndef HAVE_ATOF
#ifndef __ANDROID__
COMPAT_API double atof (const char *);
#endif
#endif

#ifndef HAVE_ATOLL
COMPAT_API long long atoll (const char *);
#endif

#ifndef HAVE_LLDIV
COMPAT_API lldiv_t lldiv (long long, long long);
#endif

#ifndef HAVE_STRTOF
#ifndef __ANDROID__
COMPAT_API float strtof (const char *, char **);
#endif
#endif

#ifndef HAVE_STRTOLL
COMPAT_API long long int strtoll (const char *, char **, int);
#endif

/* time.h */
#ifndef HAVE_GMTIME_R
COMPAT_API struct tm *gmtime_r (const time_t *, struct tm *);
#endif

#ifndef HAVE_LOCALTIME_R
COMPAT_API struct tm *localtime_r (const time_t *, struct tm *);
#endif

#ifndef HAVE_TIMEGM
COMPAT_API time_t timegm(struct tm *);
#endif

#ifndef HAVE_TIMESPEC_GET
#define TIME_UTC 1
struct timespec;
COMPAT_API int timespec_get(struct timespec *, int);
#endif

/* sys/time.h */
#ifndef HAVE_GETTIMEOFDAY
struct timezone;
COMPAT_API int gettimeofday(struct timeval *, struct timezone *);
#endif

/* unistd.h */
#ifndef HAVE_GETPID
COMPAT_API pid_t getpid (void) VLC_NOTHROW;
#endif

#ifndef HAVE_FSYNC
COMPAT_API int fsync (int fd);
#endif

/* dirent.h */
#ifndef HAVE_DIRFD
COMPAT_API int (dirfd) (DIR *);
#endif

#ifndef HAVE_FDOPENDIR
COMPAT_API DIR *fdopendir (int);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/* stdlib.h */
#ifndef HAVE_GETENV
static inline char *getenv (const char *name)
{
    (void)name;
    return NULL;
}
#endif

#ifndef HAVE_SETENV
COMPAT_API int setenv (const char *, const char *, int);
COMPAT_API int unsetenv (const char *);
#endif

#ifndef HAVE_POSIX_MEMALIGN
COMPAT_API int posix_memalign (void **, size_t, size_t);
#endif

/* locale.h */
#ifndef HAVE_USELOCALE
#define LC_ALL_MASK      0
#define LC_NUMERIC_MASK  0
#define LC_MESSAGES_MASK 0
#define LC_GLOBAL_LOCALE ((locale_t)(uintptr_t)1)
typedef void *locale_t;
static inline locale_t uselocale(locale_t loc)
{
    (void)loc;
    return NULL;
}
static inline void freelocale(locale_t loc)
{
    (void)loc;
}
static inline locale_t newlocale(int mask, const char * locale, locale_t base)
{
    (void)mask; (void)locale; (void)base;
    return NULL;
}
#endif

#if !defined (HAVE_STATIC_ASSERT) && !defined(__cpp_static_assert)
# define STATIC_ASSERT_CONCAT_(a, b) a##b
# define STATIC_ASSERT_CONCAT(a, b) STATIC_ASSERT_CONCAT_(a, b)
# define _Static_assert(x, s) extern char STATIC_ASSERT_CONCAT(static_assert_, __LINE__)[sizeof(struct { unsigned:-!(x); })]
# define static_assert _Static_assert
#endif

/* Alignment of critical static data structures */
#ifdef ATTRIBUTE_ALIGNED_MAX
#   define ATTR_ALIGN(align) __attribute__ ((__aligned__ ((ATTRIBUTE_ALIGNED_MAX < align) ? ATTRIBUTE_ALIGNED_MAX : align)))
#else
#   define ATTR_ALIGN(align)
#endif

/* libintl support */
#define _(str)            vlc_gettext (str)
#define N_(str)           gettext_noop (str)
#define gettext_noop(str) (str)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HAVE_SWAB
COMPAT_API void swab (const void *, void *, ssize_t);
#endif

/* Socket stuff */
#ifndef HAVE_INET_PTON
# ifndef _WIN32
#  include <sys/socket.h>
#else
typedef int socklen_t;
# endif
COMPAT_API int inet_pton(int, const char *, void *);
COMPAT_API const char *inet_ntop(int, const void *, char *, socklen_t);
#endif

#ifndef HAVE_STRUCT_POLLFD
enum
{
    POLLERR=0x1,
    POLLHUP=0x2,
    POLLNVAL=0x4,
    POLLWRNORM=0x10,
    POLLWRBAND=0x20,
    POLLRDNORM=0x100,
    POLLRDBAND=0x200,
    POLLPRI=0x400,
};
#define POLLIN  (POLLRDNORM|POLLRDBAND)
#define POLLOUT (POLLWRNORM|POLLWRBAND)

struct pollfd
{
    int fd;
    unsigned events;
    unsigned revents;
};
#endif
#ifndef HAVE_POLL
struct pollfd;
COMPAT_API int poll (struct pollfd *, unsigned, int);
#endif

#ifndef HAVE_IF_NAMEINDEX
#include <errno.h>
struct if_nameindex
{
    unsigned if_index;
    char    *if_name;
};
# ifndef HAVE_IF_NAMETOINDEX
#  define if_nametoindex(name)   atoi(name)
# endif
# define if_nameindex()         (errno = ENOBUFS, NULL)
# define if_freenameindex(list) (void)0
#endif

#ifndef HAVE_STRUCT_TIMESPEC
struct timespec {
    time_t  tv_sec;   /* Seconds */
    long    tv_nsec;  /* Nanoseconds */
};
#endif

#ifdef _WIN32
struct iovec
{
    void  *iov_base;
    size_t iov_len;
};
#define IOV_MAX 255
struct msghdr
{
    void         *msg_name;
    size_t        msg_namelen;
    struct iovec *msg_iov;
    size_t        msg_iovlen;
    void         *msg_control;
    size_t        msg_controllen;
    int           msg_flags;
};
#endif

#ifndef HAVE_RECVMSG
struct msghdr;
COMPAT_API ssize_t recvmsg(int, struct msghdr *, int);
#endif

#ifndef HAVE_SENDMSG
struct msghdr;
COMPAT_API ssize_t sendmsg(int, const struct msghdr *, int);
#endif

/* search.h */
#ifndef HAVE_SEARCH_H
typedef struct entry {
    char *key;
    void *data;
} ENTRY;

typedef enum {
    FIND, ENTER
} ACTION;

typedef enum {
    preorder,
    postorder,
    endorder,
    leaf
} VISIT;

COMPAT_API void *tsearch( const void *key, void **rootp, int(*cmp)(const void *, const void *) );
COMPAT_API void *tfind( const void *key, const void **rootp, int(*cmp)(const void *, const void *) );
COMPAT_API void *tdelete( const void *key, void **rootp, int(*cmp)(const void *, const void *) );
COMPAT_API void twalk( const void *root, void(*action)(const void *nodep, VISIT which, int depth) );
COMPAT_API void tdestroy( void *root, void (*free_node)(void *nodep) );
#else // HAVE_SEARCH_H
# ifndef HAVE_TDESTROY
COMPAT_API void vlc_tdestroy( void *, void (*)(void *) );
#  define tdestroy vlc_tdestroy
# endif
#endif

/* Random numbers */
#ifndef HAVE_NRAND48
COMPAT_API double erand48 (unsigned short subi[3]);
COMPAT_API long jrand48 (unsigned short subi[3]);
COMPAT_API long nrand48 (unsigned short subi[3]);
#endif

#ifdef __OS2__
# undef HAVE_FORK   /* Implementation of fork() is imperfect on OS/2 */

struct addrinfo
{
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    size_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
    struct addrinfo *ai_next;
};

COMPAT_API void freeaddrinfo (struct addrinfo *res);
#endif

/* math.h */

#ifndef HAVE_NANF
#  define nanf(tagp) NAN
#endif

#ifdef _WIN32
FILE *vlc_win32_tmpfile(void);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !LIBVLC_FIXUPS_H */
