import cv2

if __name__ == "__main__":
    img1 = cv2.imread('testpic.jpg')
    img2 = cv2.imread('testpic2.jpg')
    img1=cv2.resize(img1,(400,1000))
    img2=cv2.resize(img2,(400,1000))
    result = cv2.addWeighted(img1, 0.5, img2, 0.5, 0)
    cv2.imshow('result', result)
    cv2.waitKey(0)