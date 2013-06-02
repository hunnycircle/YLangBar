/* ************************************************************** */
/* *** hunny's Common Library - Debug logger                  *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : debuglog.c                                    *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/06 (0.01)                             *** */
/* ************************************************************** */

#define		_DEBUGLOG_C

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"date.h"
#include	"filesys.h"
#include	"xpf.h"

#include	"debuglog.h"

#define		MODE_APLUS			"ab+"

static int	putfunc( const char *, int, const char *, const char * ) ;

static char		*g_pFilename		= NULL ;

int
debuglog_init( const char *inSource, int inLine, const char *inProductName, const char *inFilename )
{
	int			retval		= -1 ;

	char		*source ;
	FILE		*fp			= NULL ;

	DATE_INFO	today ;

	if( (g_pFilename = strdup( inFilename )) == NULL ) {
		goto ERROR_EXCEPTION ;
	}

	if( date_getToday( &today ) != RESULT_NO_ERROR ) {
		goto ERROR_EXCEPTION ;
	}

	if( (fp = fopen( g_pFilename, MODE_APLUS )) ==  NULL ) {
		goto ERROR_EXCEPTION ;
	}

	source = filesys_getFilename( inSource ) ;

	fprintf( fp, "%-16s(%4d): Starting %s at %4d/%02d/%02d %02d:%02d:%02d\n",
		(source) ? source : "(NULL)",
		inLine, inProductName,
		(int)(today.m_sYear), (int)(today.m_cMonth),  (int)(today.m_cDay),
		(int)(today.m_cHour), (int)(today.m_cMinute), (int)(today.m_cSecond)
	) ;

	retval = 0 ;

ERROR_EXCEPTION:

	if( fp ) fclose( fp ) ;

	return retval ;
}


int
debuglog_terminate( const char *inSource, int inLine, const char *inProductName )
{
	int			retval		= -1 ;

	char		*source ;
	FILE		*fp			= NULL ;

	DATE_INFO	today ;

	if( !g_pFilename ) goto ERROR_EXCEPTION ;

	if( date_getToday( &today ) != RESULT_NO_ERROR ) {
		goto ERROR_EXCEPTION ;
	}

	if( (fp = fopen( g_pFilename, MODE_APLUS )) ==  NULL ) {
		goto ERROR_EXCEPTION ;
	}

	source = filesys_getFilename( inSource ) ;

	fprintf( fp, "%-16s(%4d): End of %s\n",
		(source) ? source : "(NULL)",
		inLine, inProductName
	) ;

	retval = 0 ;

ERROR_EXCEPTION:

	if( fp ) {
		fclose( fp ) ;
		fp = NULL ;
	}

	if( g_pFilename ) {
		free( g_pFilename ) ;
		g_pFilename = NULL ;
	}

	return retval ;
}


static int
putfunc( const char *inSource, int inLine, const char *inFunction, const char *inDir )
{
	int		retval	= -1 ;

	char	*source ;
	FILE	*fp		= NULL ;

	if( (fp = fopen( g_pFilename, MODE_APLUS )) == NULL ) {
		goto ERROR_EXCEPTION ;
	}

	source = filesys_getFilename( inSource ) ;

	fprintf( fp, "%-16s(%4d): %s %s\n", 
		(source) ? source : "(NULL)",
		inLine, 
		inDir,
		inFunction
	) ;

	retval = 0 ;

ERROR_EXCEPTION:

	if( fp ) fclose( fp ) ;

	return retval ;
}


int
debuglog_enterFunction( const char *inSource, int inLine, const char *inFunction )
{
	int retval = -1 ;

	if( g_pFilename ) {
		retval = putfunc( inSource, inLine, inFunction, "=>" ) ;
	}

	return retval ;
}


int
debuglog_returnFunction( const char *inSource, int inLine, const char *inFunction )
{
	int retval = -1 ;

	if( g_pFilename ) {
		retval = putfunc( inSource, inLine, inFunction, "<=" ) ;
	}

	return retval ;
}


int
debuglog_printString( const char *inSource, int inLine, const char *inSubject, const char *inValue )
{
	int		retval	= -1 ;

	char	*source ;
	FILE	*fp		= NULL ;

	if( !g_pFilename ) goto ERROR_EXCEPTION ;

	if( (fp = fopen( g_pFilename, MODE_APLUS )) == NULL ) {
		goto ERROR_EXCEPTION ;
	}

	source = filesys_getFilename( inSource ) ;

	if( inSubject ) {
		fprintf( fp, "%-16s(%4d): %s=%s\n",
			(source) ? source : "(NULL)",
			inLine,
			inSubject,
			(inValue) ? inValue : "(NULL)"
		) ;
	} else {
		fprintf( fp, "%-16s(%4d): %s\n",
			(source) ? source : "(NULL)",
			inLine,
			(inValue) ? inValue : "(NULL)"
		) ;
	}

	retval = 0 ;

ERROR_EXCEPTION:

	if( fp ) fclose( fp ) ;

	return retval ;
}


int
debuglog_printValue( const char *inSource, int inLine, const char *inSubject, long inValue )
{
	int		retval	= -1 ;

	char	*source ;
	FILE	*fp		= NULL ;

	if( !g_pFilename ) goto ERROR_EXCEPTION ;

	if( (fp = fopen( g_pFilename, MODE_APLUS )) == NULL ) {
		goto ERROR_EXCEPTION ;
	}

	source = filesys_getFilename( inSource ) ;

	if( inSubject ) {
		fprintf( fp, "%-16s(%4d): %s=%ld\n",
			(source) ? source : "(NULL)",
			inLine, inSubject, inValue
		) ;
	} else {
		fprintf( fp, "%-16s(%4d): %ld\n",
			(source) ? source : "(NULL)",
			inLine, inValue
		) ;
	}

	retval = 0 ;

ERROR_EXCEPTION:

	if( fp ) fclose( fp ) ;

	return retval ;
}
