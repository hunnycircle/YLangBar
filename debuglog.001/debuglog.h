/* ************************************************************** */
/* *** hunny's Common Library - Debug logger                  *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2004.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : debuglog.h                                    *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2004/12/26 (2.00)                             *** */
/* ************************************************************** */

#ifndef		_DEBUGLOG_H
#define		_DEBUGLOG_H

#ifdef	__cplusplus
extern "C" {
#endif

int			debuglog_init( const char *, int, const char *, const char * ) ;
int			debuglog_terminate( const char *, int, const char * ) ;
int			debuglog_enterFunction( const char *, int, const char * ) ;
int			debuglog_returnFunction( const char *, int, const char * ) ;
int			debuglog_printString( const char *, int, const char *, const char * ) ;
int			debuglog_printValue( const char *, int, const char *, long ) ;

#ifdef	_USE_DEBUGLOG
#define		DEBUGLOG_INIT(s,p)				debuglog_init( __FILE__, __LINE__, (const char *)s, (const char *)p )
#define		DEBUGLOG_TERMINATE(s)			debuglog_terminate( __FILE__, __LINE__, (const char *)s )
#define		DEBUGLOG_ENTER_FUNCTION(p)		debuglog_enterFunction( __FILE__, __LINE__, (const char *)p )
#define		DEBUGLOG_RETURN_FUNCTION(p)		debuglog_returnFunction( __FILE__, __LINE__, (const char *)p )
#define		DEBUGLOG_PRINT_STRING(s,p)		debuglog_printString( __FILE__, __LINE__, (const char *)s, (const char *)p )
#define		DEBUGLOG_PRINT_VALUE(s,n)		debuglog_printValue( __FILE__, __LINE__, (const char *)s, (long)n )
#else
#define		DEBUGLOG_INIT(s,p)
#define		DEBUGLOG_TERMINATE(s)
#define		DEBUGLOG_ENTER_FUNCTION(p)
#define		DEBUGLOG_RETURN_FUNCTION(p)
#define		DEBUGLOG_PRINT_STRING(s,p)
#define		DEBUGLOG_PRINT_VALUE(s,n)
#endif

#ifdef	__cplusplus
}
#endif

#endif
