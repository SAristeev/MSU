import sys
from PIL import Image, ImageDraw
im1=Image.open(sys.argv[7])
w,h=im1.size
compression=float(sys.argv[1])
wide=float(sys.argv[2])
x1=int(sys.argv[3])
y1=int(sys.argv[4])
x2=int(sys.argv[5])
y2=int(sys.argv[6])
px1=im1.load()
if y2<y1:
	x2,x1=x1,x2
	y2,y1=y1,y2
imout=Image.new("RGB", (w, h), (0, 0, 0))
pxout=imout.load()
wide=int(wide*w//2)
mid=x1
for i in range(w):
	for j in range(h):
		r1,g1,b1=px1[i,j]
		if j>y1 and j<y2:
			n=(1.0-compression*(4.0*(j-y2)*(j-y1)/((y1+y2)*(y2-3*y1))))

			if(i>=mid-wide) and (i<=mid+wide):
				if(i<mid):
					i1=int((i-mid+wide)**n/(wide)**(n-1))
					i2=int((i-mid+wide+1)**n/(wide)**(n-1))
					for k in range(mid-wide+i1,mid-wide+i2):
						pxout[k,j]=r1,g1,b1
				else:
					i1=int((wide-i+mid)**n/(wide)**(n-1))
					i2=int((wide-i+mid+1)**n/(wide)**(n-1))
					for k in range(mid+wide-i2-1,mid+wide-i1+1):
						pxout[k,j]=r1,g1,b1
				
			else:
				pxout[i,j]=r1,g1,b1
			for l in range(x2-x1):
				if x1!=x2:
					mid=int(l*(y2-y1)/(x2-x1)+y1)
			#pxout[mid,j]=255,255,255
		else:
			pxout[i,j]=r1,g1,b1
imout.save(sys.argv[8])