# AndroidCV Tutorial 1
# Display Chessboard using Android Studio and OpenCV 3.2 Native JNI

## Demo App:

<img src="https://raw.githubusercontent.com/xmuweili88/AndroidCV_Tutorial_1/master/ScreenCapture/device-2017-05-13-103903.png" width=480>

## Step 1: Install Andorid Studio

Follow [this page](https://developer.android.com/studio/install.html) to setup the Android Studio on you developing machine.

## Step 2: Clone the code base and Install OpenCV

```bash
git clone https://github.com/xmuweili88/AndroidCV_Tutorial_1.git
cd AndroidCV_Tutorial_1
sh Install_OpenCV.sh
```

## Step 3: Build and Run!

Connect your android device to you develop machine.  
Make sure your device is [USB debugging enabled](https://www.howtogeek.com/129728/how-to-access-the-developer-options-menu-and-enable-usb-debugging-on-android-4.2/).  
On Android menu:
- Build -> Make Project
- Run -> Rnu 'app'
- Select the connected android device
- Check out result :)

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
