clc;clear;close all;  

%%%%%  For SSD1306 I2C Module %%%%%%%

img = imread('2.jpg');  % input image
img = imresize(img,[64 128]);
img(img<128)=0;
img(img>=128)=1;
figure, imshow(double(img))
cnt=0;
s1 = fopen('bitmap_image.h','w');  % bitmap output file

fprintf(s1,['// Header created by\n']);
fprintf(s1,['// Elementz Engineers Guild Pvt Ltd\n']);
fprintf(s1,['// Size 128x64\n']);
fprintf(s1,['const uint8_t bitmap [] PROGMEM = { \n']);

for i=1:8:64
    cnt = cnt+1;
    for j=1:128
        s = (img(i:i+7,j))';
        
        d = dec2hex(bin2dec(num2str(fliplr(s))));
        
        if i==57 && j==128
            fprintf(s1,['0x' d]);
        else
            fprintf(s1,['0x' d ',']);
        end
        if mod(j,16)==0
            fprintf(s1,['\n']);
        end
    end
end

fprintf(s1,['};\n']);
fclose(s1)        
        
        