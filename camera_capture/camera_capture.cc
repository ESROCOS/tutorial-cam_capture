/* User code: This file will not be overwritten by TASTE. */

#include "camera_capture.h"
#include <opencv2/opencv.hpp>

using namespace cv;

void camera_capture_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void camera_capture_PI_capture()
{
     VideoCapture cap(0); // open the default camera
     if(!cap.isOpened())  // check if we succeeded
       
     namedWindow("raw",1);
     namedWindow("edges",2);
    
     Mat frame;
     Mat edges;
     cap >> frame; // get a new frame from camera
     cvtColor(frame, edges, COLOR_BGR2GRAY);
     GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
     Canny(edges, edges, 0, 30, 3);
     imshow("raw", frame);    
     imshow("edges", edges);
     if(waitKey(100) >= 0);
}

