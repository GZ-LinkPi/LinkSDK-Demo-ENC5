# LinkSDK Demo for ENC5

#### 项目介绍  
ENC5全功能开发板的演示程序集。ENC5主芯片是海思Hi3531D芯片，外围接口有5xHDMI，HDMI最高分辨率支持4K (3840x2160)。  
这些Demo是基于 LinkSDK 开发的，工程需要QT支持，在QT环境下编译。  
LinkSDK的运行库参见：https://github.com/GZ-LinkPi/LinkLib 。  
镜像工程：https://gitee.com/LinkPi/3531D <ENC5分支>  

#### Decode
解码网络流并显示，可以修改代码中的流地址。

#### Encode
将HDMI-1接口的图像编码并输出流rtmp://xx.xx.xx.xx/live/test

#### Gpio
Gpio测试程序，执行后按下靠近调试串口的“stop”按键，程序会打印出相应的事件。

#### InputTest  
全部输入源测试，将输出一个9宫格画面，依次为  
HDMI-1、HDMI-2、HDMI-3  
HDMI-4、USBCam  
其中USBCam需要外接UVC标准摄像头。 

#### Record
录制测试程序，程序执行后会录制一个8秒钟左右的视频，保存在/tmp/test.mp4

#### UI
支持触屏操作的UI测试程序，UI使用Html实现，运行后会出现两个交错的图像，点击“Touch Me”按钮会交换两个图像的位置。

#### 如何获得ENC5
https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-18827270222.2.3f0d6ffdfmipwc&id=579544624529

---

#### Project Introduction  
These are demos for the ENC5 full-featured development board.  
The main chip of ENC5 is the Hisilicon Hi3531D. The peripheral interfaces have 5xHDMI. The highest HDMI resolution is 4K (3840x2160).
These demos are based on LinkSDK, which requires QT support and is compiled in QT environment.  
LinkSDK runtime library: https://github.com/GZ-LinkPi/LinkLib .  
Mirror project: https://gitee.com/LinkPi/3531D_Demo <ENC5 branch>     

#### Decode
The network stream is decoded and displayed, and the network stream url in the code can be modified.

#### Encode
Encode the image of the HDMI-1 interface and output to network stream rtmp://xx.xx.xx.xx/live/test

#### Gpio
Gpio test program, after execution, press the "stop" button near the debug serial port, the program will print the corresponding event.

#### InputTest  
All input source tests will output a 9-grid screen, in order  
HDMI-1、HDMI-2、HDMI-3  
HDMI-4、USBCam  
USBCam requires an external UVC standard camera.  
 
#### Record
Record the test program. After the program is executed, a video of about 8 seconds will be recorded and saved in /tmp/test.mp4.

#### UI
The UI test program supports touch screen operation. The UI is implemented by Html. After running, two interlaced images will appear. Clicking the “Touch Me” button will swap the positions of the two images.

#### How to get ENC5
https://item.taobao.com/item.htm?spm=a1z10.1-c-s.w4004-18827270222.2.3f0d6ffdfmipwc&id=579544624529
