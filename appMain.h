/*
 * appMain.h
 *
 *  Created on: 1 ���. 2017 �.
 *      Author: ����
 */

#ifndef APPMAIN_H_
#define APPMAIN_H_

#include <iostream>
#include <wtypes.h>
#include <winbase.h>
#include "ClientCommon.h"

typedef void (*SendRequestProc) (char* params[]);
typedef void (*RepeatRequestProc) ();
typedef int (*ErrorsExistProc) ();
typedef void (*SaveStateProc) ();
enum {PARAMS_NUM=6};
#endif /* APPMAIN_H_ */
