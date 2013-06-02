/* ************************************************************** */
/* *** hunny's Common Library - Systemclock Accesser          *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : date.c                                        *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/06 (0.01)                             *** */
/* ************************************************************** */

#define		_DATEW_C

#include	<windows.h>
#include	<winbase.h>

#include	<string.h>

#include	"errors.h"
#include	"date.h"


RESULTS
date_getToday( DATE_INFO *outInfo )
{
	RESULTS		retval = RESULT_NO_ERROR ;

	SYSTEMTIME	systime ;

	memset( outInfo, '\0', sizeof(DATE_INFO) ) ;

	GetLocalTime( &systime ) ;

	outInfo->m_sYear	= (short)systime.wYear ;
	outInfo->m_cMonth	= (char)systime.wMonth ;
	outInfo->m_cDay		= (char)systime.wDay ;
	outInfo->m_cHour	= (char)systime.wHour ;
	outInfo->m_cMinute	= (char)systime.wMinute ;
	outInfo->m_cSecond	= (char)systime.wSecond ;
	outInfo->m_cWeekday	= (char)systime.wDayOfWeek+1 ;

	return retval ;
}
