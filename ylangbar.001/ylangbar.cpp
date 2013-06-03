/* --- YLangBar - YLangBar --- */
/* --- All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011 --- */
/* --- Source : winmain.cpp --- */
/* --- Author : hunny --- */
/* --- Date   : 2011/03/21 (1.00) - Release version 1.00 --- */

#define		_WINMAIN_CPP

#include	<windows.h>
#include	<windef.h>
#include	<winuser.h>
#include	<imm.h>

#include	<string.h>

#include	"debuglog.h"

#include	"ylangbar.h"

#ifndef		IMC_GETOPENSTATUS
#define		IMC_GETOPENSTATUS		(0x0005)
#endif

BOOL CALLBACK	cbShowImeWindow( HWND, LPARAM ) ;


BOOL CALLBACK
cbShowImeWindow( HWND inHwnd, LPARAM inLparam )
{
	SendMessage( inHwnd, WM_IME_CONTROL, IMC_OPENSTATUSWINDOW, 0 ) ;

	return TRUE ;
}


void
ylb_init( HMENU *ioMenu )
{
	*ioMenu = CreatePopupMenu() ;

	AppendMenu( *ioMenu, MF_STRING | MF_ENABLED, YLB_CMD_APPL_CANCEL, "ÉLÉÉÉìÉZÉã" ) ;
	AppendMenu( *ioMenu, MF_STRING | MF_ENABLED, YLB_CMD_APPL_EXIT, "èIóπ" ) ;
}


void
ylb_terminate( HMENU *ioMenu )
{
	if( *ioMenu ) {
		DestroyMenu( *ioMenu ) ;
		*ioMenu = NULL ;
	}

	EnumWindows( cbShowImeWindow, 0 ) ;
}


void
ylb_popup( const HWND inHwnd, const HMENU inMenu )
{
	::SetForegroundWindow(inHwnd); //Q135788
	POINT		point ;

	DEBUGLOG_ENTER_FUNCTION( "ylb_popup()" ) ;

	GetCursorPos( &point ) ;

	DEBUGLOG_PRINT_VALUE( "x", point.x ) ;
	DEBUGLOG_PRINT_VALUE( "y", point.y ) ;

	TrackPopupMenuEx( inMenu, TPM_CENTERALIGN | TPM_VCENTERALIGN | TPM_RIGHTBUTTON, point.x, point.y, inHwnd, NULL) ;

	DEBUGLOG_RETURN_FUNCTION( "ylb_popup()" ) ;
	::PostMessage(inHwnd, WM_NULL, 0, 0); //Q135788
}


void
ylb_state( const HWND inHwnd )
{
	HWND	hwnd ;

	if( (hwnd = ImmGetDefaultIMEWnd( inHwnd )) == NULL ) {
		DEBUGLOG_PRINT_VALUE( "ImmGetDefaultIMEWnd()", GetLastError() ) ;
		return ;
	}

	SendMessage( hwnd, WM_IME_CONTROL, IMC_OPENSTATUSWINDOW, 0 ) ;

	if( SendMessage( hwnd, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0 ) != 0 ) {
		SendMessage( hwnd, WM_IME_CONTROL, IMC_OPENSTATUSWINDOW, 0 ) ;
	} else {
		SendMessage( hwnd, WM_IME_CONTROL, IMC_CLOSESTATUSWINDOW, 0 ) ;
	}
}
