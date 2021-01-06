#pragma once
#include "../FigureDetector.h"

#define SQUARE_DIFFERENCE	0.10
#define SYMMETRY_DIFFERENCE	0.10

class pattern_fd: public figure_detector
{
public:
	figure_type Predict(Obj2d& obj);
};

cv::Mat GetPattern(figure_type type, cv::Size pat_size);
double GetPatDiff(cv::Mat img, figure_type ft);