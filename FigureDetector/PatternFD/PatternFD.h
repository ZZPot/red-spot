#pragma once
#include "../FigureDetector.h"

#define SQUARE_DIFFERENCE	0.10

class pattern_fd: public figure_detector
{
public:
	figure_type Predict(Obj2d& obj);
};

cv::Mat GetPattern(figure_type type, cv::Size pat_size);
double GetPatDiff(cv::Mat img, figure_type ft);

Obj2d RotateObj(Obj2d& obj, double angle);


// I think OpenCV need this
template<class t1, class t2> cv::Point_<t1> operator-(cv::Point_<t1> p1, cv::Point_<t2> p2);
template<class t1, class t2> cv::Point_<t1>& operator-=(cv::Point_<t1>& p1, cv::Point_<t2> p2);
template<class t1, class t2> cv::Point_<t1> operator+(cv::Point_<t1> p1, cv::Point_<t2> p2);
template<class t1, class t2> cv::Point_<t1>& operator+=(cv::Point_<t1>& p1, cv::Point_<t2> p2);
template<class t1, class t2> cv::Point_<t1> operator-(cv::Point_<t1> p1, t2 scalar);
template<class t1, class t2> cv::Point_<t1>& operator-=(cv::Point_<t1>& p1, t2 scalar);
template<class t1, class t2> cv::Point_<t1> operator+(cv::Point_<t1> p1, t2 scalar);
template<class t1, class t2> cv::Point_<t1>& operator+=(cv::Point_<t1>& p1, t2 scalar);
template<class t1, class t2> cv::Point_<t1>& operator*(cv::Point_<t1> p1, t2 scalar);
template<class t1, class t2> cv::Point_<t1>& operator*=(cv::Point_<t1>& p1, t2 scalar);
template<class t1> cv::Point_<t1> operator-(cv::Point_<t1> p1);