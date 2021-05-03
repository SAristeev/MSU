import sys
from scipy import misc
from numpy import uint8
from imageio import imread
from imageio import imwrite

im1=imread(sys.argv[1])
im2=imread(sys.argv[2])
h=len(im1)
w=len(im1[0])
imout=[i for i in range(0,h)]
for iy in range(0,h):
	imout[iy]=[i for i in range(0,w)]

for iy1 in range(0,h):
	for ix1 in range(0,w):
		br1=(im1[iy1][ix1][0]+0+im1[iy1][ix1][1]+im1[iy1][ix1][2])//3
		br2=(im2[iy1][ix1][0]+0+im2[iy1][ix1][1]+im2[iy1][ix1][2])//3
		if br1==0:
			imout[iy1][ix1]=[uint8(0),uint8(0),uint8(0)]
		else:
			v=br2/br1
			r=im1[iy1][ix1][0]*v
			b=im1[iy1][ix1][1]*v
			g=im1[iy1][ix1][2]*v
			imout[iy1][ix1]=[uint8(r),uint8(b),uint8(g)]

imwrite(sys.argv[3],imout,format='bmp')