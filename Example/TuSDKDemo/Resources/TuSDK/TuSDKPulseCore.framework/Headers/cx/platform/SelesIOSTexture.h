#ifndef SELESIOSTEXTURE_HPP
#define SELESIOSTEXTURE_HPP
/********************************************************
    * @file        : SelesIOSTexture.h
    * @project    : seles
    * @author    : Clear
    * @date        : 2020-4-22 12:40:46
    * @brief    :
    * @details    : IOS 材质对象
*********************************************************/
#include "seles/SelesCommon.hh"
#if defined(TUTU_OS_IOS) || defined(TUTU_OS_IOS_SIMULATOR)
#include "seles/Seles.hh"

#include <CoreVideo/CoreVideo.h>

namespace tutu
{
    class SelesTextureOptions;
    class SelesImage;
    
    // IOS 材质对象
    class SelesIOSTexture : public Seles
    {
    public:
        // IOS 材质对象
        static std::shared_ptr<SelesIOSTexture> make(std::shared_ptr<SelesTextureOptions> opt, const SelesSize& size);
        // 创建FBO绑定材质对象
        static std::shared_ptr<SelesIOSTexture> makeAttachment(std::shared_ptr<SelesTextureOptions> opt, const SelesSize& size);
        SelesIOSTexture(std::shared_ptr<SelesTextureOptions> opt, const SelesSize& size); // IOS 材质对象
        ~SelesIOSTexture();                                         // IOS 材质对象
    private:
        bool buildAttachment();                                     // 创建FBO绑定材质对象
    private:
        std::shared_ptr<SelesTextureOptions> _opt;
        CVPixelBufferRef     _renderTarget  = nullptr;
        CVOpenGLESTextureRef _renderTexture = nullptr;
        SelesSize _size;
        uint32_t _texture{ 0 };                                     // 材质ID
    public:
        uint32_t texture();                                         // 材质ID
        virtual void destroy() override;                            // 销毁
        std::shared_ptr<SelesImage> readPixels();                   // 读取像素
    public:
        void releaseTexture();                                      // 释放材质
        void freshTexture(CVImageBufferRef frame, uint32_t index);  // 刷新材质
    };
    
    // IOS 材质对象
    typedef std::shared_ptr<SelesIOSTexture> SelesIOSTexturePtr;
}
#endif // TUTU_OS_IOS
#endif /* SELESIOSTEXTURE_HPP */
