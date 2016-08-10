// ************************************************************************
//
// VLC Configuration File
//
// Sections:
//  . Configurable build flags
//  . Build environment specific flags
//  . Identify the compiler being used
//  . Identify the architecture being targeted
//  . Define file name extension to be used by plugin libraries
//  . C Runtime Library API existence flags
//  . Assembly-level processor optimization flags
//  . External library flags
//  . VLC specific[and generally do not change] build flags
//  . Additional header files
//
// ************************************************************************


#ifndef BUILD_CONFIG_H
#define BUILD_CONFIG_H

// ************************************************************************
//
// Configurable build flags:
//
// ************************************************************************

/* Define to 1 for inline assembly to be enabled */
/* undef HAVE_INLINE_ASM */

/* LUA scripting support */
#define BUILD_LUA                    1

/* HTTP daemon support */
/* #undef BUILD_HTTPD */

/* Skins interface module support */
/* #undef BUILD_SKINS */

/* Define to 1 if translation of program messages to the user's native language is requested. */
#define ENABLE_NLS                   1

/* Define to 1 for stream output support. */
#define ENABLE_SOUT                  1

/* Define if you want the VideoLAN manager support */
#define ENABLE_VLM                   1

/* Define to 1 for dynamic plugins */
#define HAVE_DYNAMIC_PLUGINS         1

/* Define if you want the addons manager modules */
#if defined(HAVE_DYNAMIC_PLUGINS)
#  define ENABLE_ADDONMANAGERMODULES 1
#endif

/* #undef DEFAULT_FONT_FILE */

/* #undef DEFAULT_MONOSPACE_FONT_FILE */

/* #undef DEFAULT_FAMILY */

/* #undef DEFAULT_MONOSPACE_FAMILY */

/* #undef MERGE_FFMPEG */

#define PACKAGE_VERSION_MAJOR        "2"

#define PACKAGE_VERSION_MINOR        "2"

#define PACKAGE_VERSION_REVISION     "4"

#define PACKAGE_VERSION_EXTRA        "0"

#define PACKAGE_VERSION_DEV          ""

#define PACKAGE_VERSION_NAME         "Weatherwax"

#define CONFIGURE_LINE               ""



// ************************************************************************
//
// Build environment specific flags:
//
// ************************************************************************

/* Maximum supported data alignment */
#define ATTRIBUTE_ALIGNED_MAX 64



// ************************************************************************
//
// Identify the compiler being used. Currently supported macro definitions as output:
//   HAVE_GCC         GNU C compiler
//   HAVE_GCC_VERSION Standardized version number of GCC compiler (if HAVE_GCC is defined)
//   HAVE_MSVC        Microsoft Visual C/C++ compiler
//   HAVE_BORLAND     Borland C/C++ compiler
//   HAVE_CLANG       Clang compiler
//   HAVE_MINGW       MinGW32 or MinGW64 compiler
//   VLC_COMPILER     String indicating the name of the compiler being used. 
//
// ************************************************************************
#ifdef __GNUC__
/* Code for GNU C compiler */
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
#  define HAVE_GCC     1
#  define VLC_COMPILER "gcc"
#elif _MSC_VER
/* Code specific to MSVC compiler */
#  define HAVE_MSVC    1
#  define VLC_COMPILER "MSVC"
#elif __BORLANDC__
/* Code specific to Borland compilers */
#  define HAVE_BORLAND 1
#  define VLC_COMPILER "Borland"
#elif __clang__
#  define HAVE_CLANG   1
#  define VLC_COMPILER "Clang"
#elif __MINGW32__ || __MINGW64__
/* Code specific to MinGW compilers */
#  define HAVE_MINGW   1
#  define VLC_COMPILER "mingw"
#endif



// ************************************************************************
//
// Identify the architecture being targeted. Currently supported macro definitions as output:
//   HAVE_WIN64       Microsoft Windows 64-bit
//   HAVE_WIN32       Microsoft Windows 32-bit
//   HAVE_DARWIN      Apple
//   HAVE_IOS         Apple iPhone
//   HAVE_OSX         Apple Mac OS X
//   HAVE_LINUX       Linux
//   _WIN32_WINNT     If target is Microsoft Windows, this is the target version number.
//
// ************************************************************************
#if defined(_WINDOWS)
#  define WIN32_LEAN_AND_MEAN 1
#  if defined(_WIN32) && !defined(_WIN32_WINNT)
#    include <SDKDDKVer.h>
#    if !defined(_WIN32_WINNT)
#      define _WIN32_WINNT 0x0600 /* Windows Vista */
#    endif
#  endif
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



