/* --- YLangBar - Product definition. --- */
/* --- All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011 --- */
/* --- Source : ylangbar.h --- */
/* --- Author : hunny --- */
/* --- Date   : 2011/03/20 (1.00) - Release 1.00 --- */

#ifndef		_YLANGBAR_H
#define		_YLANGBAR_H

#define		PRODUCT_NAME		"YLangBar"

#include	<windows.h>

#define		YLB_CMD_APPL_CANCEL		(100)
#define		YLB_CMD_APPL_EXIT		(101)

void	ylb_init( HMENU * ) ;
void	ylb_terminate( HMENU * ) ;
void	ylb_popup( const HWND, const HMENU ) ;
void	ylb_state( const HWND ) ;

#endif
