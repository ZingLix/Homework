import cv2

img = cv2.imread("test.jpg")
cv2.imshow("test.jpg",img[::-1])
cv2.waitKey(0)