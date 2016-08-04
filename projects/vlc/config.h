#ifndef CONFIG_H
#define CONFIG_H

#if defined(_WIN32) && !defined(_WIN32_WINNT)
#  include <SDKDDKVer.h>
#  if !defined(_WIN32_WINNT)
#    define _WIN32_WINNT 0x0502 /* Windows XP SP2 */
#  endif
#endif

// ********
// Identify the compiler being used. Currently supported macro definitions as output:
//   HAVE_GCC         GNU C compiler
//   HAVE_GCC_VERSION Standardized version number of GCC compiler (if HAVE_GCC is defined)
//   HAVE_MSVC        Microsoft Visual C/C++ compiler
//   HAVE_BORLAND     Borland C/C++ compiler
//   HAVE_CLANG       Clang compiler
//   HAVE_MINGW       MinGW32 or MinGW64 compiler
// ********
#ifdef __GNUC__
/* Code for GNU C compiler */
#  define HAVE_GCC 1
#  if defined(__GNUC__)
#    if defined(__GNUC_PATCHLEVEL__)
#      define HAVE_GCC_VERSION (__GNUC__ * 10000 \
                               + __GNUC_MINOR__ * 100 \
                               + __GNUC_PATCHLEVEL__)
#    else
#      define HAVE_GCC_VERSION (__GNUC__ * 10000 \
                               + __GNUC_MINOR__ * 100)
#    endif
#  endif
#elif _MSC_VER
/* Code specific to MSVC compiler */
#  define HAVE_MSVC 1
#elif __BORLANDC__
/* Code specific to Borland compilers */
#  define HAVE_BORLAND 1
#elif __clang__
#  define HAVE_CLANG 1
#elif __MINGW32__ || __MINGW64__
/* Code specific to MinGW compilers */
#  define HAVE_MINGW 1
#endif

// ********
// Identify the architecture being targeted. Currently supported macro definitions as output:
//   HAVE_WIN64       Microsoft Windows 64-bit
//   HAVE_WIN32       Microsoft Windows 32-bit
//   HAVE_DARWIN      Apple
//   HAVE_IOS         Apple iPhone
//   HAVE_OSX         Apple Mac OS X
//   HAVE_LINUX       Linux
// ********
#if defined(_WINDOWS)
#  if defined(__x86_64__) || defined(_M_AMD64)
#      define HAVE_WIN64 1
#  elif defined(__i386__) || defined(_M_IX86) || defined(_X86_)
#      define HAVE_WIN32 1
#  else
#    error Cannot determine target architecture
#  endif
#elif defined(__APPLE__) && defined(__MACH__)
// Apple compiler
#  define HAVE_DARWIN 1
#  include <TargetConditionals.h>
#  if TARGET_IPHONE_SIMULATOR == 1
//   iOS in Xcode simulator
#  elif TARGET_OS_IPHONE == 1
#    define HAVE_IOS 1
#  elif TARGET_OS_MAC == 1
#    define HAVE_OSX 1
#  endif
#elif defined(__linux__)
#  define HAVE_LINUX 1
#endif

/* #undef HAVE_SYMBIAN */

/* #undef HAVE_OS2 */

/* #undef HAVE_ANDROID */

/* #undef HAVE_WINSTORE */

#define __LIBVLC__

/* #undef DISTRO_VERSION */

#define VLC_WINSTORE_APP 0

#define ATTRIBUTE_ALIGNED_MAX 64

/* #undef DEFAULT_FONT_FILE */

/* #undef DEFAULT_MONOSPACE_FONT_FILE */

/* #undef DEFAULT_FAMILY */

/* #undef DEFAULT_MONOSPACE_FAMILY */

#define VERSION "2.2.4"

#define VERSION_MESSAGE "2.2.4 Weatherwax"

#define COPYRIGHT_MESSAGE "Copyright © 1996-2016 the VideoLAN team"

#define COPYRIGHT_YEARS "1996-2016"

#define CONFIGURE_LINE "${CONFIGURE_LINE}"

/* Name of package */
#define PACKAGE "vlc"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "vlc"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "vlc 2.2.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "vlc"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.2.4"

#define PACKAGE_VERSION_MAJOR 2

#define PACKAGE_VERSION_MINOR 2

#define PACKAGE_VERSION_REVISION 4

#define PACKAGE_VERSION_EXTRA 0

#define PACKAGE_VERSION_DEV ""

#define VLC_COMPILE_BY "vlc"

#define VLC_COMPILE_HOST "BUILDBOT"

#define VLC_COMPILER "MSVC"

#define HAVE_DYNAMIC_PLUGINS 1

#define HAVE_ZLIB 1

#define HAVE_MINIZIP 1

/* #undef HAVE_DBUS */

#define HAVE_MMX 1

#define HAVE_MMXEXT 1

#define HAVE_SSE2 1

/* #undef HAVE_3DNOW */

/* #undef HAVE_NEON */

/* #undef HAVE_ALTIVEC */

