import cv2
import numpy as np 

img1 = cv2.imread("t.jpg")
img2 = cv2.imread("t.jpg")

img = np.concatenate((img1,img2),axis=1)

cv2.imshow("result",img)
cv2.waitKey(0)