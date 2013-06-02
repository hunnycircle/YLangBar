/* ************************************************************** */
/* *** hunny's Common Library - Systemclock Accesser          *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : date.h                                        *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/06 (0.01)                             *** */
/* ************************************************************** */

#ifndef		_DATE_H
#define		_DATE_H

#include	"errors.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {
	short		m_sYear ;
	char		m_cMonth ;
	char		m_cDay ;
	char		m_cHour ;
	char		m_cMinute ;
	char		m_cSecond ;
	char		m_cWeekday ;
} DATE_INFO ;

RESULTS		date_getToday( DATE_INFO * ) ;

#ifdef	__cplusplus
}
#endif

#endif
