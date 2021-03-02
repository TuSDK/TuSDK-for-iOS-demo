#ifndef SELESIMAGEIOS_H
#define SELESIMAGEIOS_H
/********************************************************
    * @file        : SelesImageIOS.h
    * @project    : seles
    * @author    : Clear
    * @date        : 2020-4-22 12:40:46
    * @brief    :
    * @details    : IOS 图片对象
*********************************************************/
#include "seles/SelesCommon.hh"

#if defined(TUTU_OS_IOS) || defined(TUTU_OS_IOS_SIMULATOR)
#include <CoreGraphics/CoreGraphics.h>
#include <CoreVideo/CoreVideo.h>
#include <CoreMedia/CoreMedia.h>

#include "seles/platform/SelesImage.hh"

namespace tutu
{
    // IOS 图片对象
    class SelesImageIOS : public SelesImage
    {
    public:
        // 初始化图片
        static std::shared_ptr<SelesImageIOS> make(uint32_t width, uint32_t height, uint32_t channels);
        // 使用本地图片 [asset 供安卓使用，其他系统忽略]
        static std::shared_ptr<SelesImageIOS> makeLocal(const std::string& path, bool needAlpha = false, bool asset = false);
        // 使用二进制图片 [binary 未解码图片数据]
        static std::shared_ptr<SelesImageIOS> makeBinary(const char * binary, size_t length, bool needAlpha = false);
        // 使用解码后的图片 [是否只引用]
        static std::shared_ptr<SelesImageIOS> makeCopy(uint8_t * image, uint32_t channels, uint32_t width, uint32_t height, bool ref = false);
        // 创建IOS图片
        static std::shared_ptr<SelesImageIOS> make(CGImageRef img, bool smoothlyScale = false, bool removePremultiplied = false);
        // Yuv图像
        static std::shared_ptr<SelesImageIOS> make420(uint8_t * image, uint32_t width, uint32_t height, FormatMode type, FormatRange ranger, bool ref = false);
        // IOS图像缓存
        static std::shared_ptr<SelesImageIOS> makeCMBuffer(CMSampleBufferRef buffer);
        // IOS OpenGL图像缓存
        static std::shared_ptr<SelesImageIOS> makePixelBuffer(CVPixelBufferRef buffer);
        ~SelesImageIOS();                                                                       // IOS 图片对象
    private:
        CMSampleBufferRef _cmBuffer = nullptr;
        CVImageBufferRef _frame = nullptr;                                                      // IOS图像缓存
    private:
        void initImage(uint32_t width, uint32_t height, uint32_t channels);                     // 初始化图片
        bool loadImage(const std::string& path, bool needAlpha = false, bool asset = false);    // 加载图片
        bool decodeImage(const char * binary, size_t length, bool needAlpha = false);           // 初始化二进制图片 [binary 未解码图片数据]
        bool readImage(CGImageRef img, bool smoothlyScale = false, bool removePremultiplied = false);   // 读取IOS图片
        bool initCMBuffer();                                                                    // 初始化IOS图像缓存
        bool initCVBGRA();                                                                      // 初始化IOS图像BGRA缓存
        bool initCVYuv(FormatMode type, bool fullRange);                                        // 初始化IOS图像缓存
        bool initPixelBuffer(CVPixelBufferRef buffer);                                          // IOS OpenGL图像缓存
    public:
        void releaseCmBuffer();                                                                 // 释放IOS图像缓存
        CMSampleBufferRef cmBuffer();                                                           // IOS图像缓存
        CVImageBufferRef cvBuffer();                                                            // IOS图像缓存
        uint64_t timeStampNs();                                                                 // 获取时间戳[纳秒]
        void setCmBuffer(CMSampleBufferRef buffer);                                             // 设置IOS图像缓存
        virtual uint8_t*    data() override;                                                    // 二进制数据指针
        virtual uint8_t*    dataPlane(uint32_t index) override;                                 // 获取平面索引图像数据指针
    };
    
    // IOS 图片对象
    typedef std::shared_ptr<SelesImageIOS> SelesImageIOSPtr;
}
#endif // !TUTU_OS_IOS
#endif /* SELESIMAGEIOS_H */
