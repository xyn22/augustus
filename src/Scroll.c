#include "Scroll.h"

#include "Time.h"

#include "Data/Constants.h"
#include "Data/Mouse.h"
#include "Data/Screen.h"
#include "Data/Settings.h"
#include "Data/State.h"

#define SCROLL_BORDER 5

static TimeMillis lastScrollTime = 0;

static int shouldScrollMap()
{
	if (!Data_Mouse.isInsideWindow) {
		return 0;
	}
	TimeMillis currentTime = Time_getMillis();
	int diff = currentTime - lastScrollTime;
	if (currentTime < lastScrollTime) {
		diff = 10000;
	}
	int scrollDelay = (100 - Data_Settings.scrollSpeed) / 10;
	if (scrollDelay < 10) { // 0% = 10 = no scroll at all
		if (diff >= 12 * scrollDelay + 2) {
			lastScrollTime = currentTime;
			return 1;
		}
	}
	return 0;
}

int Scroll_getDirection() {
	if (!shouldScrollMap()) {
		return Dir_8_None;
	}
	Data_State.isScrollingMap = 0;
	int top = 0;
	int bottom = 0;
	int left = 0;
	int right = 0;
	// mouse near map edge
	if (Data_Mouse.x < SCROLL_BORDER) {
		left = 1;
		Data_State.isScrollingMap = 1;
	}
	if (Data_Mouse.x >= Data_Screen.width - SCROLL_BORDER) {
		right = 1;
		Data_State.isScrollingMap = 1;
	}
	if (Data_Mouse.y < SCROLL_BORDER) {
		top = 1;
		Data_State.isScrollingMap = 1;
	}
	if (Data_Mouse.y >= Data_Screen.height - SCROLL_BORDER) {
		bottom = 1;
		Data_State.isScrollingMap = 1;
	}
	// keyboard arrow keys
	if (Data_State.arrowKey.left) {
		left = 1;
		Data_State.isScrollingMap = 1;
	}
	if (Data_State.arrowKey.right) {
		right = 1;
		Data_State.isScrollingMap = 1;
	}
	if (Data_State.arrowKey.up) {
		top = 1;
		Data_State.isScrollingMap = 1;
	}
	if (Data_State.arrowKey.down) {
		bottom = 1;
		Data_State.isScrollingMap = 1;
	}
	Data_State.arrowKey.left = 0;
	Data_State.arrowKey.right = 0;
	Data_State.arrowKey.up = 0;
	Data_State.arrowKey.down = 0;

	// two sides
	if (left && top) {
		return Dir_7_TopLeft;
	} else if (left && bottom) {
		return Dir_5_BottomLeft;
	} else if (right && top) {
		return Dir_1_TopRight;
	} else if (right && bottom) {
		return Dir_3_BottomRight;
	}
	// one side
	if (left) {
		return Dir_6_Left;
	} else if (right) {
		return Dir_2_Right;
	} else if (top) {
		return Dir_0_Top;
	} else if (bottom) {
		return Dir_4_Bottom;
	}
	// none of them
	return Dir_8_None;
}