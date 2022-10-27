#include "XLAT_head.h"

void CaptureScreen::get_pixel(int x, int y, int width, int height)
{
	SelectObject(MemoryDC, hBitmap);
	BitBlt(MemoryDC, 0, 0, width, height, ScreenDC, x, y, SRCCOPY);
}

int* CaptureScreen::info(int x, int y)
{
	rgb_returned[0] = buf[(y * screen_x + x) * 3 + 2];
	rgb_returned[1] = buf[(y * screen_x + x) * 3 + 1];
	rgb_returned[2] = buf[(y * screen_x + x) * 3];

	return rgb_returned;
}