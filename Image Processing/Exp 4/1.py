import matplotlib.pyplot as plt
import cv2
import numpy as np


def grayHist(img):
    rows, cols, dims = img.shape
    gray = np.zeros([256], np.uint64)
    for r in range(rows):
        for c in range(cols):
            gray[img[r][c]] += 1
    return gray


img = cv2.imread("1.png")
gray = grayHist(img)
x_range = range(256)
plt.plot(x_range, gray, 'r', linewidth=2, c='black')
plt.axis([0, 255, 0, np.max(gray)])
plt.show()
