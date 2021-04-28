import sys
from PIL import Image, ImageDraw
im1=Image.open(sys.argv[1])
im2=Image.open(sys.argv[2])
x1,y1=im1.size
x2,y2=im2.size
px1=im1.load()
px2=im2.load()
imout=Image.new("RGB", (x1, y1), (0, 0, 0))
pxout=imout.load()
for i in range(x1):
	for j in range(y1):
		if i>(x1-x2)//2 and j>(y1-y2)//2 and i<(x1+x2)//2 and j<(y1+y2)//2:
			r1,g1,b1=px2[i-(x1+x2)//2,j-(y1+y2)//2]
			pxout[i,j]=r1,g1,b1
		else:
			if i<x1 and j<y1:
				pxout[i,j]=px1[i,j]
imout.save(sys.argv[3])