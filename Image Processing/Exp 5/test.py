import cv2
import numpy as np

img1 = cv2.imread('1.jpg')
hsv1 = cv2.cvtColor(img1, cv2.COLOR_BGR2HSV)

img2 = cv2.imread('2.jpg')
hsv2 = cv2.cvtColor(img2, cv2.COLOR_BGR2HSV)

hist1 = cv2.calcHist([hsv1], [0, 1], None, [180, 256], [0, 180, 0, 256])
cv2.normalize(hist1, hist1, 0, 255, cv2.NORM_MINMAX)

dst = cv2.calcBackProject([hsv2], [0, 1], hist1, [0, 180, 0, 256], 1)

disc = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
dst = cv2.filter2D(dst, -1, disc)

ret, thresh = cv2.threshold(dst, 50, 255, 0)
thresh = cv2.merge((thresh, thresh, thresh))

res = cv2.bitwise_and(img2, thresh)

cv2.imshow('结果', res)
cv2.waitKey(0)
