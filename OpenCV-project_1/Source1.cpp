#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>

int main() {
	std::cout << "Open_cv version:" << CV_VERSION;
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
	// Read image
	std::string img_path = "C:\\Users\\k1\\source\\repos\\OpenCV-project_1\\OpenCV-project_1\\Resources\\pic.png";
	cv::Mat img = cv::imread(img_path);
	cv::Mat img_gray, img_blur, img_canny, img_dilate, img_erode;
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	
	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, img_blur, cv::Size(3, 3), 0, 0);
	cv::Canny(img_blur, img_canny, 25, 100);
	dilate(img_canny, img_dilate, kernel);
	erode(img_dilate, img_erode, kernel);

	cv::imshow("Image", img);
	cv::imshow("Gray", img_gray);
	cv::imshow("Blur", img_blur);
	cv::imshow("Canny", img_canny);
	cv::imshow("Dilate", img_dilate);
	cv::imshow("Erode", img_erode);

	cv::waitKey(0);
	return 0;
}