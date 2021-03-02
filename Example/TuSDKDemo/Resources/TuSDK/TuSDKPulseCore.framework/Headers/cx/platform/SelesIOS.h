#ifndef SELESIOS_HH
#define SELESIOS_HH

/********************************************************
    * @file        : SelesMac.hh
    * @project    : seles
    * @author    : Clear
    * @date        : 2020-4-22 12:40:46
    * @brief    :
    * @details    : IOS 环境
*********************************************************/
#include "seles/SelesCommon.hh"
#if defined(TUTU_OS_IOS) || defined(TUTU_OS_IOS_SIMULATOR)
#include "seles/platform/SelesPlatform.hh"
#include <CoreVideo/CoreVideo.h>

namespace tutu
{
    // IOS 环境
    class SelesIOS : public SelesPlatform
    {
    public:
        static std::shared_ptr<SelesIOS> make(void * sharedContext);    // IOS 环境 (__bridge EAGLContext*) | (__bridge void*)
        virtual CVOpenGLESTextureCacheRef textureCache() = 0;           // 材质缓存
        virtual void textureCacheFlush() = 0;                           // 清理材质缓存
    public:
        static void* currentThreadContext();                            // 当前线程的 GL Context
        static bool supportTextureCache();                              // 是否支持材质缓存
    };
    
    // Mac 环境
    typedef std::shared_ptr<SelesIOS> SelesIOSPtr;
}
#endif // TUTU_OS_IOS
#endif /* SELESIOS_HH */
