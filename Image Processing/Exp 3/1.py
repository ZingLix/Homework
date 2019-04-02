import cv2
import numpy as np
import math
img = cv2.imread("t.jpg")

h,w=img.shape[:2]
a1 = np.array([[2,0,0],[0,2,0]],np.float32)
img = cv2.warpAffine(img,a1,(h*2,w*2))

h,w=img.shape[:2]
r=cv2.getRotationMatrix2D((w/2,h/2),45,1)
cos = np.abs(r[0, 0])
sin = np.abs(r[0, 1])
newW = int((h * sin) + (w * cos))
newH = int((h * cos) + (w * sin))

r[0, 2] += (newW / 2) - h/2
r[1, 2] += (newH / 2) - w/2

d1=cv2.warpAffine(img,r,(newW,newH))
cv2.imshow("result",d1)
cv2.waitKey(0)