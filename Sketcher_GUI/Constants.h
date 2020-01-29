//======================================================================
// Constants.h
// Defines all the constants for shape type, and drawing color
//======================================================================
#pragma once		// Only define these once

// Defines for shapes
#define LINE         1
#define RECTANGLE    2
#define OVAL         3
#define CURVE        4

// Define for a solid brush pattern with no hatching (default)
#define BRUSH_PATTERN_SOLID		32767 

// COLORREF objects for colors
const COLORREF	COLOR_CLEAR   = RGB(1, 1, 1); // Won't actually use this 
const COLORREF	COLOR_BLACK   = RGB(0, 0, 0);
const COLORREF	COLOR_WHITE   = RGB(255, 255, 255);
const COLORREF	COLOR_RED     = RGB(255, 0, 0);
const COLORREF	COLOR_ORANGE  = RGB(255, 128, 0);
const COLORREF	COLOR_YELLOW  = RGB(255, 255, 0);
const COLORREF	COLOR_GREEN   = RGB(0, 255, 0);
const COLORREF	COLOR_BLUE    = RGB(0, 0, 255);
const COLORREF	COLOR_VIOLET  = RGB(128, 0, 255);