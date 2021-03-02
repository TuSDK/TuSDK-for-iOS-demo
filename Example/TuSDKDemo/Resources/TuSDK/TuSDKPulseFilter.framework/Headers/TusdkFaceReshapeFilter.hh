#ifndef PULSEVIDEO_FILTER_TUSDK_FACE_RESHAPE_HH_
#define PULSEVIDEO_FILTER_TUSDK_FACE_RESHAPE_HH_

#include "filter/Filter.hh"

namespace pulsevideo {
namespace filter {

class TusdkFaceReshapeFilter : public Filter
{
public:
    static constexpr auto type_name = "TusdkFaceReshape";

    TusdkFaceReshapeFilter(FilterContext& ctx);
    virtual ~TusdkFaceReshapeFilter() noexcept;

private:
    virtual BoolResult do_activate(const Config& config) override;
    virtual VoidResult do_deactivate() override;
    virtual Result<ImagePtr> do_process(ImagePtr image) override;

    virtual bool isSkip() override;

    void initResource();

private:
    struct Impl;
    UPtr<Impl> _impl;
};


}
}
#endif
