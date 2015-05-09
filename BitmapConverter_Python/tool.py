__author__ = 'drona@elementz'

import sys

#sys.path.append('/usr/local/lib/python2.7/site-packages')
import numpy as np
import cv2

def imgtool(filepath):
    fo = open("hex_values.txt", "w")
    fo.write("//Header created by Image2LCD tool developed by Elementz Engineers Guild Pvt. Ltd. \n\n")
    fo.write("unsigned char bitmap [] = {\n")
    if filepath != '':
        img = cv2.imread(filepath,0)
        img = cv2.resize(img, (128, 64))
        #cv2.imshow('Greyscale',img)
        cv2.imwrite('Greyscale.jpg',img)
        #print img.shape
        for i in xrange(0,64):
            for j in xrange(0,128):
                px = img[i,j]
                lcd= img
                if px>127:
                    img[i,j]= 255
                    lcd[i,j]=1
                else:
                    img[i,j]=0
                    lcd[i,j]=0
                px = img[i,j]
                #print px
                c=0
                d=0
        #cv2.imshow('image',img)
        k=0
        total=0
        while (c<64):
            for i in xrange(0,128):
                binary_temp=0
                #print "binary temp ", binary_temp
                for j in xrange(c,c+8):
                    #print(j,i)
                    #total=total+1
                    binary_temp = binary_temp + (lcd[j, i] << (j-c))
                    #if bin(lcd[j,i])>bin(0):
                        #print binary_temp
                #print "hex", hex(binary_temp)
                k+1
                if k<10:
                    total = total+1
                    if total == 1024:
                        fo.write( "%s " % (hex(binary_temp)))
                    else:
                        fo.write( "%s, " % (hex(binary_temp)))
                    k=k+1

                else:
                    total=total+1
                    fo.write("\n")
                    fo.write( "%s, " % (hex(binary_temp)))
                    k=1

            c=c+8
            #print c
        fo.write("};")
        fo.close()
        print total
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    return
