import cv2
import numpy as np

img = cv2.imread('1.jpg')
edge = cv2.Canny(img, 50, 150)
lines = cv2.HoughLines(edge, 1, np.pi/180, 260)
result = img
for line in lines[0]:
    rho = line[0]
    theta = line[1]
    if (theta < (np.pi/4.)) or (theta > (3.*np.pi/4.0)):
        pt1 = (int(rho/np.cos(theta)), 0)
        pt2 = (int((rho-result.shape[0]*np.sin(theta))/np.cos(theta)), result.shape[0])
        cv2.line(result, pt1, pt2, (0, 0, 255))
    else:
        pt1 = (0, int(rho/np.sin(theta)))
        pt2 = (result.shape[1], int(
            (rho-result.shape[1]*np.cos(theta))/np.sin(theta)))
        cv2.line(result, pt1, pt2, (0, 0, 255), 1)
cv2.imshow('result', result)
cv2.waitKey(0)
