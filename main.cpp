#include "FeatureDetector/FeatureDetector.h"
#include "FigureDetector/SimpleFD/SimpleFD.h"
#include "FigureDetector/PatternFD/PatternFD.h"
#include "FeatureDetector/Draw/DrawDebug.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#define WND_NAME_ORIG	"Original"
#define WND_NAME_SFD	"Simple figure detector"
#define WND_NAME_PFD	"Pattern figure detector"
#define FILE_NAME		"1.png"

int main()
{
	cv::Mat img = cv::imread(FILE_NAME);
	cv::Mat img_sfd, img_pfd;
	img.copyTo(img_sfd);
	img.copyTo(img_pfd);
	cv::Mat red_range;
	cv::inRange(img, cv::Scalar(0, 0, 220), cv::Scalar(20, 20, 255), red_range);
	std::map<std::string, cv::Scalar> rect_colors = {	{"ellipse", cv::Scalar(255, 255, 255)},
														{"rectangle", cv::Scalar(255, 128, 0)} };
	std::vector<Obj2d> objects = FindObjects(red_range, std::vector<type_condition>(),  std::vector<int>(), cv::RETR_EXTERNAL);
	simple_fd sfd;
	pattern_fd pfd;
	for(auto& obj: objects)
	{
		/*DrawContours(obj.contours, {cv::Scalar(255, 255, 255)}, img);
		cv::imshow(WND_NAME_ORIG, img);
		cv::waitKey(0);*/
		figure_type ft_sfd = sfd.Predict(obj);
		figure_type ft_pfd = pfd.Predict(obj);
		switch(ft_sfd)
		{
		case FT_ELLIPSE:
			DrawRRect(obj.r_rect, img_sfd, rect_colors["ellipse"]);
			cv::putText(img_sfd, "ellipse", obj.rect.tl(), cv::FONT_HERSHEY_SIMPLEX, 0.75, rect_colors["ellipse"], 1, cv::LINE_AA);
			break;
		case FT_RECT:
			DrawRRect(obj.r_rect, img_sfd, rect_colors["rectangle"]);
			cv::putText(img_sfd, "rectangle", obj.rect.tl(), cv::FONT_HERSHEY_SIMPLEX, 0.75, rect_colors["rectangle"], 1, cv::LINE_AA);
			break;
		}
		switch(ft_pfd)
		{
		case FT_ELLIPSE:
			DrawRRect(obj.r_rect, img_pfd, rect_colors["ellipse"]);
			cv::putText(img_pfd, "ellipse", obj.rect.tl(), cv::FONT_HERSHEY_SIMPLEX, 0.75, rect_colors["ellipse"], 1, cv::LINE_AA);
			break;
		case FT_RECT:
			DrawRRect(obj.r_rect, img_pfd, rect_colors["rectangle"]);
			cv::putText(img_pfd, "rectangle", obj.rect.tl(), cv::FONT_HERSHEY_SIMPLEX, 0.75, rect_colors["rectangle"], 1, cv::LINE_AA);
			break;
		}
	}
	cv::imshow(WND_NAME_SFD, img_sfd);
	cv::imshow(WND_NAME_PFD, img_pfd);
	cv::imwrite("result.png", img_pfd);
	cv::waitKey(0);
	return 0;
}