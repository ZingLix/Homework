import matplotlib.pyplot as plt
import cv2
import numpy as np

img = cv2.imread("1.png")
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
img = cv2.equalizeHist(img)
cv2.imshow("result", img)
cv2.waitKey(0)
