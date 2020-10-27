import numpy as np
import cv2
from PIL import Image

image = np.zeros([500, 500, 3], np.uint8)
rawData = open("../x.raw", 'r').read()
print(len(rawData))
datas = rawData.split('&')[:-1]
print(datas.__len__())
width = 500
for index, data in enumerate(datas):
    # print(int(index / width), int(index % width))
    r = int(data.split(' ')[0])
    g = int(data.split(' ')[1])
    b = int(data.split(' ')[2])
    image[int(index / width)][int(index % width)][0] = b
    image[int(index / width)][int(index % width)][1] = g
    image[int(index / width)][int(index % width)][2] = r

# cv2.imshow("new_image", image)
# cv2.waitKey(0)
# #释放窗口
# cv2.destroyAllWindows()
cv2.imwrite('x.png', image)