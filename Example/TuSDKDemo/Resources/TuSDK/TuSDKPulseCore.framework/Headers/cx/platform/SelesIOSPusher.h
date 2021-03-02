#ifndef SELESIOSPUSHER_H
#define SELESIOSPUSHER_H
/********************************************************
    * @file        : SelesIOSPusher.h
    * @project    : eva_worker
    * @author    : Clear
    * @date        : 2020-4-27 14:27:03
    * @brief    : IOS绘制图像到窗口
    * @details    :
*********************************************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "seles/Seles.hh"

namespace tutu
{
    class SelesSemaphore;
    class SelesFramebuffer;
    class SelesVertexbuffer;
    class SelesProgram;
    
    // IOS绘制图像窗口
    class SelesIOSPusher :
        public SelesSurfaceDisplay,
        public Seles,
        public std::enable_shared_from_this<SelesIOSPusher>
    {
    public:
        static std::shared_ptr<SelesIOSPusher> make(CAEAGLLayer* glLayer, std::shared_ptr<SelesContext> context = nullptr);
        SelesIOSPusher(CAEAGLLayer* glLayer);
        ~SelesIOSPusher();
    private:
        // 初始化滤镜
        void initSurface(const std::string& vertex_str, const std::string& fragment_str);
    private:
        CAEAGLLayer*                        _glLayer = nil;                         // IOS GLView
        uint32_t                            _displayFramebuffer{ 0 };               /** FBO */
        uint32_t                            _displayRenderbuffer{ 0 };              /** RBO */
        std::shared_ptr<SelesProgram>       _displayProgram;                        // GL程序
        float                               _bg_rgba[4]{ 0.0f, 0.0f, 0.0f, 1.0f };  // 背景色 RGBA
        uint32_t                            _backgroundColor{ 0xff000000 };         // 背景色 ARGB
        int                                 _displayInputTextureUniform{ -1 };      // 显示材质索引
        std::shared_ptr<SelesVerticeBuilder>_verticeBuilder;                        /** 顶点坐标计算接口 */
        SelesRotation                       _inputRotation{ SelesRotation::Up };    // 输入方向
        std::shared_ptr<SelesVertexbuffer>  _vertexbuffer;                          // 顶点缓存
        SelesSize                           _outputSize;                            // 输出长宽
        SelesSize                           _inputTextureSize;                      // 输入长宽
        int                                 inputFramebufferTexture();              // 输入材质ID
        bool                                _disable{ false };                      // 忽略执行自己
        std::shared_ptr<SelesFramebuffer>   _inputFramebuffer;                      // view GL
        SelesWatermarkPtr                   _watermark;                             // 需要绘制的水印对象 这里必须为forDisplay
    private:
        void releaseInputFrameBuffer();                         // 释放输入FBO
        void createDisplayFramebuffer();                        // 创建显示FBO
        void destroyDisplayFramebuffer();                       // 销毁显示FBO
        void setDisplayFramebuffer();                           // 设置显示FBO
        void presentFramebuffer();                              // 执行显示FBO
    public:
        void renderToTexture(uint64_t frameTimeNN);             // 渲染数据 [纳秒]
        void setDisable(bool should);                           // 忽略执行自己
    public:
        // SelesInput
        virtual void newFrameReady(uint64_t frameTimeNN, uint32_t textureIndex) override;        // new FrameReady System.nanoTime()
        virtual void setInputFramebuffer(std::shared_ptr<SelesFramebuffer> newFbo, uint32_t textureIndex) override;// set InputFrame buffer
        virtual void setInputSize(const SelesSize& newSize, uint32_t textureIndex) override;     // set Input Size
        virtual void setInputRotation(SelesRotation orien, uint32_t textureIndex) override;      // set Input Rotation
        virtual SelesSize maximumOutputSize() override;                                          // maximum Output Size
        virtual void endProcessing() override;                                                   // end Processing
        virtual bool disable() override;                                                         // should Ignore Updates To This Target
    public:
        // SelesSurfaceDisplay
        /** 设置材质坐标计算接口 */
        virtual void setVerticeBuilder(std::shared_ptr<SelesVerticeBuilder> verticeBuilder) override;
        // 设置背景颜色 ARGB
        virtual void setBackgroundColor(uint32_t color) override;
        /** 需要绘制的水印对象 这里必须为forDisplay */
        virtual void setWatermark(SelesWatermarkPtr watermark) override;
        /** 销毁 */
        virtual void destroy() override;
        /** set Pusher Rotation */
        virtual void setPusherRotation(SelesRotation orient, uint32_t textureIndex) override;
        void rebuildDisplayFramebuffer();   // 重新创建显示FBO
    };

    // IOS绘制图像窗口
    typedef std::shared_ptr<SelesIOSPusher> SelesIOSPusherPtr;
}

#endif /* SELESIOSPUSHER_H */