// ************************************************************************
//
// Define file name extension to be used by plugin libraries:
//   LIBEXT           String indicating the OS-dependent file name extension.
//
// ************************************************************************
#if defined(HAVE_WIN32) || defined(HAVE_WIN64)
#  define LIBEXT ".dll"
#elif defined(HAVE_DARWIN)
#  define LIBEXT ".dylib"
#elif defined(HAVE_LINUX)
#  define LIBEXT ".a"
#else
#  define LIBEXT ".so"
#endif



// ************************************************************************
//
// C Runtime Library API existence flags:
//
// ************************************************************************

/* #undef HAVE_DIRFD */

/* #undef HAVE_FDOPENDIR */

/* #undef HAVE_FLOCKFILE */

/* #undef HAVE_FSYNC */

/* #undef HAVE_GETDELIM */

/* #undef HAVE_GMTIME_R */

/* #undef HAVE_LOCALTIME_R */

/* #undef HAVE_NRAND48 */

/* #undef HAVE_POLL */

/* #undef HAVE_POSIX_MEMALIGN */

/* #undef HAVE_SETENV */

/* #undef HAVE_STRCASESTR */

/* #undef HAVE_STRLCPY */

/* #undef HAVE_STRNDUP */

/* #undef HAVE_STRSEP */

/* #undef HAVE_TDESTROY */

/* #undef HAVE_STRVERSCMP */

#if _WIN32_WINNT >= _WIN32_WINNT_VISTA
// Introduced in Windows Vista
#  define HAVE_STRUCT_POLLFD   1
#endif

#if _MSC_VER >= 1900
// Introduced in MSVC 2015
#  define HAVE_STRUCT_TIMESPEC 1 /* Unconfirmed version introduced in */
#  define HAVE_INET_PTON       1 /* Unconfirmed version introduced in */
#endif
#if _MSC_VER >= 1700
// Introduced in MSVC 2013
#  define HAVE_ATOLL           1
#  define HAVE_NANF            1
#  define HAVE_STRTOF          1
#  define HAVE_STRTOLL         1
#endif
#if _MSC_VER >= 1400
// Introduced in MSVC 2005
#  define HAVE_STRNLEN         1
#  define HAVE_STRTOK_R        1
#  define HAVE_STRCASECMP      1
#  define strcasecmp           stricmp
#  define strtok_r             strtok_s
#endif
#if _MSC_VER >= 1310
// Introduced in MSVC 2003
#  define HAVE_ATOF            1
#  define HAVE_GETENV          1
#  define HAVE_GETPID          1
#  define HAVE_LLDIV           1
#  define HAVE_REWIND          1
#  define HAVE_STRDUP          1
#  define HAVE_SWAB            1
#  define strdup               _strdup
#  define swab                 _swab
#  define getpid               _getpid
#endif



// ************************************************************************
//
// Assembly-level processor optimization flags:
//
// ************************************************************************

/* Define to 1 if 3D Now! inline assembly is available. */
#define CAN_COMPILE_3DNOW   1

/* Define to 1 if AltiVec inline assembly is available. */
/* #undef CAN_COMPILE_ALTIVEC */

/* Define to 1 if C AltiVec extensions are available. */
/* #undef CAN_COMPILE_C_ALTIVEC */

/* Define to 1 inline MMX assembly is available. */
#define CAN_COMPILE_MMX     1

/* Define to 1 if MMX EXT inline assembly is available. */
#define CAN_COMPILE_MMXEXT  1

/* Define to 1 if SSE inline assembly is available. */
#define CAN_COMPILE_SSE     1

/* Define to 1 if SSE2 inline assembly is available. */
#define CAN_COMPILE_SSE2    1

/* Define to 1 if SSE3 inline assembly is available. */
#define CAN_COMPILE_SSE3    1

/* Define to 1 if SSE4A inline assembly is available. */
#define CAN_COMPILE_SSE4A   1

/* Define to 1 if SSE4_1 inline assembly is available. */
#define CAN_COMPILE_SSE4_1  1

/* Define to 1 if SSE4_2 inline assembly is available. */
#define CAN_COMPILE_SSE4_2  1

/* Define to 1 if SSSE3 inline assembly is available. */
#define CAN_COMPILE_SSSE3   1

#if defined(HAVE_INLINE_ASM) && defined(CAN_COMPILE_3DNOW)
#  define HAVE_3DNOW           1
#else
/* #undef HAVE_3DNOW */
#endif

#if defined(HAVE_INLINE_ASM) && (defined(CAN_COMPILE_ALTIVEC) || defined(CAN_COMPILE_C_ALTIVEC))
#  define HAVE_ALTIVEC         1
#else
/* #undef HAVE_ALTIVEC */
#endif

#if defined(HAVE_INLINE_ASM) && defined(CAN_COMPILE_MMX)
#  define HAVE_MMX             1
#else
/* #undef HAVE_MMX */
#endif

