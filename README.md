# AndroidCV Tutorial 1: Display Chessboard using Android Studio and OpenCV 3.2 Native JNI

## Demo App:
![alt text](https://raw.githubusercontent.com/xmuweili88/AndroidCV_Tutorial_1/master/ScreenCapture/device-2017-05-13-103903.png)
## Step 1: Install Android Studio

## Step 2: Install OpenCV
## Step 3: Build and Run!
## Issues you may have:
```
item ninja: error: '../app/src/main/jniLibs/arm64-v8a/libopencv_java3.so', 
needed by '../../../../build/intermediates/cmake/debug/obj/arm64-v8a/libnative-lib.so', 
missing and no known rule to make it
```

Make sure you run ```sh Install_OpenCV.sh``` before build the project.


```
The app does not show chessboard in the emulator.
```
The openCV library is built for cell phone to use. 
An really android device is needed to run this demo.