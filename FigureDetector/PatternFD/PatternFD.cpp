#include "PatternFD.h"
#include <opencv2/imgproc.hpp>


#pragma warning(disable: 4244)
figure_type pattern_fd::Predict(Obj2d& obj)
{
	Obj2d new_obj = RotateObj(obj, obj.r_rect.angle);
	cv::Mat obj_field(new_obj.rect.size(), CV_8UC1, cv::Scalar(0));
	cv::Point offset = new_obj.rect.tl();
	offset *= -1;
	DrawContours(new_obj.contours, {cv::Scalar(255)}, obj_field, offset);
	if(VHSymmetry(obj_field) >= SYMMETRY_DIFFERENCE)
		return FT_UNKNOWN;
	if(GetPatDiff(obj_field, FT_RECT) <= SQUARE_DIFFERENCE)
		return FT_RECT;
	if(GetPatDiff(obj_field, FT_ELLIPSE) <= SQUARE_DIFFERENCE)
		return FT_ELLIPSE;
	return FT_UNKNOWN;
}
cv::Mat GetPattern(figure_type type, cv::Size pat_size)
{
	cv::Mat res;
	switch(type)
	{
	case FT_RECT:
		res = cv::getStructuringElement(cv::MORPH_RECT, pat_size);
		break;
	case FT_ELLIPSE:
		cv::Rect cut_rect(cv::Point(0, 1), pat_size);
		//pat_size.width += 2;
		pat_size.height += 2; // one pixel problem
		res = cv::getStructuringElement(cv::MORPH_ELLIPSE, pat_size);
		res = res(cut_rect);
		break;
	}
	return res;
}
double GetPatDiff(cv::Mat img, figure_type ft)
{
	cv::Mat pat = GetPattern(ft, img.size())*255;
	cv::Scalar pat_sum = cv::sum(pat);
	cv::Mat diff;
	cv::absdiff(pat, img, diff);
	cv::Scalar diff_sum = cv::sum(diff);
	return diff_sum[0] / pat_sum[0];
}
