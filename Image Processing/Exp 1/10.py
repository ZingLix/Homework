import cv2
import imutils
import numpy as np

if __name__ == "__main__":
    img=cv2.imread("testpic.jpg")
    img=imutils.resize(img,height = 1024)
    [b,g,r]=cv2.split(img)
    zeros = np.zeros(img.shape[:2], dtype = "uint8")
    cv2.imshow("Blue&Green",cv2.merge([b,g,zeros]))
    cv2.waitKey(0)
    cv2.destroyAllWindows()