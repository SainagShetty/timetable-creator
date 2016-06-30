/* File: MOUSE.H
** Description:
**   Function declarations and miscellaneous definitions for module
**   MOUSE.C.
** Copyright:
**   Copyright 1994, David G. Roberts
*/

#ifndef _MOUSE_H

#include "gamedefs.h"

/* constants */

/* mouse events */
#define ME_CENTER_RELEASED	(0x40)
#define ME_CENTER_PRESSED	(0x20)
#define ME_RIGHT_RELEASED	(0x10)
#define ME_RIGHT_PRESSED	(0x08)
#define ME_LEFT_RELEASED	(0x04)
#define ME_LEFT_PRESSED		(0x02)
#define ME_MOVEMENT			(0x01)

/* button state masks */
#define CENTER_BUTTON_MASK	(0x04)
#define RIGHT_BUTTON_MASK	(0x02)
#define LEFT_BUTTON_MASK	(0x01)

/* prototypes for MOUSE.C */
int ResetMouse(void);
void ShowMouseCursor(void);
void HideMouseCursor(void);
UINT16 PollMouseStatus(UINT16 * x, UINT16 * y);
void SetMouseCursorPosition(UINT16 x, UINT16 y);
UINT16 GetMouseButtonPressInfo
	(
    UINT16   Button,
    UINT16 * Counter,
    UINT16 * x,
    UINT16 * y
    );
UINT16 GetMouseButtonReleaseInfo
	(
    UINT16 Button,
    UINT16 * Counter,
    UINT16 * x,
    UINT16 * y
    );
void SetMouseXLimit(UINT16 MinimumX, UINT16 MaximumX);
void SetMouseYLimit(UINT16 MinimumY, UINT16 MaximumY);
void SetMouseGraphicsCursor
	(
    int HotSpotX,
    int HotSpotY,
    void far * BitmapPtr
    );
void SetMouseTextCursor(UINT16 ANDmask, UINT16 XORmask);
void SetMouseEventHandler(UINT16 EventMask, void far * Handler);
void SetMouseSensitivity
	(
    UINT16 MickeysPer8X,
    UINT16 MickeysPer8Y
    );
void SetMouseProtectedArea
	(
    UINT16 Left,
    UINT16 Top,
    UINT16 Right,
    UINT16 Bottom
    );
void SetMouseAccelerationThreshold(UINT16 MickeysPerSecond);
UINT16 GetMouseInfo(UINT16 * Type, UINT16 * Irq);

#define _MOUSE_H

#endif