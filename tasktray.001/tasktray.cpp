/* ************************************************************** */
/* *** hunny's Common Library - Tasktray Accesser             *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : trasktray.cpp                                 *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/20 (1.00)                             *** */
/* ************************************************************** */

#define		_TASKTRAY_CPP

#include	<windows.h>
#include	<shellapi.h>

#include	<stdlib.h>
#include	<string.h>

#include	"errors.h"
#include	"except.h"

#include	"tasktray.h"

namespace hcomm {


void
tasktray_addIcon( const HWND inHwnd, const HINSTANCE inInst, UINT inIcon, UINT inMessageID, int inRetry, int inInterval )
{
	int		i ;

	NOTIFYICONDATA		nid ;

	memset( &nid, '\0', sizeof(NOTIFYICONDATA) ) ;

	nid.cbSize = sizeof(NOTIFYICONDATA) ;
	nid.hWnd = inHwnd ;
	nid.uID = inIcon ;
	nid.uFlags = (NIF_MESSAGE | NIF_ICON | NIF_TIP) ;
	nid.uCallbackMessage = inMessageID ;
	nid.hIcon = LoadIcon( inInst, (LPCSTR)inIcon ) ;

	for( i=0 ; i < inRetry ; i++ ) {
		if( Shell_NotifyIcon( NIM_ADD, &nid ) == TRUE ) {
			break ;
		} else {
			Sleep( inInterval ) ;
		}
	}

	if( i >= inRetry ) {
		throw SystemException( GetLastError() ) ;
	}
}


void
tasktray_removeIcon( const HWND inHwnd, UINT inIcon )
{
	NOTIFYICONDATA		nid ;

	memset( &nid, '\0', sizeof(NOTIFYICONDATA) ) ;

	nid.cbSize = sizeof(NOTIFYICONDATA) ;
	nid.hWnd = inHwnd ;
	nid.uID = inIcon ;

	Shell_NotifyIcon( NIM_DELETE, &nid ) ;

	if( nid.hIcon ) {
		DestroyIcon( nid.hIcon ) ;
	}
}


// End of namespace
}
