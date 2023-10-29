#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>

int main() {
	std::cout << "Open_cv version:" << CV_VERSION << '\n';
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
	// Read image
	// Define a blank image
	cv::Mat img(512, 512, CV_8UC3, cv::Scalar(120, 59, 43));
	
	cv::putText(img, "OpenCV",
		cv::Point(175, 175), cv::FONT_HERSHEY_SCRIPT_COMPLEX,
		2, cv::Scalar(200, 140, 100));
	

	cv::imshow("Image", img);

	cv::waitKey(0);
	return 0;
}