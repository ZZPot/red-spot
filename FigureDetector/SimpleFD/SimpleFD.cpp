#define _USE_MATH_DEFINES
#include <math.h>
#include "SimpleFD.h"


figure_type simple_fd::Predict(Obj2d& obj)
{
	figure_type res = FT_UNKNOWN;
	if(CheckFeatures(&obj, _figure_conditions[FT_RECT], FEATURE_CHECK_SQUARE_RATIO))
		return FT_RECT;
	if(CheckFeatures(&obj, _figure_conditions[FT_ELLIPSE], FEATURE_CHECK_SQUARE_RATIO))
		return FT_ELLIPSE;
	return FT_UNKNOWN;
}

std::vector<type_condition> simple_fd::_figure_conditions = {type_condition(),
	{{cv::Rect(), cv::Rect()}, {cv::RotatedRect(), cv::RotatedRect()}, {0, 0},
	{0.94, 1.1}, {0, 1}, {0, 1}},
	{{cv::Rect(), cv::Rect()}, {cv::RotatedRect(), cv::RotatedRect()}, {0, 0},
	{(M_PI/4-0.05), (M_PI/4+0.08)}, {0, 1}, {0, 1}}
};