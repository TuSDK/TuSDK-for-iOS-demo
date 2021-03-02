#ifndef TAudioIOS_hpp
#define TAudioIOS_hpp

/********************************************************
    * @file        : SelesIOSTexture.h
    * @project    : seles
    * @author    : Clear
    * @date        : 2020-5-12 12:40:46
    * @brief    :
    * @details    : IOS 媒体缓存
*********************************************************/

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#include "algom/audio/AudioBuffer.hh"

namespace tutu
{
    // IOS媒体缓存
    class AudioBufferIOS : public AudioBuffer
    {
    public:
        // IOS媒体缓存, 初始化byte大小
        static std::shared_ptr<AudioBufferIOS> make(uint32_t capacity);
        // IOS媒体缓存, 传入外部Buffer
        static std::shared_ptr<AudioBufferIOS> make(CMSampleBufferRef buffer);
        ~AudioBufferIOS();
    private:
        void initBuffer(uint32_t capacity);            // IOS媒体缓存, 初始化byte大小
        void initBuffer(CMSampleBufferRef buffer);     // IOS媒体缓存, 传入外部Buffer
        bool _created{ false };
        CMBlockBufferRef _blockBuffer = nullptr;
    public:
        virtual bool flagEndOfStream() override;                    // 是否读取到数据结尾
    };

    // IOS媒体缓存
    typedef std::shared_ptr<AudioBufferIOS> AudioBufferIOSPtr;
    
    ////////////////////////////////////////////////////////////////////
    
    // IOS媒体监听对象
    class AudioIOSListener : public AudioProcessListener
    {
    public:
        typedef void(^lsqAudioBridgeBlock)(AudioBufferPtr buffer);
        static std::shared_ptr<AudioIOSListener> make(lsqAudioBridgeBlock listener);
        AudioIOSListener(lsqAudioBridgeBlock listener);
        ~AudioIOSListener();
    private:
        /** IOS监听对象 */
        lsqAudioBridgeBlock _listener = nullptr;
    public:
        virtual void onMediaOutputBuffer(AudioBufferPtr buffer) override;    // 媒体输出
        virtual AudioBufferPtr createBuffer(uint32_t capacity) override;     // 创建缓存
    };

    // IOS媒体监听对象
    typedef std::shared_ptr<AudioIOSListener> AudioIOSListenerPtr;
}

#endif /* TAudioIOS_hpp */
