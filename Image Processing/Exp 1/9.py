import cv2
import imutils
import numpy as np

if __name__ == "__main__":
    img=cv2.imread("testpic.jpg")
    cv2.imshow("Image",img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()