#define ENABLE_SOUT 1

#define BUILD_LUA 1

/* #undef BUILD_HTTPD */

#define ENABLE_VLM 1

#define ENABLE_ADDONMANAGERMODULES 1

/* #undef HAVE_V4L2 */

/* #undef HAVE_DECKLINK */

/* #undef HAVE_LINUX_DVB */

/* #undef HAVE_MAC_SCREEN */

/* #undef HAVE_QTKIT */

/* #undef HAVE_AVFOUNDATION */

/* #undef HAVE_ASDCP */

#define HAVE_DVBPSI 1

/* #undef MERGE_FFMPEG */

/* #undef HAVE_GST_DECODE */

#define HAVE_AVCODEC 1

/* #undef HAVE_VAAPI_DRM */

/* #undef HAVE_VAAPI_X11 */

#define HAVE_AVCODEC_VAAPI 1

/* #undef HAVE_AVCODEC_DXVA2 */

#define HAVE_AVCODEC_VDA 1

#define HAVE_AVFORMAT 1

#define HAVE_SPEEXDSP 1

/* #undef HAVE_EGL */

/* #undef HAVE_GL */

/* #undef HAVE_XCB */

/* #undef HAVE_XCB_KEYSYMS */

/* #undef HAVE_XCB_RANDR */

/* #undef HAVE_XCB_XVIDEO */

/* #undef HAVE_VDPAU */

/* #undef HAVE_AVCODEC_VDPAU */

/* #undef HAVE_DIRECTX */

/* #undef HAVE_KVA */

/* #undef HAVE_PULSE */

/* #undef HAVE_ALSA */

/* #undef HAVE_OSS */

/* #undef HAVE_SNDIO */

/* #undef HAVE_WASAPI */

/* #undef HAVE_JACK */

/* #undef HAVE_KAI */

/* #undef ENABLE_QT4 */

/* #undef BUILD_SKINS */

/* #undef ENABLE_MACOSX_UI */

/* #undef ENABLE_MINIMAL_MACOSX */

/* #undef ENABLE_MACOSX_DIALOG_PROVIDER */

/* #undef HAVE_GCRYPT */

/* #undef KDE_SOLID */

/* #undef BUILD_VLC */

/* #undef BUILD_MACOSX_VLC_APP */

#define HAVE_ATOF 1

#define HAVE_ATOLL 1

/* #undef HAVE_DIRFD */

/* #undef HAVE_FDOPENDIR */

/* #undef HAVE_FLOCKFILE */

/* #undef HAVE_FSYNC */

/* #undef HAVE_GETDELIM */

#define HAVE_GETPID 1

/* #undef HAVE_GMTIME_R */

#define HAVE_LLDIV 1

/* #undef HAVE_LOCALTIME_R */

/* #undef HAVE_NRAND48 */

/* #undef HAVE_POLL */

/* #undef HAVE_POSIX_MEMALIGN */

#define HAVE_REWIND 1

/* #undef HAVE_SETENV */

#define HAVE_STRCASECMP 1

/* #undef HAVE_STRCASESTR */

#define HAVE_STRDUP 1

/* #undef HAVE_STRLCPY */

/* #undef HAVE_STRNDUP */

#define HAVE_STRNLEN 1

/* #undef HAVE_STRSEP */

#define HAVE_STRTOF 1

/* #undef HAVE_STRTOK_R */

#define HAVE_STRTOLL 1

#define HAVE_SWAB 1

/* #undef HAVE_TDESTROY */

/* #undef HAVE_STRVERSCMP */

/* Define to 1 if 3D Now! inline assembly is available. */
#define CAN_COMPILE_3DNOW 1

/* Define to 1 if AltiVec inline assembly is available. */
/* #undef CAN_COMPILE_ALTIVEC */

/* Define to 1 if C AltiVec extensions are available. */
/* #undef CAN_COMPILE_C_ALTIVEC */

/* Define to 1 inline MMX assembly is available. */
#define CAN_COMPILE_MMX 1

/* Define to 1 if MMX EXT inline assembly is available. */
#define CAN_COMPILE_MMXEXT 1

/* Define to 1 if SSE inline assembly is available. */
#define CAN_COMPILE_SSE 1

/* Define to 1 if SSE2 inline assembly is available. */
#define CAN_COMPILE_SSE2 1

/* Define to 1 if SSE3 inline assembly is available. */
#define CAN_COMPILE_SSE3 1

/* Define to 1 if SSE4A inline assembly is available. */
#define CAN_COMPILE_SSE4A 1

/* Define to 1 if SSE4_1 inline assembly is available. */
#define CAN_COMPILE_SSE4_1 1

/* Define to 1 if SSE4_2 inline assembly is available. */
#define CAN_COMPILE_SSE4_2 1

/* Define to 1 if SSSE3 inline assembly is available. */
#define CAN_COMPILE_SSSE3 1

#include <compat.h>
#include <vlc_fixups.h>

#endif