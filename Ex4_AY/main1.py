import sys
from scipy import misc
from numpy import uint8
from imageio import imread
from imageio import imwrite
x=int(sys.argv[1])
y=int(sys.argv[2])
w=int(sys.argv[3])
h=int(sys.argv[4])
im1=imread(sys.argv[5])
h1=len(im1) # высота
w1=len(im1[0]) # ширина
if h+y>h1:
	h2=h1-y
else:
	h2=h
if w+x>w1:
	w2=w1-x
else:
	w2=w
imout=[i for i in range(0,h2)]
for iy in range(0,h2):
	imout[iy]=[i for i in range(0,w2)]
for iy1 in range(0,h2):
	for ix1 in range(0,w2):
		imout[iy1][ix1]=im1[iy1+y][ix1+x].copy()
imwrite(sys.argv[6],imout,format='bmp')