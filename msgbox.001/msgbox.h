/* ************************************************************** */
/* *** hunny's Common Library - Message Box                   *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2011.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : msgbox.h                                      *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2011/03/07 (0.01)                             *** */
/* ************************************************************** */

#ifndef	_MSGBOX_H
#define	_MSGBOX_H

#include	"errors.h"

namespace hcomm {

void	msgbox_showMessage( RESULTS ) ;
void	msgbox_showSystemMessage( DWORD ) ;

// End of namespace
}
#endif
