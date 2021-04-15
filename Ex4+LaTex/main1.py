class ArgException(Exception):
	pass

import sys
from scipy import misc
from numpy import uint8
from imageio import imread
from imageio import imwrite
try:
	if len(sys.argv)<4:
		raise ArgException("Not enough arguments")
	if len(sys.argv)>4:
		raise ArgException("Too many arguments")
	im=imread(sys.argv[2])
	n=int(sys.argv[1])
	if n<0:
		raise ArgException("Negative value: "+sys.argv[1])
	h=len(im) # высота
	w=len(im[0]) # ширина
	im2=[i for i in range(0,h+2*n)]
	for iy in range(0,h+2*n):
		im2[iy]=[i for i in range(0,w+2*n)]

	for iy1 in range(0,n):
		for ix1 in range(0,w+2*n):
			im2[iy1][ix1]=[uint8(0),uint8(0),uint8(0)]

	for iy2 in range(n,h+n):
		for ix21 in range(0,n):
			im2[iy2][ix21]=[uint8(0),uint8(0),uint8(0)]
		for ix22 in range(n,w+n):
			im2[iy2][ix22]=im[iy2-n][ix22-n].copy()
		for ix23 in range(w+n,w+2*n):
			im2[iy2][ix23]=[uint8(0),uint8(0),uint8(0)]

	for iy3 in range(h+n,h+2*n):
		for ix3 in range(0,w+2*n):
			im2[iy3][ix3]=[uint8(0),uint8(0),uint8(0)]

	imwrite(sys.argv[3],im2,format='bmp')
except Exception as e:
	print(str(e))