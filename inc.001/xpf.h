/* ************************************************************** */
/* *** hunny's Common Library - Closs platform definitions.   *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2006.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : xpf.h                                         *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2006/08/30 (3.00)                             *** */
/* ************************************************************** */

#ifndef		_XPF_H
#define		_XPF_H

#include	<stdlib.h>

#ifdef	WIN32
#define		sleep(s)		Sleep((DWORD)s*1000)		/* winbase.h */
#endif

#ifdef	VC
#define		snprintf		_snprintf					/* stdio.h */
#define		vsnprintf		_vsnprintf					/* stdio.h */
#define		access			_access						/* io.h */
#define		strupr			_strupr						/* string.h */
#define		strlwr			_strlwr						/* string.h */
#define		MAX_PATH		_MAX_PATH					/* stdlib.h */
#define		MAX_FNAME		_MAX_FNAME					/* stdlib.h */
#endif

#ifdef	GNU_C
#define		stricmp			strcasecmp					/* string.h */
#define		strnicmp		strncasecmp					/* string.h */
#endif

#endif
