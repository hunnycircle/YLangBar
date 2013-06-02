/* --- YLangBar - WinMain --- */
/* --- All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011 --- */
/* --- Source : winmain.cpp --- */
/* --- Author : hunny --- */
/* --- Date   : 2011/03/20 (0.01) - Test version 0.01 --- */

#define		_WINMAIN_CPP

#include	<afxwin.h>
#include	<stdlib.h>
#include	<string.h>

#include	"debuglog.h"
#include	"except.h"
#include	"msgbox.h"
#include	"tasktray.h"

#include	"ylangbar.h"

#include	"resource.h"

using namespace hcomm ;

static HWND			initFrameWindow( HINSTANCE ) ;
static ATOM			registFrameWindow( HINSTANCE ) ;
static LRESULT		mainWindowProc( HWND, UINT, UINT, LONG ) ;

#define				YLB_WM_NOTIFYICON		(WM_USER + 100)
#define				NOTIFY_RETRY					(15)
#define				NOTIFY_INTERVAL				(2000)
#define				TIMER_INTERVAL				(300)

HWND				g_hWnd			= NULL ;
HMENU				g_hMenu			= NULL ;


static LRESULT mainWindowProc( HWND inHwnd, UINT inMsg, UINT wParam, LONG lParam )
{
	HWND	hwnd ;

	switch( inMsg ) 
	{
		case WM_DESTROY :
		{
			PostQuitMessage( 0 ) ;
		}
		return 0 ;

		case WM_COMMAND :
		{
			if( LOWORD(wParam) == YLB_CMD_APPL_EXIT ) {
				DestroyWindow( g_hWnd ) ;
			}
		}
		return 0 ;

		case WM_TIMER :
		{
			if( (hwnd = GetForegroundWindow()) != NULL ) {
				ylb_state( hwnd ) ;
			}
		}
		break ;

		case YLB_WM_NOTIFYICON :
		{
			if( lParam == WM_LBUTTONUP ) {
				ylb_popup( g_hWnd, g_hMenu ) ;
			}
		}
		break ;
	}

	return DefWindowProc( inHwnd, inMsg, wParam, lParam ) ;
}


static ATOM registFrameWindow( HINSTANCE inInst )
{
	WNDCLASS	wc ;

	wc.style         = CS_HREDRAW | CS_VREDRAW ;
	wc.lpfnWndProc   = (WNDPROC)mainWindowProc ;
	wc.cbClsExtra    = 0 ;
	wc.cbWndExtra    = 0 ;
	wc.hInstance     = inInst ;
	wc.hIcon         = LoadIcon( inInst, (LPCSTR)IDI_APPL_ICON ) ;
	wc.hCursor       = LoadCursor( NULL, IDC_ARROW ) ;
	wc.hbrBackground = (HBRUSH)(COLOR_3DFACE+1) ;
	wc.lpszMenuName  = NULL ;
	wc.lpszClassName = PRODUCT_NAME ;

	return RegisterClass( &wc ) ;
}


static HWND initFrameWindow( HINSTANCE inInst )
{
	return CreateWindow(
		PRODUCT_NAME, PRODUCT_NAME,
//		WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU,
		0,
		CW_USEDEFAULT, CW_USEDEFAULT, 0, 0,
		NULL,
		NULL,
		inInst,
		NULL
	) ;
}


int WINAPI WinMain( HINSTANCE inInst, HINSTANCE inPrevInst, LPSTR inLPCmdLine, int inCmdShow )
{
	int			retval = 0 ;

	UINT_PTR	timer = NULL ;
	MSG			msg ;

	DEBUGLOG_INIT( PRODUCT_NAME, "debug.log" ) ;

	try {
		AfxSetResourceHandle( inInst ) ;

		if( registFrameWindow( inInst ) == (ATOM)0 ) {
			throw SystemException( GetLastError() ) ;
		}

		if( (g_hWnd = initFrameWindow( inInst )) == NULL ) {
			throw SystemException( GetLastError() ) ;
		}

		if( (timer = SetTimer( g_hWnd, NULL, TIMER_INTERVAL, NULL )) == NULL ) {
			throw SystemException( GetLastError() ) ;
		}

		ylb_init( &g_hMenu ) ;

		tasktray_addIcon( g_hWnd, inInst, IDI_APPL_ICON, YLB_WM_NOTIFYICON, NOTIFY_RETRY, NOTIFY_INTERVAL ) ;

		while( !0 ) {
			if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) {
				if( msg.message != WM_QUIT ) {
					TranslateMessage( &msg ) ;
					DispatchMessage( &msg ) ;
				} else {
					retval = (int)msg.wParam ;
					break ;
				}
			} else {
				WaitMessage() ;
			}
		}

		tasktray_removeIcon( g_hWnd, IDI_APPL_ICON ) ;

		ylb_terminate( &g_hMenu ) ;

		KillTimer( g_hWnd, timer ) ;

	} catch( SystemException se ) {
		msgbox_showSystemMessage( se.m_iErrNo ) ;
		retval = 1 ;
	} catch( Exception e ) {
		msgbox_showMessage( e.m_iErrNo ) ;
		retval = 1 ;
	}

	DEBUGLOG_TERMINATE( PRODUCT_NAME ) ;

	return retval ;
}
