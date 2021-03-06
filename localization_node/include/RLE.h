#ifndef RLE_H_
#define RLE_H_

#include "ScanLines.h"

/** Structure for the definition of the run-length encoding information. */

struct RLEInfo
{
    int center, start, end, endAfter, startBefore;
    unsigned scIdx;
    unsigned lengthColorBefore;
    unsigned lengthColor;
    unsigned lengthColorAfter;
    float x, y;

};

using namespace cv;
using namespace std;
class RLE
{

public:

	std::vector<RLEInfo> rlData;
	ScanLines s;
    RLE();
    RLE(ScanLines &s_, unsigned colorBefore, unsigned colorOfInterest, unsigned colorAfter,
            unsigned threshColorBefore, unsigned threshColorOfInterest, unsigned threshColorAfter,
            unsigned searchWindow);

	inline cv::Point getPointXYFromInteger(int idx)
	{
		cv::Point temp;
		temp.x = idx%s.image.cols;
		temp.y = idx/s.image.cols;

		return temp;
    }

    void draw(cv::Scalar colorBefore, cv::Scalar colorOfInterest, cv::Scalar colorAfter, cv::Mat *destination);
    void drawLine(int pt1, int pt2, cv::Scalar color, cv::Mat *img);
    void drawCircle(int pt, int radius, cv::Scalar color, cv::Mat *img);
    void drawInterestPoints(cv::Scalar color,cv::Mat *destination,UAV_COLORS_BIT idx);
    void LinespushDataC(std::vector<Point> &destination, Mat& img);
    void LinespushData(std::vector<Point> &destination, Mat& img, std::vector<double> &distPix, std::vector<int> &distPixVal, Point robotCenter, int filter);
    void pushData(std::vector<Point> &destination, Mat& img);
    inline int d2p(Point p1, Point p2) {  return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2)); }
};

#endif
