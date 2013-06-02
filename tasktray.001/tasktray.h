/* ************************************************************** */
/* *** hunny's Common Library - Tasktray Accesser             *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : trasktray.h                                   *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/20 (1.00)                             *** */
/* ************************************************************** */

#ifndef		_TASKTRAY_H
#define		_TASKTRAY_H

#include	<windows.h>

namespace hcomm {

void	tasktray_addIcon( const HWND, const HINSTANCE, UINT, UINT, int, int ) ;
void	tasktray_removeIcon( const HWND, UINT ) ;

// End of namespace
}
#endif
