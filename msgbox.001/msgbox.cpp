/* ************************************************************** */
/* *** hunny's Common Library - Message Box                   *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : msgbox.cpp                                    *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/07 (0.01)                             *** */
/* ************************************************************** */

#define		_MSGBOX_CPP

#include	<afx.h>
#include	<afxwin.h>
//#include	<dxerr9.h>

#include	"errors.h"
#include	"debuglog.h"

#include	"msgbox.h"

namespace hcomm {


void
msgbox_showMessage( RESULTS inErrNo )
{
	AfxMessageBox( (UINT)inErrNo ) ;
}


void
msgbox_showSystemMessage( DWORD inErrNo )
{
	LPVOID	pMsg = NULL ;

	if( FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			inErrNo,
			MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
			(LPTSTR)&pMsg,
			0,
			NULL ) != 0 
	) {
		DEBUGLOG_PRINT_STRING( NULL, pMsg ) ;
		AfxMessageBox( (LPCTSTR)pMsg ) ;
	} else {
		DEBUGLOG_PRINT_VALUE( "Failure FormatMessage() ", inErrNo ) ;
		pMsg = NULL ;
	}

	if( pMsg ) LocalFree( pMsg ) ;
}


// End of namespace
}
