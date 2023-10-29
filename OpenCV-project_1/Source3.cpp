#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>

int main() {
	std::cout << "Open_cv version:" << CV_VERSION << '\n';
	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
	// Read image
	std::string img_path = "directory address";
	cv::Mat img = cv::imread(img_path);
	cv::Mat transform_matrix, img_warp;

	float w = 214, h = 334;
	cv::Point2f src[4] = { {45, 109}, {302, 5}, {307, 459}, {584, 249} };
	cv::Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	transform_matrix = cv::getPerspectiveTransform(src, dst);
	cv::warpPerspective(img, img_warp, transform_matrix, cv::Point(w, h));

	cv::imshow("Image", img);
	cv::imshow("Warp", img_warp);

	cv::waitKey(0);
	return 0;
}