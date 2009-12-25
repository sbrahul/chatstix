/* 
 * File:   CStixTypedefs.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 12:54 PM
 *
 * Conventions:
 * <rettype><param_count><param_type...> as identified by,
 * v - void
 * i - int
 * l - long
 * s - short
 * c - char
 * f - float
 * d - double
 * str - string
 * <...> - other objects
 *
 */

#ifndef _CSTIXTYPEDEFS_H
#define	_CSTIXTYPEDEFS_H

#include <string>
using namespace std;

#include "../includes/CStixCallbackTemplate.h"
#include "../includes/CStixCallbacks.h"
#include "../includes/CStixMessage.h"

/*
 * Used by the login callback.
 */
typedef CStixCallbackTemplate< CStixCallbacks, void, string, string > callback_v2str;
/*
 * Used by the communications callback.
 */
typedef CStixCallbackTemplate< CStixCallbacks, void, CStixMessage& > callback_v1csmsg;

#endif	/* _CSTIXTYPEDEFS_H */

