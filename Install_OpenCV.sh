#!/bin/sh

# Download OpenCV
cd Libs && \
curl https://svwh.dl.sourceforge.net/project/opencvlibrary/opencv-android/3.2.0/opencv-3.2.0-android-sdk.zip | tar -xf- -C . && \

# Copy OpenCV Jni Library to the android project
cd .. && \
mkdir app/src/main/jniLibs && \
cp -R Libs/OpenCV-android-sdk/sdk/native/libs/. app/src/main/jniLibs/.