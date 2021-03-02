#ifndef SelesIOSOutputPusher_h
#define SelesIOSOutputPusher_h

/******************************************************************
* droid-sdk-jni
* ${PACKAGE_NAME}.SelesOutputPusher
*
* @author         : Clear
* @Date         : 2020/6/3 5:59 PM
* @Copyright     : (c) 2020 tutucloud.com. All rights reserved.
* @brief       : 输出显示 / 或供编码器使用
* @details     :
******************************************************************/

#include "seles/output/SelesOutputImage.hh"

namespace tutu
{
    class SelesIOSPusher;

    // 输出显示 / 或供编码器使用
    class SelesIOSOutputPusher : public SelesOutputImage
    {
    public:
        static std::shared_ptr<SelesIOSOutputPusher> make(void* glLayer, bool async, std::shared_ptr<SelesContext> context = nullptr); // 图像输出接口
        SelesIOSOutputPusher(bool async);                                       // 图像输出接口
        ~SelesIOSOutputPusher();                                                // 图像输出接口
        virtual void destroy() override ;                                       // destroy
    private:
        void* _glLayer = nullptr;                                               // IOS GLView
        std::shared_ptr<SelesIOSPusher> _pusher;                                // 输出显示 / 或供编码器使用
    private:
        void initPusher(void* glLayer);                                         // 初始化图像输出源
        void buildPusher();                                                     // 创建并链接显示窗口
    public:
        virtual void rebuildDisplay() override;                                          // 重建显示区域 [IOS专用RBO]
        virtual void setOutputRotation(SelesRotation orien) override;                    // set Output Rotation
        virtual void setVerticeBuilder(std::shared_ptr<SelesVerticeBuilder> builder) override; // 顶点坐标计算接口
        virtual void setBackgroundColor(uint32_t color) override;                        // 背景区域颜色 (默认：ARGB = 0xFF000000)
        virtual void setWaterImage(std::shared_ptr<SelesImage> image) override;          // 水印图像
        virtual void processFrame() override;                                            // 处理帧数据 [供异步使用，该方法在其他Context线程执行]
    };

    // 输出显示 / 或供编码器使用
    typedef std::shared_ptr<SelesIOSOutputPusher> SelesIOSOutputPusherPtr;
}

#endif /* SelesIOSOutputPusher_h */
