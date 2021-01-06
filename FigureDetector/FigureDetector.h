#pragma once
#include "FeatureDetector/FeatureDetector.h"

enum figure_type
{
	FT_UNKNOWN = 0,
	FT_RECT = 1,
	FT_ELLIPSE,
	FT_TRIANGLE,
	FT_CROSS
};

class figure_detector
{
public:
	virtual figure_type Predict(Obj2d& obj) = 0;
};