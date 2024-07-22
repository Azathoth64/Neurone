#ifndef AD5C99D6_93F4_4A19_923F_EDBB290399FF
#define AD5C99D6_93F4_4A19_923F_EDBB290399FF

#include <string>

namespace Neurone
{
    typedef std::string Identifier;

    class IDGenerator {
    public:
        static Identifier generate();
        static bool validate(const Identifier& identifier);
    };

}


#endif /* AD5C99D6_93F4_4A19_923F_EDBB290399FF */
