#include <jni.h>
#include <string>
#include <android/bitmap.h>
#include <android/log.h>
#include "opencv2/opencv.hpp"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "native-lib", __VA_ARGS__)

namespace {
    // Draw the chess board on inupt cv::Mat image
    void DrawCheessBoard(cv::Mat* image) {
        const int width = image->cols;
        const int height = image->rows;
        const int block_size = 64;
        uint8_t color = 0;
        for(int i=0; i<width; i+=block_size){
            uint8_t row_color = color;
            color = ~color;
            for (int j=0; j<height; j+=block_size) {
                cv::rectangle(*image, cv::Rect(i, j, block_size, block_size),
                              cv::Scalar(row_color, row_color, row_color, row_color), CV_FILLED);
                row_color = ~row_color;
            }
        }
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_androidcv_tutorial_11_MainActivity_DrawChessBoardJNI(
        JNIEnv *env,
        jobject /* this */, jobject bitmap) {
    uint8_t *bitmapPixels;
    AndroidBitmapInfo overlayInfo;
    if(AndroidBitmap_getInfo(env, bitmap, &overlayInfo) < 0) {
        LOGD("[ndk demo]AndroidBitmap_getInfo() failed");
        return;
    }
    if (AndroidBitmap_lockPixels(env, bitmap, (void**)&bitmapPixels) < 0) {
        LOGD("[ndk demo]AndroidBitmap_lockPixels() failed");
        return;
    }
    cv::Mat bitmap_mat(overlayInfo.height, overlayInfo.width, CV_8UC4, bitmapPixels,
                       overlayInfo.stride);
    bitmap_mat.setTo(255);
    DrawCheessBoard(&bitmap_mat);
    AndroidBitmap_unlockPixels(env, bitmap);
}
