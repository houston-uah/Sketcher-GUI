//===========================================================
// COval.h
// Class definition file for an Oval shape
// Author: Dr. Rick Coleman
//===========================================================
#pragma once

#include "Constants.h"
#include "CShape.h"

class COval : public CShape
{
	public:
		COval();
		~COval();
		void Draw(CDC *pDC);
};