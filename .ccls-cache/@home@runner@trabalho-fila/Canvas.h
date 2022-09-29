#ifndef __CANVAS_H__
#define __CANVAS_H__


const int CANVAS_ROWS = 8;
const int CANVAS_COLS = 8;

struct Canvas
{
	bool data[CANVAS_ROWS][CANVAS_COLS];
	char on;
	char off;
};

void SetupCanvas(Canvas& canvas,
#if _WIN32
	char on = (char)219,
	char off = (char)176
#else
	char on = '#',
	char off = '.'
#endif
);

void ClearCanvas(Canvas& canvas);
void ToggleCanvas(Canvas& canvas, int row, int col);
void PrintCanvas(const Canvas& canvas);

std::ostream& operator<<(std::ostream& os, const Canvas& canvas);

#endif
