/* ************************************************************** */
/* *** hunny's Common Library - Filesystem Accesser           *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : filesys.c                                     *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/05 (0.01)                             *** */
/* ************************************************************** */

#define		_FILESYS_C

#define		WINVER			(0x0500)		/* Windows98 and Windows2000 or later */

#include	<windows.h>
#include	<shlwapi.h>

#include	<stdlib.h>

#include	"filesys.h"

char *
filesys_getFilename( const char *inPath )
{
	return (char*)PathFindFileName( (LPCTSTR)inPath ) ;
}
