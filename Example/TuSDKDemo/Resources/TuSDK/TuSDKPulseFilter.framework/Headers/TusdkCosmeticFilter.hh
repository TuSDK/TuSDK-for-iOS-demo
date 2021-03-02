#ifndef PULSEVIDEO_FILTER_TUSDK_TUSDK_COSMETIC_HH
#define PULSEVIDEO_FILTER_TUSDK_TUSDK_COSMETIC_HH

#include "filter/Filter.hh"

namespace pulsevideo {
    namespace filter {

        class TusdkCosmeticFilter : public Filter {
        public:
            static constexpr auto type_name = "TusdkCosmetic";

            TusdkCosmeticFilter(FilterContext &ctx);

            virtual ~TusdkCosmeticFilter() noexcept;

        private:
            virtual BoolResult do_activate(const Config &config) override;

            virtual VoidResult do_deactivate() override;

            virtual Result<ImagePtr> do_process(ImagePtr image) override;

            virtual bool isSkip() override;

        private:
            void initResource();

        private:
            struct Impl;
            UPtr<Impl> _impl;
        };

    }
}
#endif