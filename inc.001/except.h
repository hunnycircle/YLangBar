/* ************************************************************** */
/* *** hunny's Common Library - Exception.                    *** */
/* *** ------------------------------------------------------ *** */
/* *** All Rights Reserved, Copyright (C) Hunny-CIRCLE 2005.  *** */
/* *** ------------------------------------------------------ *** */
/* *** File   : except.h                                      *** */
/* *** Author : hunny                                         *** */
/* *** Date   : 2006/01/07 (1.00)                             *** */
/* ************************************************************** */

#ifndef		_EXCEPT_H
#define		_EXCEPT_H

#include	<windows.h>
#include	<winerror.h>

namespace hcomm {


class Exception
{
	public :
		int		m_iErrNo ;

	public :
		Exception( int inNo ) { m_iErrNo = inNo ; } ;
} ;


class SystemException : public Exception
{
	public :
		SystemException( DWORD inNo ) : Exception( (int)inNo ) {} ;
} ;


class DxException : public Exception
{
	public :
		DxException( HRESULT inNo ) : Exception( (int)inNo ) {} ;
} ;


// End of namespace
}
#endif
