import cv2
import matplotlib.pyplot as plt

img = cv2.imread("1.png")
x = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=5)
y = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=5)
#cv2.imshow("x", x)

plt.subplot(221), plt.imshow(x, 'gray')
plt.subplot(222), plt.imshow(y, 'gray')
plt.show()
cv2.waitKey(0)
