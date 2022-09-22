
#ifndef PULSEVIDEO_RENDERER_EFFECT_TRANSFORM_HH_
#define PULSEVIDEO_RENDERER_EFFECT_TRANSFORM_HH_

#include "renderer/effect.hh"

#include <string_view>
#include <string>
#include <mutex>
//#include <glm/vec2.hpp>

namespace pulsevideo {
namespace renderer {

class PULSE_API TransformEffect_ModeTransfer {

public:
    TransformEffect_ModeTransfer(const std::string& cur = "");

    std::string ApplyMirror();
    std::string ApplyFlip();

    std::string ApplyRotate(bool ccw = false);

    std::string CurrentMode() {
        return _cur_mode;
    }
private:
    std::string _cur_mode;
};

class PULSE_API TransformEffect : public Effect {


public:
    static constexpr auto type_name = "transform";

    static UPtr<TransformEffect> Make(RendererContext *ctx);

//public:
    TransformEffect(RendererContext *ctx);

    virtual ~TransformEffect() noexcept = default;

};
}
}

#endif
