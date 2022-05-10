// //任务一（已完成）
// #include <opencv2/opencv.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include<iostream>
// #include <time.h>

// using namespace cv;
// using namespace std;

// clock_t start,finish;
// Mat srcImage;
// vector<Vec3f>circles;
// Mat templateImage;
// Mat resultImage;

// void processFrame(Mat& img, Rect& rect);//绘制外接矩形
// double area=0.0;

// int main(int argc, char** argv)
// {
// 	Rect roi;//存储最大外接矩形的数据
    
// 	VideoCapture capture;
// 	capture.open(0);

// 	if (!capture.isOpened())
// 	{
// 		cout << "图像读取错误！～" << endl;
// 		return -1;
// 	}
	
// 	Mat frame,dst;
// 	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
// 	Mat kernel_dilite = getStructuringElement(MORPH_RECT, Size(7, 7), Point(-1, -1));

// 	while (capture.read(frame))
// 	{
// 		start = clock();

// 		//筛选出绿色
// 		//inRange(frame, Scalar(0, 127, 0), Scalar(120, 255, 120), dst);

//         //分离通道参数
//         vector<Mat>image;
//         split(frame,image);
//         //绿蓝通道相减得出绿灯的二值化图像
//         dst = image[1] - image[0];			
// 		//开操作去噪点
// 		morphologyEx(dst, dst, MORPH_OPEN, kernel, Point(-1, -1), 1);
//         threshold(dst,dst,50,255,THRESH_BINARY);
// 		//膨胀操作把绿灯具体化的显示出来
// 		dilate(dst, dst, kernel_dilite, Point(-1, -1), 2);
// 		imshow("output video", dst);
// 		processFrame(dst, roi);
// 		rectangle(frame, roi, Scalar(0, 0, 255), 3, 8, 0);
//         if(area>=800)  //根据距离调参数800
//         {
//             cout<<"绿灯识别完成"<<endl;
//             cout<<"area:"<<area<<endl;
//         }

//         finish= clock();
//         double abc_Frame = 1000/(double(finish-start)/CLOCKS_PER_SEC*1000);
//         std::string str = std::to_string(abc_Frame);
//         string Frame_name = "FPS:";
//         Frame_name +=str;
//         cout<<"视觉识别帧率为："<<Frame_name<<endl;
//         putText(frame,Frame_name,Point(0,50),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
// 		   imshow("input video", frame);

// 		char c = waitKey(50);
// 		if (c == 27)
// 		{
// 			break;
// 		}
// 	}

// 	capture.release();
// 	waitKey(0);
// 	return 0;

// }

// void processFrame(Mat & img, Rect & rect)
// {
// 	//寻找外接轮廓
// 	vector<vector<Point>>contours;
// 	vector<Vec4i>hierarchy;
// 	findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(-1, -1));
	
// 	if (contours.size() > 0) 
// 	{
// 		for (size_t i = 0; i < contours.size(); i++)
// 		{
// 			double contours_Area = contourArea(contours[static_cast<int>(i)]);//面积
// 			rect = boundingRect(contours[static_cast<int>(i)]);//外接矩形
// 			if (contours_Area > area)
// 			{
// 				area = contours_Area;
// 			}
// 		}
		
// 	}
// 	else
// 	{
// 		rect.x = rect.y = rect.width = rect.height = 0;
// 	}
// }