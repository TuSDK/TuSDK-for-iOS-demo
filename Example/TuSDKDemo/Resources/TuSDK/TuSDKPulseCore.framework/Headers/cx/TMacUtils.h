#ifndef TMACUTILS_HH
#define TMACUTILS_HH
/********************************************************
 * @file    : TMacUtils.h
 * @project : seles
 * @author  : Clear
 * @date    : 2020-4-13 22:05:14
 * @brief   : Mac os帮助类
 * @details :
*********************************************************/

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#include "seles/Seles.hh"

@class SelesParameters;

namespace tutu
{
    class TFileBinary;
//    class SelesParams;
    class SelesImage;
    enum class FilterModel : uint32_t;
    
    // Mac os帮助类
    class TMacUtils
    {
    private:
        static void dataProviderReleaseCallback(void *info, const void *data, size_t size); // 数据释放接口
        static void pixelBufferReleaseCallback(void *info, const void *data);               // 数据释放接口
        static std::map<SelesImage *, std::shared_ptr<SelesImage>> dataProviderRefs;        // 引用图片缓存
    public:
        static std::string toCString(NSString * str);           // 转换为C字符串
        static NSString * toNSString(const std::string& str);   // 转换为C字符串 RGBA

    public:
        static uint32_t toCColor(UIColor *color);               // 转换为C颜色
    public:
        static UIImage * decodeImage(std::shared_ptr<TFileBinary> binary);  // 解码图片
        static UIImage * createImage(std::shared_ptr<SelesImage> cImage);   // 创建图片
//        static CMSampleBufferRef fitCmBuffer(CMSampleBufferRef cmBuffer);   // 缩放到可支持大小 [需要手动释放 CFRelease]
        static CMSampleBufferRef resizedPixBuffer(CVPixelBufferRef frame, const SelesSize& size);  // 缩放 [需要手动释放 CFRelease]
    };
}
#endif // !TMACUTILS_HH
