# Computer-Vision-OpenCV-Background-elimination-on-video

 we have applied cvtColor() which will convert the 
frame from BGR to RGB and then we will apply clone() to duplicate the RGB image and 
store it in Mat object. Now after doing this all we will read each frame from video in 
while loop. We convert each frame again into the RGB and then apply absdiff() method 
to calculate the absolute difference of current frame and previous frame and store it into 
Mat object(end image). Furthermore, we calculated the sum of the single channel of that 
mat object and at last we calculated the percentage difference between calculated sum 
and maximum difference (which we calculate at start by multiplying number of columns 
in frame * rows in frame* 255) and show it on an output screen. This is how we eliminated 
the background of each frame. And then displayed the original image/frame and end 
image/frame on screen. In code we have used the method called putText() which will 
show the single channel sum on the end image if the percent difference is greater than 0.5
