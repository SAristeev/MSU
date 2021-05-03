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
		r1,b1,g1=px1[i,j]
		r2,b2,g2=px2[i,j]
		br1=(r1+b1+g1)//3
		br2=(r2+b2+g2)//3
		if br1==0:
			r,b,g=0,0,0
		else:
			r,b,g=r1*br2//br1,b1*br2//br1,g1*br2//br1
		pxout[i,j]=r,b,g
imout.save(sys.argv[3])