#if defined(HAVE_INLINE_ASM) && defined(CAN_COMPILE_MMXEXT)
#  define HAVE_MMXEXT          1
#else
/* #undef HAVE_MMXEXT */
#endif

#if defined(HAVE_INLINE_ASM) && defined(CAN_COMPILE_SSE2)
#  define HAVE_SSE2            1
#  define HAVE_SSE2_INTRINSICS 1
#else
/* #undef HAVE_SSE2 */
/* #undef HAVE_SSE2_INTRINSICS */
#endif

/* Define to 1 if ARM NEON assembly is available. */
/* #undef HAVE_NEON */



// ************************************************************************
//
// External library flags:
//
// ************************************************************************

/* Library: alsa (Advanced Linux Sound Architecture); Version: >= 1.0.24 */
/* #undef HAVE_ALSA */

/* Library: gcrypt; Version: >= 1.6.0 */
/* #undef HAVE_GCRYPT */

/* Library: jack; Version: >= 1.9.7 */
/* #undef HAVE_JACK */

/* Library: linux_dvb (Linux DVB); Version: >= 5.2 */
/* #undef HAVE_LINUX_DVB */

/* Library: kai */
/* #undef HAVE_KAI */

/* Library: sndio (OpenBSD sndio module) */
/* #undef HAVE_SNDIO */

/* Library: wasapi ([Windows Audio Session API) */
/* #undef HAVE_WASAPI */

/* Library: zlib */
#define HAVE_ZLIB 1

#if defined(HAVE_ZLIB)
#define HAVE_MINIZIP 1
#else
/* #undef HAVE_MINIZIP */
#endif

/* #undef HAVE_DBUS */

/* #undef HAVE_V4L2 */

/* Blackmagic DeckLink SDI input */
/* #undef HAVE_DECKLINK */

/* #undef HAVE_MAC_SCREEN */

/* #undef HAVE_QTKIT */

/* #undef HAVE_AVFOUNDATION */

/* #undef HAVE_ASDCP */

#define HAVE_DVBPSI 1

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

/* #undef HAVE_OSS */



// ************************************************************************
//
// VLC specific [and generally do not change] build flags:
//
// ************************************************************************

/* Define within the LibVLC source code tree */
#define __LIBVLC__

/* Name of package */
#define PACKAGE           "vlc"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME   "vlc"

/* Define to the home page for this package. */
#define PACKAGE_URL       ""

/* Define to the version of this package. */
#define PACKAGE_VERSION   PACKAGE_VERSION_MAJOR "." PACKAGE_VERSION_MINOR "." PACKAGE_VERSION_REVISION

/* Define to the full name of this package. */
#define PACKAGE_NAME      "vlc"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING    PACKAGE_NAME " " PACKAGE_VERSION

#define VERSION           PACKAGE_VERSION

#define VERSION_MESSAGE   PACKAGE_VERSION " " PACKAGE_VERSION_NAME

#define VLC_COMPILE_BY    "vlc"

#define VLC_COMPILE_HOST  "BUILDBOT"

#define COPYRIGHT_YEARS   "1996-2016"

#define COPYRIGHT_MESSAGE "Copyright © " COPYRIGHT_YEARS " the VideoLAN team"

/* Define to 1 if you want to build for Windows Store apps */
#define VLC_WINSTORE_APP  0

/* Binary specific version */
/* #undef DISTRO_VERSION */

/* Define if you want the HTTP daemon support */
#if defined(BUILD_HTTPD)
// Assume true if building the HTTP daemon
#define ENABLE_HTTPD           1
#else
/* #undef ENABLE_HTTPD */
#endif

/* VLC media player binary */
#if !defined(_LIB) && !defined(_USRDLL)
// Assume true if not building a static or dynamic lib
#  define BUILD_VLC            1
#else
/* #undef BUILD_VLC */
#endif

/* VLC media player OS X application binary */
#if defined(BUILD_VLC) && defined(HAVE_DARWIN)
// Assume true if building binary on a mac
#  define BUILD_MACOSX_VLC_APP 1
#else
/* #undef BUILD_MACOSX_VLC_APP */
#endif

/* MacOS X gui module */
#if defined(HAVE_DARWIN)
// Assume true if building binary on a mac
#  define BUILD_MACOSX_VLC_APP 1
#else
/* #undef BUILD_MACOSX_VLC_APP */
#endif



// ************************************************************************
//
// Additional header files needed globally for compatibility between build environments:
//
// ************************************************************************

#include <stdbool.h>
#include <stdalign.h>
#include <compat.h>
#include <vlc_fixups.h>

#endif /* BUILD_CONFIG_H */