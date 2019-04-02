import matplotlib.pyplot as plt
import cv2
import numpy as np

img = cv2.imread("1.png")
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
img = cv2.equalizeHist(img)
rows, cols = img.shape
for x in range(rows):
    for y in range(cols):
        if img[x, y] >= 140:
            img[x, y] = 255
        else:
            img[x, y] = 0

cv2.imshow("result", img)
cv2.waitKey(0)
